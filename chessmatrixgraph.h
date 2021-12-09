#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <unordered_set>
#include <QFile>
#include <QApplication>
using namespace std;

class ChessMatrixGraph
{
private:
    map<string, int> names;
    map<int, string> nums;
    vector<vector<int>> edges;

    class compareEdges
    {
    public:
        bool operator()(pair<string, int> lhs, pair<string, int> rhs)
        {
            return lhs.second > rhs.second;
        }
    };

public:
    ChessMatrixGraph(QString filename);
    ChessMatrixGraph(){};

    vector<pair<string, int>> findTopN(string name, int n);

    void findTopNHelper(string curr,
                        unsigned int n,
                        unordered_set<string>& visited,
                        vector<pair<string, int>>& topN);

    vector<vector<string>> findPath(string source, vector<string> targets);
};
