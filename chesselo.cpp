#include "chesselo.h"
#include "GraphAnalysis_QT.h"
ChessELO::ChessELO(QString _filename, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChessELO)
{
    ui->setupUi(this);
    filename = _filename;
    ui->table->hide();

    //connect(ui->pushButton_User, SIGNAL(clicked()), this, SLOT(on_pushButton_User_clicked()));
    //connect(ui->pushButton_File, SIGNAL(clicked()), this, SLOT(on_pushButton_File_clicked()));
}


void ChessELO::on_pushButton_File_clicked()
{
    filename = ui->lineEdit_File->text();
    //construct graphs here, also calculate build time
    int ListBuildTime = 20;
    int MatrixBuildTime = 13;
    ui->BuildListLabel->setText(QString::fromStdString("Adjacency List Build Time: " + to_string(ListBuildTime) + " milliseconds"));
    ui->BuildMatrixLabel->setText(QString::fromStdString("Adjacency List Build Time: " + to_string(MatrixBuildTime) + " milliseconds"));
}


void ChessELO::on_pushButton_User_clicked()
{
    auto start = chrono::high_resolution_clock::now();

    userName = ui->lineEdit_User->text();
    /*if (playerName not found)
    {
        ui->nameLabel->setText("No data available");
        ui->ELOLabel->setText("No data available");
        ui->separationLabel->setText("No data available");
    }
    */
    ChessGraph a(filename);
    
    
    vector<pair<string, int>> top = a.findTopN(userName.toStdString(), 1);
    vector<string> dests = vector<string>();
    for (pair<string, int>& b : top)
    {
        dests.push_back(b.first);
    }
    vector<vector<string>> paths = a.findPath(userName.toStdString(), dests);
    
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

    QFont font;
    font.setPointSize(12);

    for (int i = 0; i < 5; i ++)
    {
        ui->table->setItem(i,0,new QTableWidgetItem("efggggggggggggggf"));
        ui->table->setItem(i,1,new QTableWidgetItem("eff"));
        ui->table->setItem(i,2,new QTableWidgetItem("efeeeeeeggggggggggggggggggggggggggggggggggeeeeeeeeeeeeeeeeeeeef"));
        ui->table->setItem(i,3,new QTableWidgetItem("eff"));
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

    ui->nameLabel->setText(QString::fromStdString(topName));
    
    QString playerElo = QString::number(elo);
    playerElo += " rating points";
    ui->ELOLabel->setText(playerElo);
    
    //ui->separationLabel_2->setText(QString::fromStdString(path));

    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

    cout << "Request execution time: " << duration.count() << " ms" << endl;
}

void ChessELO::on_pushButton_Player_clicked()
{
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
