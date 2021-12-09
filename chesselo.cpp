#include "chesselo.h"
#include "ChessAdjGraph.h"
#include "chessmatrixgraph.h"
ChessELO::ChessELO(QString _filename, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChessELO)
{
    ui->setupUi(this);
    filename = _filename;
    ui->table->hide();

    //connect(ui->pushButton_Enter, SIGNAL(clicked()), this, SLOT(on_pushButton_Enter_clicked()));
    //connect(ui->pushButton_User, SIGNAL(clicked()), this, SLOT(on_pushButton_User_clicked()));
    //connect(ui->pushButton_File, SIGNAL(clicked()), this, SLOT(on_pushButton_File_clicked()));
}


void ChessELO::on_pushButton_File_clicked()
{
    filename = ui->lineEdit_File->text();
    //construct graphs here, also calculate build time

    auto start = chrono::high_resolution_clock::now();
    adjGraph = ChessAdjGraph(filename);
    auto end = chrono::high_resolution_clock::now();
    auto adjDuration = chrono::duration_cast<chrono::milliseconds>(end - start);


    start = chrono::high_resolution_clock::now();
    matrixGraph = ChessMatrixGraph(filename);
    end = chrono::high_resolution_clock::now();
    auto matrixDuration = chrono::duration_cast<chrono::milliseconds>(end - start);

    int ListBuildTime = adjDuration.count();
    int MatrixBuildTime = matrixDuration.count();
    ui->BuildListLabel->setText(QString::fromStdString("Adjacency List Build Time: " + to_string(ListBuildTime) + " ms"));
    ui->BuildMatrixLabel->setText(QString::fromStdString("Adjacency Matrix Build Time: " + to_string(MatrixBuildTime) + " ms"));

    initialized = true;

    return;
}


void ChessELO::on_pushButton_User_clicked()
{
    if(!initialized)
        return;

    auto start = chrono::high_resolution_clock::now();

    userName = ui->lineEdit_User->text();
    
    /*if (playerName not found)
    {
        ui->nameLabel->setText("No data available");
        ui->ELOLabel->setText("No data available");
        ui->separationLabel->setText("No data available");
    }
    */

    ChessAdjGraph a(filename);
    
    vector<pair<string, int>> top = a.findTopN(userName.toStdString(), 5);
    
    vector<string> dests = vector<string>();
    for (pair<string, int>& b : top)
    {
        dests.push_back(b.first);
    }
    vector<vector<string>> paths = a.findPath(userName.toStdString(), dests);
    
    vector<string> displayPaths = vector<string>(5, "");
    for(unsigned int i = 0; i < displayPaths.size(); i++)
    {
        if (paths.empty())
            displayPaths[i] = "No path found";
        else
        {
            for (unsigned int j = 0; j < paths[i].size() - 1; j++)
            {
                displayPaths[i] += paths[i][j];
                displayPaths[i] += " -> ";
            }
            displayPaths[i] += paths[i][paths[i].size() - 1];
        }
    }

    QFont font;
    font.setPointSize(12);

    for (int i = 0; i < 5; i ++)
    {
        ui->table->setItem(i,0,new QTableWidgetItem(QString::fromStdString(top[i].first)));
        ui->table->setItem(i,1,new QTableWidgetItem(QString::fromStdString(to_string(top[i].second))));
        ui->table->setItem(i,2,new QTableWidgetItem(QString::fromStdString(displayPaths[i])));
        ui->table->setItem(i,3,new QTableWidgetItem(QString::fromStdString(to_string(paths[i].size()))));
    }

    ui->table->setFont(font);

    ui->table->resizeColumnToContents(0);
    ui->table->resizeColumnToContents(1);
    ui->table->resizeColumnToContents(2);
    ui->table->resizeColumnToContents(3);

    ui->table->show();

    int UserListTime = 20;
    int UserMatrixTime = 13;

    ui->UserListLabel->setText(QString::fromStdString("Adjacency List Search Time: " + to_string(UserListTime) + " milliseconds"));
    ui->UserMatrixLabel->setText(QString::fromStdString("Adjacency List Search Time: " + to_string(UserMatrixTime) + " milliseconds"));

    //ui->nameLabel->setText(QString::fromStdString(topName));
    
    //QString playerElo = QString::number(elo);
    //playerElo += " rating points";
    //ui->ELOLabel->setText(playerElo);
    
    //ui->separationLabel_2->setText(QString::fromStdString(path));

    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

    cout << "Request execution time: " << duration.count() << " ms" << endl;
}

void ChessELO::on_pushButton_Player_clicked()
{
   if(!initialized || userName == "")
       return;

    playerName = ui->lineEdit_Player->text();

    string path = "wefwef->wefw->ergerg";
    string pathLength = "3";
    string ELO = "1546";
    string pathOutput = "Path: " + path + "          Path Length: " + pathLength;
    ui->separationLabel->setText(QString::fromStdString(pathOutput));

    string nameELO = "Player Name: " + playerName.toStdString() + "          Player ELO: " + ELO;
    ui->label_2->setText(QString::fromStdString(nameELO));

    int PlayerListTime = 20;
    int PlayerMatrixTime = 13;

    ui->PlayerListLabel->setText(QString::fromStdString("Adjacency List Search Time: " + to_string(PlayerListTime) + " milliseconds"));
    ui->PlayerMatrixLabel->setText(QString::fromStdString("Adjacency List Search Time: " + to_string(PlayerMatrixTime) + " milliseconds"));
}

void ChessELO::on_pushButton_Exit_clicked()
{
    close();
}
