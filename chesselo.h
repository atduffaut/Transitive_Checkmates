#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_chesselo.h"
#include "ChessAdjGraph.h"
#include "chessmatrixgraph.h"

class ChessELO : public QMainWindow
{
    Q_OBJECT

public:
    ChessELO(QString _filename, QWidget *parent = Q_NULLPTR);

private:
    Ui::ChessELO *ui;
    QString filename;
    QString userName = "";
    QString playerName = "";

    bool initialized;

    ChessAdjGraph adjGraph;
    ChessMatrixGraph matrixGraph;

private slots:
    void on_pushButton_User_clicked();
    void on_pushButton_Exit_clicked();
    void on_pushButton_Player_clicked();
    void on_pushButton_File_clicked();
};
