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
    ChessELO w(QString::fromStdString(""));
    w.show();
    return a.exec();
}
