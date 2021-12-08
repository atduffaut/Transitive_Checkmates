#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <QFile>
#include <QApplication>
#include "GraphAnalysis_QT.h"

using namespace std;

//Constructor for the ChessGraph, reads in the file and makes the graph
ChessGraph::ChessGraph(QString filename)
{
    internalGraph = unordered_map<string, vector<pair<string, int>>>();

//    ifstream inputFile(filename);
    QFile inputFile(filename);
    QString line_temp;
    string line;
    if(!inputFile.open(QIODevice::ReadOnly)) {
        cout << "error" << endl;
    }

    while (!inputFile.atEnd())
    {
        line_temp = inputFile.readLine();
        line = line_temp.toStdString();
        string from = line.substr(0, line.find(","));
        line = line.substr(from.length() + 1);

        string to = line.substr(0, line.find(","));
        line = line.substr(to.length() + 1);

        if (line[0] == '?')
            continue;
        int weight = stoi(line.substr(0, line.find(",")));
        pair<string, int> temp = pair<string, int>(to, weight);
        internalGraph[from].push_back(temp);
    }
    inputFile.close();
};

vector<pair<string, int>> ChessGraph::findTopN(string name, int n)
{
    vector<pair<string, int>> topN = vector<pair<string, int>>();
    unordered_set<string> visited = unordered_set<string>();

    findTopNHelper(name, n, visited, topN);

    sort(topN.begin(), topN.end(), compareEdges());

    return topN;
}

void ChessGraph::findTopNHelper(string curr,
                                int n,
                                unordered_set<string>& visited,
                                vector<pair<string, int>>& topN)
{
    if (visited.find(curr) != visited.end())
        return;

    visited.emplace(curr);

    for (pair<string, int> a : internalGraph[curr])
    {
        int found = -1;
        for (int i = 0; i < topN.size(); i++)
        {
            if (topN[i].first == a.first)
                found = i;
        }

        if (found == -1)
            topN.push_back(a);
        else
            topN[found].second = max(a.second, topN[found].second);

        if (topN.size() > n)
        {
            int min = 0;
            for (int i = 0; i < topN.size(); i++)
            {
                if (topN[i].second < topN[min].second)
                    min = i;
            }

            topN.erase(topN.begin() + min);
        }
    }

    for (pair<string, int> a : internalGraph[curr])
        findTopNHelper(a.first, n, visited, topN);
}

vector<vector<string>> ChessGraph::findPath(string source, vector<string> dests)
{
    unordered_map<string, vector<string>> predecessors = unordered_map<string, vector<string>>();
    predecessors[source] = vector<string>{source};

    unordered_set<string> visited = unordered_set<string>();
    visited.emplace(source);

    queue<string> q = queue<string>();

    q.push(source);

    while (!q.empty())
    {
        string curr = q.front();

        for (int i = 0; i < internalGraph[curr].size(); i++)
        {
            string target = internalGraph[curr][i].first;

            if (visited.find(target) == visited.end())
            {
                q.push(target);
                visited.insert(target);

                if(predecessors[target].empty() || predecessors[target].size() > predecessors[curr].size() + 1)
                {
                    predecessors[target] = predecessors[curr];
                    predecessors[target].push_back(target);
                }
            }
        }

        q.pop();
    }

    vector<vector<string>> ans = vector<vector<string>>();

    for(string a: dests)
        ans.push_back(predecessors[a]);

    return ans;
}
