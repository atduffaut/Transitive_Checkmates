/********************************************************************************
** Form generated from reading UI file 'chesselo.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHESSELO_H
#define UI_CHESSELO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChessELO
{
public:
    QWidget *centralwidget;
    QLabel *titleLabel;
    QLabel *ELOLabel;
    QLabel *descripLabel;
    QLabel *highestEloLabel;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *searchUserLabel;
    QLineEdit *lineEdit_User;
    QPushButton *pushButton_User;
    QLabel *separationLabel;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *searchPlayerLabel_2;
    QLineEdit *lineEdit_File;
    QPushButton *pushButton_File;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *searchPlayerLabel_3;
    QLineEdit *lineEdit_Player;
    QPushButton *pushButton_Player;
    QLabel *BuildListLabel;
    QLabel *BuildMatrixLabel;
    QTableWidget *table;
    QLabel *UserMatrixLabel;
    QLabel *UserListLabel;
    QLabel *PlayerMatrixLabel;
    QLabel *PlayerListLabel;
    QLabel *descripLabel_2;
    QTableWidget *table2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ChessELO)
    {
        if (ChessELO->objectName().isEmpty())
            ChessELO->setObjectName(QString::fromUtf8("ChessELO"));
        ChessELO->resize(811, 818);
        centralwidget = new QWidget(ChessELO);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        titleLabel = new QLabel(centralwidget);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        titleLabel->setGeometry(QRect(0, 10, 761, 31));
        QFont font;
        font.setPointSize(40);
        font.setBold(true);
        font.setItalic(false);
        titleLabel->setFont(font);
        titleLabel->setStyleSheet(QString::fromUtf8("font: 700 40pt \"Calibri\";\n"
"color: rgb(0, 170, 255)"));
        titleLabel->setAlignment(Qt::AlignCenter);
        ELOLabel = new QLabel(centralwidget);
        ELOLabel->setObjectName(QString::fromUtf8("ELOLabel"));
        ELOLabel->setGeometry(QRect(100, 770, 571, 24));
        ELOLabel->setStyleSheet(QString::fromUtf8("font: 14pt \"Calibri\";"));
        descripLabel = new QLabel(centralwidget);
        descripLabel->setObjectName(QString::fromUtf8("descripLabel"));
        descripLabel->setGeometry(QRect(20, 160, 761, 41));
        descripLabel->setStyleSheet(QString::fromUtf8("font: 12pt \"Calibri\";"));
        descripLabel->setAlignment(Qt::AlignCenter);
        highestEloLabel = new QLabel(centralwidget);
        highestEloLabel->setObjectName(QString::fromUtf8("highestEloLabel"));
        highestEloLabel->setGeometry(QRect(0, 260, 761, 24));
        highestEloLabel->setStyleSheet(QString::fromUtf8("font: 14pt \"Calibri\";"));
        highestEloLabel->setAlignment(Qt::AlignCenter);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(130, 200, 451, 39));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        searchUserLabel = new QLabel(layoutWidget);
        searchUserLabel->setObjectName(QString::fromUtf8("searchUserLabel"));
        searchUserLabel->setStyleSheet(QString::fromUtf8("font: 14pt \"Calibri\";"));

        horizontalLayout->addWidget(searchUserLabel);

        lineEdit_User = new QLineEdit(layoutWidget);
        lineEdit_User->setObjectName(QString::fromUtf8("lineEdit_User"));

        horizontalLayout->addWidget(lineEdit_User);

        pushButton_User = new QPushButton(layoutWidget);
        pushButton_User->setObjectName(QString::fromUtf8("pushButton_User"));
        pushButton_User->setStyleSheet(QString::fromUtf8("font: 12pt \"Segoe UI\";"));

        horizontalLayout->addWidget(pushButton_User);

        separationLabel = new QLabel(centralwidget);
        separationLabel->setObjectName(QString::fromUtf8("separationLabel"));
        separationLabel->setGeometry(QRect(0, 650, 671, 24));
        separationLabel->setStyleSheet(QString::fromUtf8("font: 14pt \"Calibri\";"));
        layoutWidget_2 = new QWidget(centralwidget);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(130, 60, 451, 39));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        searchPlayerLabel_2 = new QLabel(layoutWidget_2);
        searchPlayerLabel_2->setObjectName(QString::fromUtf8("searchPlayerLabel_2"));
        searchPlayerLabel_2->setStyleSheet(QString::fromUtf8("font: 14pt \"Calibri\";"));

        horizontalLayout_2->addWidget(searchPlayerLabel_2);

        lineEdit_File = new QLineEdit(layoutWidget_2);
        lineEdit_File->setObjectName(QString::fromUtf8("lineEdit_File"));

        horizontalLayout_2->addWidget(lineEdit_File);

        pushButton_File = new QPushButton(layoutWidget_2);
        pushButton_File->setObjectName(QString::fromUtf8("pushButton_File"));
        pushButton_File->setStyleSheet(QString::fromUtf8("font: 12pt \"Segoe UI\";"));

        horizontalLayout_2->addWidget(pushButton_File);

        layoutWidget_3 = new QWidget(centralwidget);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(130, 590, 451, 39));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        searchPlayerLabel_3 = new QLabel(layoutWidget_3);
        searchPlayerLabel_3->setObjectName(QString::fromUtf8("searchPlayerLabel_3"));
        searchPlayerLabel_3->setStyleSheet(QString::fromUtf8("font: 14pt \"Calibri\";"));

        horizontalLayout_3->addWidget(searchPlayerLabel_3);

        lineEdit_Player = new QLineEdit(layoutWidget_3);
        lineEdit_Player->setObjectName(QString::fromUtf8("lineEdit_Player"));

        horizontalLayout_3->addWidget(lineEdit_Player);

        pushButton_Player = new QPushButton(layoutWidget_3);
        pushButton_Player->setObjectName(QString::fromUtf8("pushButton_Player"));
        pushButton_Player->setStyleSheet(QString::fromUtf8("font: 12pt \"Segoe UI\";"));

        horizontalLayout_3->addWidget(pushButton_Player);

        BuildListLabel = new QLabel(centralwidget);
        BuildListLabel->setObjectName(QString::fromUtf8("BuildListLabel"));
        BuildListLabel->setGeometry(QRect(50, 110, 351, 37));
        BuildListLabel->setStyleSheet(QString::fromUtf8("font: 14pt \"Calibri\";"));
        BuildMatrixLabel = new QLabel(centralwidget);
        BuildMatrixLabel->setObjectName(QString::fromUtf8("BuildMatrixLabel"));
        BuildMatrixLabel->setGeometry(QRect(430, 110, 341, 37));
        BuildMatrixLabel->setStyleSheet(QString::fromUtf8("font: 14pt \"Calibri\";"));
        table = new QTableWidget(centralwidget);
        if (table->columnCount() < 4)
            table->setColumnCount(4);
        QFont font1;
        font1.setPointSize(12);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font1);
        table->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font1);
        table->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font1);
        table->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font1);
        table->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        if (table->rowCount() < 5)
            table->setRowCount(5);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        table->setVerticalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        table->setVerticalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        table->setVerticalHeaderItem(2, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        table->setVerticalHeaderItem(3, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        table->setVerticalHeaderItem(4, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setFont(font1);
        table->setItem(0, 0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setFont(font1);
        table->setItem(0, 1, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setFont(font1);
        table->setItem(0, 2, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        __qtablewidgetitem12->setFont(font1);
        table->setItem(0, 3, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        __qtablewidgetitem13->setFont(font1);
        table->setItem(1, 0, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        __qtablewidgetitem14->setFont(font1);
        table->setItem(1, 1, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        __qtablewidgetitem15->setFont(font1);
        table->setItem(1, 2, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        __qtablewidgetitem16->setFont(font1);
        table->setItem(1, 3, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        __qtablewidgetitem17->setFont(font1);
        table->setItem(2, 0, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        __qtablewidgetitem18->setFont(font1);
        table->setItem(2, 1, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        __qtablewidgetitem19->setFont(font1);
        table->setItem(2, 2, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        __qtablewidgetitem20->setFont(font1);
        table->setItem(2, 3, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        __qtablewidgetitem21->setFont(font1);
        table->setItem(3, 0, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        __qtablewidgetitem22->setFont(font1);
        table->setItem(3, 1, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        __qtablewidgetitem23->setFont(font1);
        table->setItem(3, 2, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        __qtablewidgetitem24->setFont(font1);
        table->setItem(3, 3, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        __qtablewidgetitem25->setFont(font1);
        table->setItem(4, 0, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        __qtablewidgetitem26->setFont(font1);
        table->setItem(4, 1, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        __qtablewidgetitem27->setFont(font1);
        table->setItem(4, 2, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        __qtablewidgetitem28->setFont(font1);
        table->setItem(4, 3, __qtablewidgetitem28);
        table->setObjectName(QString::fromUtf8("table"));
        table->setGeometry(QRect(50, 290, 681, 181));
        UserMatrixLabel = new QLabel(centralwidget);
        UserMatrixLabel->setObjectName(QString::fromUtf8("UserMatrixLabel"));
        UserMatrixLabel->setGeometry(QRect(410, 500, 351, 37));
        UserMatrixLabel->setStyleSheet(QString::fromUtf8("font: 14pt \"Calibri\";"));
        UserListLabel = new QLabel(centralwidget);
        UserListLabel->setObjectName(QString::fromUtf8("UserListLabel"));
        UserListLabel->setGeometry(QRect(30, 500, 341, 37));
        UserListLabel->setStyleSheet(QString::fromUtf8("font: 14pt \"Calibri\";"));
        PlayerMatrixLabel = new QLabel(centralwidget);
        PlayerMatrixLabel->setObjectName(QString::fromUtf8("PlayerMatrixLabel"));
        PlayerMatrixLabel->setGeometry(QRect(410, 720, 351, 37));
        PlayerMatrixLabel->setStyleSheet(QString::fromUtf8("font: 14pt \"Calibri\";"));
        PlayerListLabel = new QLabel(centralwidget);
        PlayerListLabel->setObjectName(QString::fromUtf8("PlayerListLabel"));
        PlayerListLabel->setGeometry(QRect(30, 720, 351, 37));
        PlayerListLabel->setStyleSheet(QString::fromUtf8("font: 14pt \"Calibri\";"));
        descripLabel_2 = new QLabel(centralwidget);
        descripLabel_2->setObjectName(QString::fromUtf8("descripLabel_2"));
        descripLabel_2->setGeometry(QRect(-30, 560, 761, 41));
        descripLabel_2->setStyleSheet(QString::fromUtf8("font: 12pt \"Calibri\";"));
        descripLabel_2->setAlignment(Qt::AlignCenter);
        table2 = new QTableWidget(centralwidget);
        if (table2->columnCount() < 3)
            table2->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        __qtablewidgetitem29->setFont(font1);
        table2->setHorizontalHeaderItem(0, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        __qtablewidgetitem30->setFont(font1);
        table2->setHorizontalHeaderItem(1, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        __qtablewidgetitem31->setFont(font1);
        table2->setHorizontalHeaderItem(2, __qtablewidgetitem31);
        if (table2->rowCount() < 1)
            table2->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        table2->setVerticalHeaderItem(0, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        __qtablewidgetitem33->setFont(font1);
        table2->setItem(0, 0, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        __qtablewidgetitem34->setFont(font1);
        table2->setItem(0, 1, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        __qtablewidgetitem35->setFont(font1);
        table2->setItem(0, 2, __qtablewidgetitem35);
        table2->setObjectName(QString::fromUtf8("table2"));
        table2->setGeometry(QRect(210, 630, 361, 61));
        ChessELO->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ChessELO);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 811, 21));
        ChessELO->setMenuBar(menubar);
        statusbar = new QStatusBar(ChessELO);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ChessELO->setStatusBar(statusbar);

        retranslateUi(ChessELO);

        QMetaObject::connectSlotsByName(ChessELO);
    } // setupUi

    void retranslateUi(QMainWindow *ChessELO)
    {
        ChessELO->setWindowTitle(QCoreApplication::translate("ChessELO", "ChessELO", nullptr));
        titleLabel->setText(QCoreApplication::translate("ChessELO", "\342\231\230 Transitive Checkmates \342\231\230", nullptr));
        ELOLabel->setText(QString());
        descripLabel->setText(QCoreApplication::translate("ChessELO", "Find the path from the user to the 5 highest ELO players they've ever transitively beaten.", nullptr));
        highestEloLabel->setText(QCoreApplication::translate("ChessELO", "Path to Top 5 Highest ELO Players:", nullptr));
        searchUserLabel->setText(QCoreApplication::translate("ChessELO", "Enter User Name:", nullptr));
        pushButton_User->setText(QCoreApplication::translate("ChessELO", "Enter", nullptr));
        separationLabel->setText(QString());
        searchPlayerLabel_2->setText(QCoreApplication::translate("ChessELO", "Enter File Name:", nullptr));
        pushButton_File->setText(QCoreApplication::translate("ChessELO", "Enter", nullptr));
        searchPlayerLabel_3->setText(QCoreApplication::translate("ChessELO", "Search Player Name:", nullptr));
        pushButton_Player->setText(QCoreApplication::translate("ChessELO", "Enter", nullptr));
        BuildListLabel->setText(QString());
        BuildMatrixLabel->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = table->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("ChessELO", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = table->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("ChessELO", "ELO", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = table->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("ChessELO", "Path", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = table->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("ChessELO", "Path Length", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = table->verticalHeaderItem(0);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("ChessELO", "#1", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = table->verticalHeaderItem(1);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("ChessELO", "#2", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = table->verticalHeaderItem(2);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("ChessELO", "#3", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = table->verticalHeaderItem(3);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("ChessELO", "#4", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = table->verticalHeaderItem(4);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("ChessELO", "#5", nullptr));

        const bool __sortingEnabled = table->isSortingEnabled();
        table->setSortingEnabled(false);
        table->setSortingEnabled(__sortingEnabled);

        UserMatrixLabel->setText(QString());
        UserListLabel->setText(QString());
        PlayerMatrixLabel->setText(QString());
        PlayerListLabel->setText(QString());
        descripLabel_2->setText(QCoreApplication::translate("ChessELO", "Find the path from the user to the Searched Player", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = table2->horizontalHeaderItem(0);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("ChessELO", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = table2->horizontalHeaderItem(1);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("ChessELO", "Path", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = table2->horizontalHeaderItem(2);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("ChessELO", "Path Length", nullptr));

        const bool __sortingEnabled1 = table2->isSortingEnabled();
        table2->setSortingEnabled(false);
        table2->setSortingEnabled(__sortingEnabled1);

    } // retranslateUi

};

namespace Ui {
    class ChessELO: public Ui_ChessELO {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHESSELO_H
