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
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ChessELO w("Jan2013.csv");
    w.show();
    return a.exec();
}
//change in the git repository
