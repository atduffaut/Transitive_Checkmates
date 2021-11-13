#include "chesselo.h"
#include "GraphAnalysis.h"
ChessELO::ChessELO(QString _filename, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChessELO)
{
    ui->setupUi(this);
    filename = _filename;

    connect(ui->pushButton_Enter, SIGNAL(clicked()), this, SLOT(on_pushButton_Enter_clicked()));
    connect(ui->pushButton_Exit, SIGNAL(clicked()), this, SLOT(on_pushButton_Exit_clicked()));
}

void ChessELO::on_pushButton_Enter_clicked()
{
    QString playerName = ui->lineEdit_Name->text();
    /*if (playerName not found)
    {
        ui->nameLabel->setText("No data available");
        ui->ELOLabel->setText("No data available");
        ui->separationLabel->setText("No data available");
    }
    */
    ui->nameLabel->setText(playerName);
    ui->ELOLabel->setText(playerName);
    int i = 3;
    QString separation = QString::number(i);
    separation += " players in between";
    ui->separationLabel_2->setText(separation);
}

void ChessELO::on_pushButton_Exit_clicked()
{
    close();
}
