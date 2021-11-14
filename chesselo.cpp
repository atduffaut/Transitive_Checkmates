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
    ChessGraph a(filename.toStdString());
    
    
    vector<pair<string, int>> top = a.findTopN(playerName.toStdString(), 1);
    vector<string> dests = vector<string>();
    for (pair<string, int> b : top)
    {
        dests.push_back(b.first);
    }
    vector<vector<string>> paths = a.findPath(playerName.toStdString(), dests);
    
    string topName;
    if(!top.empty())
        topName = top[0].first;
    else
        topName = "None";
    
    int elo;
    if(!top.empty())
        elo = top[0].second;
    else
        elo = 0;
    
    int sep;
    if(!paths.empty())
        sep = paths[0].size();
    else
        sep = 0;
    
    ui->nameLabel->setText(QString::fromStdString(topName));
    
    QString playerElo = QString::number(elo);
    playerElo += " rating points";
    ui->ELOLabel->setText(playerElo);
    
    QString separation = QString::number(sep);
    separation += " players in between";
    ui->separationLabel_2->setText(separation);
}

void ChessELO::on_pushButton_Exit_clicked()
{
    close();
}
