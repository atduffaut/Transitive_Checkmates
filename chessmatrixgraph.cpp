#include "chessmatrixgraph.h"
#include <set>
#include <cmath>
#include <unordered_map>
#include <queue>

ChessMatrixGraph::ChessMatrixGraph(QString filename)
{
    QFile inputFile(filename);
    QString line_temp;
    string line;

    if(!inputFile.open(QIODevice::ReadOnly)) {
        cout << "error" << endl;
    }

    set<string> namesSet = set<string>();



    while (!inputFile.atEnd())
    {
        line_temp = inputFile.readLine();
        line = line_temp.toStdString();

        string from = line.substr(0, line.find(","));
        line = line.substr(from.length() + 1);

        string to = line.substr(0, line.find(","));
        line = line.substr(to.length() + 1);

        namesSet.insert(from);
        namesSet.insert(to);
    }

    int i = 0;
    for(auto it = namesSet.begin(); it != namesSet.end(); ++it)
    {
        names[*it] = i;
        nums[i] = *it;
        i++;
    }
    edges = vector<vector<int>>(names.size(), vector<int>(names.size(), -1));
    inputFile.close();

    QFile inputFile2(filename);
    if(!inputFile2.open(QIODevice::ReadOnly)) {
        cout << "error" << endl;
    }

    while (!inputFile2.atEnd())
    {
        line_temp = inputFile2.readLine();
        line = line_temp.toStdString();
        string from = line.substr(0, line.find(","));
        line = line.substr(from.length() + 1);

        string to = line.substr(0, line.find(","));
        line = line.substr(to.length() + 1);

        if (line[0] == '?')
            continue;

        int weight = stoi(line.substr(0, line.find(",")));

        edges[names[from]][names[to]] = max(weight, edges[names[from]][names[to]]);
    }
    inputFile2.close();
}

vector<pair<string, int>> ChessMatrixGraph::findTopN(string name, int n)
{
    vector<pair<string, int>> topN = vector<pair<string, int>>();
    unordered_set<string> visited = unordered_set<string>();

    cout << "1" << endl;

    findTopNHelper(name, n, visited, topN);

    sort(topN.begin(), topN.end(), compareEdges());


    cout << "Done with TopN: " << topN[0].first << " " << topN[0].second << endl;
    return topN;
}

void ChessMatrixGraph::findTopNHelper(string curr,
                                unsigned int n,
                                unordered_set<string>& visited,
                                vector<pair<string, int>>& topN)
{
    visited.insert(curr);

    for (unsigned int i = 0; i < edges[names[curr]].size(); i++)
    {
        if(edges[names[curr]][i] == -1)
            continue;

        int found = -1;
        for (unsigned int j = 0; j < topN.size(); j++)
        {
            if (topN[j].first == nums[j])
                found = j;
        }

        if (found == -1)
            topN.push_back(pair<string, int>(nums[i], edges[names[curr]][i]));
        else
            topN[found].second = max(edges[i][names[curr]], topN[found].second);

        if (topN.size() > n)
        {
            int min = 0;
            for (unsigned int i = 0; i < topN.size(); i++)
            {
                if (topN[i].second < topN[min].second)
                    min = i;
            }

            topN.erase(topN.begin() + min);
        }
    }

    for (unsigned int i = 0; i < edges[names[curr]].size(); i++)
    {
        if(edges[names[curr]][i] == -1)
            continue;
        if(visited.find(nums[i]) != visited.end())
            continue;
        findTopNHelper(nums[i], n, visited, topN);
    }

}

vector<vector<string>> ChessMatrixGraph::findPath(string source, vector<string> dests)
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
        for (unsigned int i = 0; i < edges[names[curr]].size(); i++)
        {
            if (edges[names[curr]][i] == -1)
                continue;

            string target = nums[i];

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

    for(string& a: dests)
        ans.push_back(predecessors[a]);

    return ans;
}
