#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_chesselo.h"

class ChessELO : public QMainWindow
{
    Q_OBJECT

public:
    ChessELO(QWidget *parent = Q_NULLPTR);

private:
    Ui::ChessELO *ui;

private slots:
    void on_pushButton_Enter_clicked();
    void on_pushButton_Exit_clicked();
};