#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class ChessGraph
{
private:
    unordered_map<string, vector<pair<string, int>>> internalGraph;

    class compareEdges
    {
    public:
        bool operator()(pair<string, int> lhs, pair<string, int> rhs)
        {
            return lhs.second > rhs.second;
        }
    };

public:
    ChessGraph(string filename);

    vector<pair<string, int>> findTopN(string name, int n);

    void findTopNHelper(string curr,
                        int n,
                        unordered_set<string> &visited,
                        vector<pair<string, int>> &topN);

    vector<pair<string, int>> findPath(string source, string dest);
};

int main()
{
    ChessGraph a = ChessGraph("Jan2013.csv");

    vector<pair<string, int>> ans = a.findTopN("Romoda", 10);

    for (pair<string, int> a: ans)
        cout << a.first << "|" << a.second << endl;
    return 0;
}

//Constructor for the ChessGraph, reads in the file and makes the graph
ChessGraph::ChessGraph(string filename)
{
    internalGraph = unordered_map<string, vector<pair<string, int>>>();

    ifstream inputFile(filename);
    string line;
    while (getline(inputFile, line))
    {
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
                                unordered_set<string> &visited,
                                vector<pair<string, int>> &topN)
{
    if (visited.find(curr) != visited.end())
        return;

    visited.emplace(curr);

    for (pair<string, int> a: internalGraph[curr])
    {
        int found = -1;
        for(int i = 0; i < topN.size(); i++)
        {
            if(topN[i].first == a.first)
                found = i;
        }

        if(found == -1)
            topN.push_back(a);
        else
            topN[found].second = max(a.second, topN[found].second);

        if (topN.size() > n)
        {
            int min = 0;
            for (int i = 0; i < topN.size(); i++)
            {
                if(topN[i].second < topN[min].second)
                    min = i;
            }

            topN.erase(topN.begin() + min);
        }
    }

    for (pair<string, int> a: internalGraph[curr])
        findTopNHelper(a.first, n, visited, topN);
}

vector<pair<string, int>> ChessGraph::findPath(string source, string dest)
{

}