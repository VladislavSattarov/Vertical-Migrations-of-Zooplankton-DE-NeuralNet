/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab_3;
    QCustomPlot *widget;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_3;
    QLabel *label_8;
    QLabel *label_7;
    QGridLayout *gridLayout;
    QLabel *label_10;
    QLineEdit *line_PS;
    QLabel *label_9;
    QLineEdit *line_CDE;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_5;
    QLineEdit *lineEdit;
    QPushButton *LoadButton;
    QLabel *label_14;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout_2;
    QPushButton *ProcessDayButton;
    QWidget *layoutWidget3;
    QGridLayout *gridLayout_4;
    QPushButton *SaveButton;
    QLabel *NameSelected;
    QLabel *SelectedLabel;
    QWidget *tab_4;
    QCustomPlot *widget_6;
    QWidget *tab;
    QLabel *label_3;
    QLabel *label_4;
    QCustomPlot *widget_4;
    QLabel *label_5;
    QCustomPlot *widget_5;
    QCustomPlot *widget_2;
    QCustomPlot *widget_3;
    QLabel *label_6;
    QTextBrowser *textBrowser;
    QCheckBox *checkBox;
    QLineEdit *lineEdit_11per;
    QLabel *label_21;
    QLineEdit *lineEdit_2maxDeep;
    QWidget *layoutWidget4;
    QGridLayout *gridLayout_6;
    QLabel *label_11;
    QLineEdit *lineEdit_2xi1;
    QLabel *label_12;
    QLineEdit *lineEdit_3xi2;
    QLabel *label_13;
    QLineEdit *lineEdit_4x3;
    QLabel *label_15;
    QLineEdit *lineEdit_5x4;
    QLabel *label_16;
    QLineEdit *eta1;
    QLabel *label_17;
    QLineEdit *eta2;
    QLabel *label_18;
    QLineEdit *c1;
    QLabel *label_19;
    QLineEdit *lineEdit_9c2;
    QLabel *label_20;
    QLineEdit *lineEdit_10c3;
    QLabel *label_22;
    QWidget *layoutWidget5;
    QGridLayout *gridLayout_7;
    QLabel *label_23;
    QLineEdit *AJ;
    QLabel *label_26;
    QLineEdit *AA;
    QLabel *label_29;
    QLineEdit *GJ;
    QLabel *label_24;
    QLineEdit *BJ;
    QLabel *label_27;
    QLineEdit *BA;
    QLabel *label_30;
    QLineEdit *GA;
    QLabel *label_25;
    QLineEdit *DJ;
    QLabel *label_28;
    QLineEdit *DA;
    QCheckBox *checkBox_2;
    QWidget *tab_2;
    QCustomPlot *widget_7;
    QWidget *layoutWidget6;
    QGridLayout *gridLayout_12;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_2;
    QGridLayout *gridLayout_9;
    QLabel *SelectedLabel2;
    QLabel *SelectedNameLabel2;
    QGridLayout *gridLayout_8;
    QLabel *CountNN;
    QLabel *CountNNi;
    QGridLayout *gridLayout_10;
    QLabel *label_31;
    QLineEdit *CDEline;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QGridLayout *gridLayout_11;
    QLabel *label_32;
    QLabel *jlabel2;
    QStatusBar *statusbar;
    QMenuBar *menuBar;
    QMenu *menuv2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1286, 794);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 1281, 761));
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        widget = new QCustomPlot(tab_3);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(190, 10, 1081, 731));
        layoutWidget = new QWidget(tab_3);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 172, 117));
        gridLayout_3 = new QGridLayout(layoutWidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_3->addWidget(label_8, 1, 1, 1, 1);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_3->addWidget(label_7, 1, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 0, 0, 1, 2);

        line_PS = new QLineEdit(layoutWidget);
        line_PS->setObjectName(QString::fromUtf8("line_PS"));

        gridLayout->addWidget(line_PS, 0, 2, 1, 1);

        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 1, 0, 1, 2);

        line_CDE = new QLineEdit(layoutWidget);
        line_CDE->setObjectName(QString::fromUtf8("line_CDE"));

        gridLayout->addWidget(line_CDE, 1, 2, 1, 1);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 2, 1, 1, 2);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 4, 0, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 4, 1, 1, 2);


        gridLayout_3->addLayout(gridLayout, 0, 0, 1, 2);

        layoutWidget1 = new QWidget(tab_3);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 170, 169, 70));
        gridLayout_5 = new QGridLayout(layoutWidget1);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(layoutWidget1);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout_5->addWidget(lineEdit, 0, 1, 1, 1);

        LoadButton = new QPushButton(layoutWidget1);
        LoadButton->setObjectName(QString::fromUtf8("LoadButton"));

        gridLayout_5->addWidget(LoadButton, 1, 0, 1, 2);

        label_14 = new QLabel(layoutWidget1);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_5->addWidget(label_14, 0, 0, 1, 1);

        layoutWidget2 = new QWidget(tab_3);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 270, 169, 44));
        gridLayout_2 = new QGridLayout(layoutWidget2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        ProcessDayButton = new QPushButton(layoutWidget2);
        ProcessDayButton->setObjectName(QString::fromUtf8("ProcessDayButton"));

        gridLayout_2->addWidget(ProcessDayButton, 0, 0, 1, 1);

        layoutWidget3 = new QWidget(tab_3);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 130, 171, 44));
        gridLayout_4 = new QGridLayout(layoutWidget3);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        SaveButton = new QPushButton(layoutWidget3);
        SaveButton->setObjectName(QString::fromUtf8("SaveButton"));

        gridLayout_4->addWidget(SaveButton, 0, 0, 1, 1);

        NameSelected = new QLabel(tab_3);
        NameSelected->setObjectName(QString::fromUtf8("NameSelected"));
        NameSelected->setGeometry(QRect(100, 240, 81, 29));
        SelectedLabel = new QLabel(tab_3);
        SelectedLabel->setObjectName(QString::fromUtf8("SelectedLabel"));
        SelectedLabel->setGeometry(QRect(12, 240, 82, 29));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        widget_6 = new QCustomPlot(tab_4);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        widget_6->setGeometry(QRect(10, 20, 1251, 701));
        tabWidget->addTab(tab_4, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(630, 340, 47, 13));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(1060, 340, 47, 13));
        widget_4 = new QCustomPlot(tab);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setGeometry(QRect(440, 360, 412, 326));
        label_5 = new QLabel(tab);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(630, 690, 47, 13));
        widget_5 = new QCustomPlot(tab);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setGeometry(QRect(860, 360, 411, 326));
        widget_2 = new QCustomPlot(tab);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(440, 10, 412, 327));
        widget_3 = new QCustomPlot(tab);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(860, 10, 411, 327));
        label_6 = new QLabel(tab);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(1060, 690, 47, 13));
        textBrowser = new QTextBrowser(tab);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(10, 10, 411, 221));
        checkBox = new QCheckBox(tab);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(20, 540, 251, 21));
        lineEdit_11per = new QLineEdit(tab);
        lineEdit_11per->setObjectName(QString::fromUtf8("lineEdit_11per"));
        lineEdit_11per->setGeometry(QRect(200, 540, 61, 21));
        label_21 = new QLabel(tab);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(250, 250, 131, 16));
        lineEdit_2maxDeep = new QLineEdit(tab);
        lineEdit_2maxDeep->setObjectName(QString::fromUtf8("lineEdit_2maxDeep"));
        lineEdit_2maxDeep->setGeometry(QRect(380, 250, 51, 20));
        layoutWidget4 = new QWidget(tab);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(10, 240, 231, 281));
        gridLayout_6 = new QGridLayout(layoutWidget4);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        label_11 = new QLabel(layoutWidget4);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_6->addWidget(label_11, 0, 0, 1, 1);

        lineEdit_2xi1 = new QLineEdit(layoutWidget4);
        lineEdit_2xi1->setObjectName(QString::fromUtf8("lineEdit_2xi1"));

        gridLayout_6->addWidget(lineEdit_2xi1, 0, 1, 1, 1);

        label_12 = new QLabel(layoutWidget4);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_6->addWidget(label_12, 1, 0, 1, 1);

        lineEdit_3xi2 = new QLineEdit(layoutWidget4);
        lineEdit_3xi2->setObjectName(QString::fromUtf8("lineEdit_3xi2"));

        gridLayout_6->addWidget(lineEdit_3xi2, 1, 1, 1, 1);

        label_13 = new QLabel(layoutWidget4);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_6->addWidget(label_13, 2, 0, 1, 1);

        lineEdit_4x3 = new QLineEdit(layoutWidget4);
        lineEdit_4x3->setObjectName(QString::fromUtf8("lineEdit_4x3"));

        gridLayout_6->addWidget(lineEdit_4x3, 2, 1, 1, 1);

        label_15 = new QLabel(layoutWidget4);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_6->addWidget(label_15, 3, 0, 1, 1);

        lineEdit_5x4 = new QLineEdit(layoutWidget4);
        lineEdit_5x4->setObjectName(QString::fromUtf8("lineEdit_5x4"));

        gridLayout_6->addWidget(lineEdit_5x4, 3, 1, 1, 1);

        label_16 = new QLabel(layoutWidget4);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_6->addWidget(label_16, 4, 0, 1, 1);

        eta1 = new QLineEdit(layoutWidget4);
        eta1->setObjectName(QString::fromUtf8("eta1"));

        gridLayout_6->addWidget(eta1, 4, 1, 1, 1);

        label_17 = new QLabel(layoutWidget4);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout_6->addWidget(label_17, 5, 0, 1, 1);

        eta2 = new QLineEdit(layoutWidget4);
        eta2->setObjectName(QString::fromUtf8("eta2"));

        gridLayout_6->addWidget(eta2, 5, 1, 1, 1);

        label_18 = new QLabel(layoutWidget4);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout_6->addWidget(label_18, 6, 0, 1, 1);

        c1 = new QLineEdit(layoutWidget4);
        c1->setObjectName(QString::fromUtf8("c1"));

        gridLayout_6->addWidget(c1, 6, 1, 1, 1);

        label_19 = new QLabel(layoutWidget4);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        gridLayout_6->addWidget(label_19, 7, 0, 1, 1);

        lineEdit_9c2 = new QLineEdit(layoutWidget4);
        lineEdit_9c2->setObjectName(QString::fromUtf8("lineEdit_9c2"));

        gridLayout_6->addWidget(lineEdit_9c2, 7, 1, 1, 1);

        label_20 = new QLabel(layoutWidget4);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        gridLayout_6->addWidget(label_20, 8, 0, 1, 1);

        lineEdit_10c3 = new QLineEdit(layoutWidget4);
        lineEdit_10c3->setObjectName(QString::fromUtf8("lineEdit_10c3"));

        gridLayout_6->addWidget(lineEdit_10c3, 8, 1, 1, 1);

        label_22 = new QLabel(tab);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(10, 580, 181, 20));
        layoutWidget5 = new QWidget(tab);
        layoutWidget5->setObjectName(QString::fromUtf8("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(10, 610, 421, 81));
        gridLayout_7 = new QGridLayout(layoutWidget5);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        label_23 = new QLabel(layoutWidget5);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        gridLayout_7->addWidget(label_23, 0, 0, 1, 1);

        AJ = new QLineEdit(layoutWidget5);
        AJ->setObjectName(QString::fromUtf8("AJ"));

        gridLayout_7->addWidget(AJ, 0, 1, 1, 1);

        label_26 = new QLabel(layoutWidget5);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        gridLayout_7->addWidget(label_26, 0, 2, 1, 1);

        AA = new QLineEdit(layoutWidget5);
        AA->setObjectName(QString::fromUtf8("AA"));

        gridLayout_7->addWidget(AA, 0, 3, 1, 2);

        label_29 = new QLabel(layoutWidget5);
        label_29->setObjectName(QString::fromUtf8("label_29"));

        gridLayout_7->addWidget(label_29, 0, 5, 1, 1);

        GJ = new QLineEdit(layoutWidget5);
        GJ->setObjectName(QString::fromUtf8("GJ"));

        gridLayout_7->addWidget(GJ, 0, 6, 1, 1);

        label_24 = new QLabel(layoutWidget5);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        gridLayout_7->addWidget(label_24, 1, 0, 1, 1);

        BJ = new QLineEdit(layoutWidget5);
        BJ->setObjectName(QString::fromUtf8("BJ"));

        gridLayout_7->addWidget(BJ, 1, 1, 1, 1);

        label_27 = new QLabel(layoutWidget5);
        label_27->setObjectName(QString::fromUtf8("label_27"));

        gridLayout_7->addWidget(label_27, 1, 2, 1, 1);

        BA = new QLineEdit(layoutWidget5);
        BA->setObjectName(QString::fromUtf8("BA"));

        gridLayout_7->addWidget(BA, 1, 3, 1, 2);

        label_30 = new QLabel(layoutWidget5);
        label_30->setObjectName(QString::fromUtf8("label_30"));

        gridLayout_7->addWidget(label_30, 1, 5, 1, 1);

        GA = new QLineEdit(layoutWidget5);
        GA->setObjectName(QString::fromUtf8("GA"));

        gridLayout_7->addWidget(GA, 1, 6, 1, 1);

        label_25 = new QLabel(layoutWidget5);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        gridLayout_7->addWidget(label_25, 2, 0, 1, 1);

        DJ = new QLineEdit(layoutWidget5);
        DJ->setObjectName(QString::fromUtf8("DJ"));

        gridLayout_7->addWidget(DJ, 2, 1, 1, 1);

        label_28 = new QLabel(layoutWidget5);
        label_28->setObjectName(QString::fromUtf8("label_28"));

        gridLayout_7->addWidget(label_28, 2, 2, 1, 1);

        DA = new QLineEdit(layoutWidget5);
        DA->setObjectName(QString::fromUtf8("DA"));

        gridLayout_7->addWidget(DA, 2, 3, 1, 2);

        checkBox_2 = new QCheckBox(tab);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(250, 330, 241, 31));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        widget_7 = new QCustomPlot(tab_2);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        widget_7->setGeometry(QRect(250, 10, 1021, 711));
        layoutWidget6 = new QWidget(tab_2);
        layoutWidget6->setObjectName(QString::fromUtf8("layoutWidget6"));
        layoutWidget6->setGeometry(QRect(11, 12, 231, 251));
        gridLayout_12 = new QGridLayout(layoutWidget6);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        gridLayout_12->setContentsMargins(0, 0, 0, 0);
        lineEdit_2 = new QLineEdit(layoutWidget6);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout_12->addWidget(lineEdit_2, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(layoutWidget6);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout_12->addWidget(pushButton_2, 1, 0, 1, 1);

        gridLayout_9 = new QGridLayout();
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        SelectedLabel2 = new QLabel(layoutWidget6);
        SelectedLabel2->setObjectName(QString::fromUtf8("SelectedLabel2"));

        gridLayout_9->addWidget(SelectedLabel2, 0, 0, 1, 1);

        SelectedNameLabel2 = new QLabel(layoutWidget6);
        SelectedNameLabel2->setObjectName(QString::fromUtf8("SelectedNameLabel2"));

        gridLayout_9->addWidget(SelectedNameLabel2, 0, 1, 1, 1);


        gridLayout_12->addLayout(gridLayout_9, 2, 0, 1, 1);

        gridLayout_8 = new QGridLayout();
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        CountNN = new QLabel(layoutWidget6);
        CountNN->setObjectName(QString::fromUtf8("CountNN"));

        gridLayout_8->addWidget(CountNN, 0, 0, 1, 1);

        CountNNi = new QLabel(layoutWidget6);
        CountNNi->setObjectName(QString::fromUtf8("CountNNi"));

        gridLayout_8->addWidget(CountNNi, 0, 1, 1, 1);


        gridLayout_12->addLayout(gridLayout_8, 3, 0, 1, 1);

        gridLayout_10 = new QGridLayout();
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        label_31 = new QLabel(layoutWidget6);
        label_31->setObjectName(QString::fromUtf8("label_31"));

        gridLayout_10->addWidget(label_31, 0, 0, 1, 1);

        CDEline = new QLineEdit(layoutWidget6);
        CDEline->setObjectName(QString::fromUtf8("CDEline"));

        gridLayout_10->addWidget(CDEline, 0, 1, 1, 1);


        gridLayout_12->addLayout(gridLayout_10, 4, 0, 1, 1);

        pushButton_4 = new QPushButton(layoutWidget6);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        gridLayout_12->addWidget(pushButton_4, 5, 0, 1, 1);

        pushButton_3 = new QPushButton(layoutWidget6);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout_12->addWidget(pushButton_3, 6, 0, 1, 1);

        gridLayout_11 = new QGridLayout();
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        label_32 = new QLabel(layoutWidget6);
        label_32->setObjectName(QString::fromUtf8("label_32"));

        gridLayout_11->addWidget(label_32, 0, 0, 1, 1);

        jlabel2 = new QLabel(layoutWidget6);
        jlabel2->setObjectName(QString::fromUtf8("jlabel2"));

        gridLayout_11->addWidget(jlabel2, 0, 1, 1, 1);


        gridLayout_12->addLayout(gridLayout_11, 7, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1286, 21));
        menuv2 = new QMenu(menuBar);
        menuv2->setObjectName(QString::fromUtf8("menuv2"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuv2->menuAction());

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_8->setText(QString());
        label_7->setText(QCoreApplication::translate("MainWindow", "\320\222\321\200\320\265\320\274\321\217 \320\262\321\213\320\277\320\276\320\273\320\275\320\265\320\275\320\270\321\217:", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"right\">\320\240\320\260\320\267\320\274\320\265\321\200 \320\277\320\276\320\277\321\203\320\273\321\217\321\206\320\270\320\270:</p></body></html>", nullptr));
        line_PS->setText(QCoreApplication::translate("MainWindow", "100", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"right\">\320\232\320\276\320\273-\320\262\320\276 \320\276\320\277\320\265\321\200\320\260\321\206\320\270\320\271 DE:</p></body></html>", nullptr));
        line_CDE->setText(QCoreApplication::translate("MainWindow", "10", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\321\203\321\201\321\202\320\270\321\202\321\214 \320\276\320\261\321\203\321\207\320\265\320\275\320\270\320\265", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"right\"><span style=\" font-weight:600;\">J=</span></p></body></html>", nullptr));
        label_2->setText(QString());
        LoadButton->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "\320\230\320\274\321\217 \320\276\320\261\321\212\320\265\320\272\321\202\320\260:", nullptr));
        ProcessDayButton->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\207\320\270\321\201\320\273\320\270\321\202\321\214", nullptr));
        SaveButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        NameSelected->setText(QString());
        SelectedLabel->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\320\275\320\276:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "\320\234\320\270\320\263\321\200\320\260\321\206\320\270\321\217 \320\267\320\276\320\276\320\277\320\273\320\260\320\275\320\272\321\202\320\276\320\275\320\260", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\265\320\275\320\270\320\265 \321\204\320\270\321\202\320\275\320\265\321\201 \321\204\321\203\320\275\320\272\321\206\320\270\320\270", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "E(x)", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Sx(x)", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "St(t)", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "G(x)", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">\320\244\321\203\320\275\320\272\321\206\320\270\321\217 \320\277\320\270\321\211\320\270:</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">E(x) = (tanh(xi</span><span style=\" font-size:14pt; vertical-align:sub;\">1</span><span style=\" font-size:14pt;\">(x+C</span><span style=\" font-size:14pt; vertical-align:sub;\">1</span><span style=\" font-size:14pt;\">))+1)/2</span></p>\n"
"<p style=\" margin-top:"
                        "0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">\320\244\321\203\320\275\320\272\321\206\320\270\321\217 \321\200\320\260\321\201\320\277\321\200\320\265\320\264\320\265\320\273\320\265\320\275\320\270\321\217 \321\205\320\270\321\211\320\275\320\270\320\272\320\276\320\262:</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">S</span><span style=\" font-size:14pt; vertical-align:sub;\">x</span><span style=\" font-size:14pt;\">(x) = (tanh(xi</span><span style=\" font-size:14pt; vertical-align:sub;\">2</span><span style=\" font-size:14pt;\">(x+C</span><span style=\" font-size:14pt; vertical-align:sub;\">1</span><span style=\" font-size:14pt;\">)+1)/2</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\""
                        ">\320\244\321\203\320\275\320\272\321\206\320\270\321\217 \320\260\320\272\321\202\320\270\320\262\320\275\320\276\321\201\321\202\320\270 \321\205\320\270\321\211\320\275\320\270\320\272\320\276\320\262:</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">S</span><span style=\" font-size:14pt; vertical-align:sub;\">t</span><span style=\" font-size:14pt;\">(t) = (cos(2PI(t/1440+1/2))+1)/2</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">\320\244\321\203\320\275\320\272\321\206\320\270\321\217 \320\275\320\265\320\261\320\273\320\260\320\263\320\276\320\277\321\200\320\270\321\217\321\202\320\275\321\213\321\205 \321\204\320\260\320\272\321\202\320\276\321\200\320\276\320\262 \321\201\321\200\320\265\320\264\321\213:</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; "
                        "margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">D(x) = (xi</span><span style=\" font-size:14pt; vertical-align:sub;\">3</span><span style=\" font-size:14pt;\">eta</span><span style=\" font-size:14pt; vertical-align:sub;\">1</span><span style=\" font-size:14pt; vertical-align:super;\">x-c3</span><span style=\" font-size:14pt;\">+xi</span><span style=\" font-size:14pt; vertical-align:sub;\">4</span><span style=\" font-size:14pt;\">eta</span><span style=\" font-size:14pt; vertical-align:sub;\">2</span><span style=\" font-size:14pt; vertical-align:super;\">-(x-c4)</span><span style=\" font-size:14pt;\">)/2</span></p></body></html>", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\321\210\321\203\320\274\320\273\320\265\320\275\320\270\320\265 \321\204\321\203\320\275\320\272\321\206\320\270\320\270 \320\277\320\270\321\211\320\270 \320\275\320\260:", nullptr));
        lineEdit_11per->setText(QCoreApplication::translate("MainWindow", "0.05", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\320\272\321\201\320\270\320\274\320\260\320\273\321\214\320\275\320\260\321\217 \320\263\320\273\321\203\320\261\320\270\320\275\320\260:", nullptr));
        lineEdit_2maxDeep->setText(QCoreApplication::translate("MainWindow", "-150", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">xi</span><span style=\" font-size:12pt; font-weight:600; vertical-align:sub;\">1 </span><span style=\" font-size:12pt;\">=</span></p></body></html>", nullptr));
        lineEdit_2xi1->setText(QCoreApplication::translate("MainWindow", "0.02", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">xi</span><span style=\" font-size:12pt; font-weight:600; vertical-align:sub;\">2 </span><span style=\" font-size:12pt;\">=</span></p></body></html>", nullptr));
        lineEdit_3xi2->setText(QCoreApplication::translate("MainWindow", "0.025", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">xi</span><span style=\" font-size:12pt; font-weight:600; vertical-align:sub;\">3</span><span style=\" font-size:12pt; font-weight:600;\"> =</span></p></body></html>", nullptr));
        lineEdit_4x3->setText(QCoreApplication::translate("MainWindow", "0.105", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">xi</span><span style=\" font-size:12pt; font-weight:600; vertical-align:sub;\">4 </span><span style=\" font-size:12pt; font-weight:600;\">=</span></p></body></html>", nullptr));
        lineEdit_5x4->setText(QCoreApplication::translate("MainWindow", "0.105", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">eta</span><span style=\" font-size:12pt; font-weight:600; vertical-align:sub;\">1</span><span style=\" font-size:12pt; font-weight:600;\"> =</span></p></body></html>", nullptr));
        eta1->setText(QCoreApplication::translate("MainWindow", "1.15", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">eta</span><span style=\" font-size:12pt; font-weight:600; vertical-align:sub;\">2</span><span style=\" font-size:12pt; font-weight:600;\"> =</span></p></body></html>", nullptr));
        eta2->setText(QCoreApplication::translate("MainWindow", "1.15", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">C</span><span style=\" font-size:12pt; font-weight:600; vertical-align:sub;\">1 </span><span style=\" font-size:12pt; font-weight:600;\">=</span></p></body></html>", nullptr));
        c1->setText(QCoreApplication::translate("MainWindow", "40", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">C</span><span style=\" font-size:12pt; font-weight:600; vertical-align:sub;\">2</span><span style=\" font-size:12pt; font-weight:600;\"> =</span></p></body></html>", nullptr));
        lineEdit_9c2->setText(QCoreApplication::translate("MainWindow", "-10", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">C</span><span style=\" font-size:12pt; font-weight:600; vertical-align:sub;\">3</span><span style=\" font-size:12pt; font-weight:600;\"> =</span></p></body></html>", nullptr));
        lineEdit_10c3->setText(QCoreApplication::translate("MainWindow", "-120", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\321\215\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321\202\321\213 \321\204\320\270\321\202\320\275\320\265\321\201 \321\204\321\203\320\275\320\272\321\206\320\270\320\270:", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "Alpha_J", nullptr));
        AJ->setText(QCoreApplication::translate("MainWindow", "0.0016", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "Alpha_A", nullptr));
        AA->setText(QCoreApplication::translate("MainWindow", "0.006", nullptr));
        label_29->setText(QCoreApplication::translate("MainWindow", "Gamma_J", nullptr));
        GJ->setText(QCoreApplication::translate("MainWindow", "0.00008", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "Beta_J", nullptr));
        BJ->setText(QCoreApplication::translate("MainWindow", "0.0000007", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "Beta_A", nullptr));
        BA->setText(QCoreApplication::translate("MainWindow", "0.0000075", nullptr));
        label_30->setText(QCoreApplication::translate("MainWindow", "Gamma_A", nullptr));
        GA->setText(QCoreApplication::translate("MainWindow", "0.004", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "Delta_J", nullptr));
        DJ->setText(QCoreApplication::translate("MainWindow", "0.000016", nullptr));
        label_28->setText(QCoreApplication::translate("MainWindow", "Delta_A", nullptr));
        DA->setText(QCoreApplication::translate("MainWindow", "0.00006", nullptr));
        checkBox_2->setText(QCoreApplication::translate("MainWindow", "\320\236\320\261\321\203\321\207\320\265\320\275\320\270\320\265 \321\201 \320\270\320\267\320\274\320\265\320\275\321\217\321\216\321\211\320\270\320\274\320\270\321\201\321\217 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\320\260\320\274\320\270", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "\320\244\321\203\320\275\320\272\321\206\320\270\320\270 \321\201\321\200\320\265\320\264\321\213", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", nullptr));
        SelectedLabel2->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\266\320\265\320\275\320\276:", nullptr));
        SelectedNameLabel2->setText(QString());
        CountNN->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\266\320\265\320\275\320\276 \321\201\320\265\321\202\320\265\320\271:", nullptr));
        CountNNi->setText(QString());
        label_31->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\276\320\277\320\265\321\200\320\260\321\206\320\270\320\271 DE:", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\321\203\321\201\321\202\320\270\321\202\321\214 \320\276\320\261\321\203\321\207\320\265\320\275\320\270\320\265", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\207\320\270\321\201\320\273\320\270\321\202\321\214", nullptr));
        label_32->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"right\"><span style=\" font-weight:600;\">J=</span></p></body></html>", nullptr));
        jlabel2->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "\320\241\321\202\321\200\320\260\320\275\320\270\321\206\320\260", nullptr));
        menuv2->setTitle(QCoreApplication::translate("MainWindow", "2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
