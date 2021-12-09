#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <QFile>
#include <QApplication>
using namespace std;

class ChessAdjGraph
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
    ChessAdjGraph(QString filename);
    ChessAdjGraph(){};

    vector<pair<string, int>> findTopN(string name, int n);

    void findTopNHelper(string curr,
                        unsigned int n,
                        unordered_set<string>& visited,
                        vector<pair<string, int>>& topN);

    vector<vector<string>> findPath(string source, vector<string> targets);
};
