#include "chesselo.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ChessELO w;
    w.show();
    return a.exec();
}
//change in the git repository
