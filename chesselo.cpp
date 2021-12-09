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
    ui->table2->hide();

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
    
    vector<pair<string, int>> top = adjGraph.findTopN(userName.toStdString(), 5);
    
    vector<string> dests = vector<string>();
    for (pair<string, int>& b : top)
    {
        dests.push_back(b.first);
    }
    vector<vector<string>> paths = adjGraph.findPath(userName.toStdString(), dests);
    
    vector<string> displayPaths = vector<string>(5, "");
    for(unsigned int i = 0; i < paths.size(); i++)
    {
        if (paths[i].empty())
            displayPaths[i] = "No path found";
        else
        {
            for (unsigned int j = 0; j < paths[i].size() - 1; j++)
            {
                displayPaths[i] += paths[i][j];
                displayPaths[i] += " → ";
            }
            displayPaths[i] += paths[i][paths[i].size() - 1];
        }
    }
    for(unsigned int i = paths.size(); i < displayPaths.size(); i++)
        displayPaths[i] = "No path found";

    QFont font;
    font.setPointSize(12);

    for(int i = top.size(); i < 5; i++)
        top.push_back(pair<string, int>("No Player Found", 0));

    for(int i = paths.size(); i < 5; i++)
        paths.push_back(vector<string>());

    for (int i = 0; i < 5; i ++)
    {
        ui->table->setItem(i,0,new QTableWidgetItem(QString::fromStdString(top[i].first)));
        ui->table->setItem(i,1,new QTableWidgetItem(QString::fromStdString(to_string(top[i].second))));
        ui->table->setItem(i,2,new QTableWidgetItem(QString::fromStdString(displayPaths[i])));
        ui->table->setItem(i,3,new QTableWidgetItem(QString::fromStdString(to_string(paths[i].size()))));
    }

    ui->table->setFont(font);

    for(int i = 0; i < 4; i++)
        ui->table->resizeColumnToContents(i);
    ui->table->show();

    auto end = chrono::high_resolution_clock::now();

    int UserListTime = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    ui->UserListLabel->setText(QString::fromStdString("Adjacency List Search Time: " + to_string(UserListTime) + " ms"));

    start = chrono::high_resolution_clock::now();

    //matrixGraph.findTopN(userName.toStdString(), 5);
    //matrixGraph.findPath(userName.toStdString(), dests);

    end = chrono::high_resolution_clock::now();
    int UserMatrixTime = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    ui->UserMatrixLabel->setText(QString::fromStdString("Adjacency Matrix Search Time: " + to_string(UserMatrixTime) + " ms"));
}

void ChessELO::on_pushButton_Player_clicked()
{
   if(!initialized || userName == "")
       return;

   QFont font;
   font.setPointSize(12);

   auto start = chrono::high_resolution_clock::now();


    playerName = ui->lineEdit_Player->text();
    vector<string> dests = vector<string>();
    dests.push_back(playerName.toStdString());
    vector<vector<string>> paths = adjGraph.findPath(userName.toStdString(), dests);

    string path;
    if(paths[0].empty())
        path = "No path found";
    else
    {
        path = "";
        for (unsigned int i = 0; i < paths[0].size() - 1; i++) {
            path += paths[0][i];
            path += " → ";
        }
        path += paths[0][paths[0].size() - 1];
    }

    string pathLength = "0";

    if(!paths[0].empty())
        pathLength = to_string(paths[0].size());

    string pathOutput = "Path: " + path + "          Path Length: " + pathLength;
    //ui->separationLabel->setText(QString::fromStdString(pathOutput));

    ui->table2->setItem(0,0,new QTableWidgetItem(playerName));
    ui->table2->setItem(0,1,new QTableWidgetItem(QString::fromStdString(path)));
    ui->table2->setItem(0,2,new QTableWidgetItem(QString::fromStdString(pathLength)));

    ui->table2->setFont(font);
    ui->table2->show();
    ui->table2->resizeColumnToContents(0);
    ui->table2->resizeColumnToContents(1);
    ui->table2->resizeColumnToContents(2);

    auto end = chrono::high_resolution_clock::now();

    int PlayerListTime = chrono::duration_cast<chrono::milliseconds>(end - start).count();;
    ui->PlayerListLabel->setText(QString::fromStdString("Adjacency List Search Time: " + to_string(PlayerListTime) + " ms"));

    start = chrono::high_resolution_clock::now();

    matrixGraph.findPath(userName.toStdString(), dests);

    end = chrono::high_resolution_clock::now();

    int PlayerMatrixTime = chrono::duration_cast<chrono::milliseconds>(end - start).count();;
    ui->PlayerMatrixLabel->setText(QString::fromStdString("Adjacency Matrix Search Time: " + to_string(PlayerMatrixTime) + " ms"));
}

void ChessELO::on_pushButton_Exit_clicked()
{
    close();
}
