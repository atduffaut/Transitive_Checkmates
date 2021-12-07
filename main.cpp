#include "chesselo.h"
#include <QApplication>
#include <QStringList>
#include <QLineEdit>
#include <QCompleter>
#include <QHBoxLayout>
#include <QWidget>
#include <QLabel>

#include <qfile.h>
#include <QTextStream>
#include <iostream>
#include <chrono>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    auto start = chrono::high_resolution_clock::now();

    ChessELO w("/Users/matthewtave/Transitive_Checkmates/Jan2013.csv");
    w.show();

    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

    cout << "Graph Generation and Window Opening: " << duration.count() << " ms" << endl;

    return a.exec();
}
//change in the git repository
