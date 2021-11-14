#include "chesselo.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ChessELO w("Jan2013.csv");
    w.show();
    return a.exec();
}
//change in the git repository
