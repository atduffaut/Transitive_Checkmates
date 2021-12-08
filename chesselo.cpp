#include "chesselo.h"
#include "ChessAdjGraph.h"
#include "chessmatrixgraph.h"
ChessELO::ChessELO(QString _filename, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChessELO)
{
    ui->setupUi(this);
    filename = _filename;

    //connect(ui->pushButton_Enter, SIGNAL(clicked()), this, SLOT(on_pushButton_Enter_clicked()));
}

void ChessELO::on_pushButton_Enter_clicked()
{
    auto start = chrono::high_resolution_clock::now();

    QString playerName = ui->lineEdit_Name->text();

    /*if (playerName not found)
    {
        ui->nameLabel->setText("No data available");
        ui->ELOLabel->setText("No data available");
        ui->separationLabel->setText("No data available");
    }
    */
    ChessAdjGraph a(filename);
    
    vector<pair<string, int>> top = a.findTopN(playerName.toStdString(), 1);

    vector<string> dests = vector<string>();
    for (pair<string, int>& b : top)
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
    
    string path = "";
    if (paths.empty())
        path = "No path found";
    else
    {
        for (unsigned int i = 0; i < paths[0].size() - 1; i++)
        {
            path += paths[0][i];
            path += " -> ";
        }
        path += paths[0][paths[0].size() - 1];
    }
    
    ui->nameLabel->setText(QString::fromStdString(topName));
    
    QString playerElo = QString::number(elo);
    playerElo += " rating points";
    ui->ELOLabel->setText(playerElo);
    
    ui->separationLabel_2->setText(QString::fromStdString(path));

    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

    cout << "Request execution time: " << duration.count() << " ms" << endl;
}

void ChessELO::on_pushButton_Exit_clicked()
{
    close();
}
