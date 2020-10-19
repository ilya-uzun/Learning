/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_2;
    QTextEdit *textEdit_13;
    QTextEdit *textEdit_14;
    QTextEdit *textEdit_10;
    QTextEdit *textEdit_18;
    QTextEdit *textEdit_15;
    QTextEdit *textEdit_12;
    QTextEdit *textEdit_16;
    QTextEdit *textEdit_11;
    QTextEdit *textEdit_17;
    QWidget *widget;
    QGridLayout *gridLayout;
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;
    QTextEdit *textEdit_3;
    QTextEdit *textEdit_6;
    QTextEdit *textEdit_5;
    QTextEdit *textEdit_4;
    QTextEdit *textEdit_9;
    QTextEdit *textEdit_8;
    QTextEdit *textEdit_7;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(755, 619);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(280, 40, 221, 141));
        gridLayout_2 = new QGridLayout(layoutWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        textEdit_13 = new QTextEdit(layoutWidget);
        textEdit_13->setObjectName(QString::fromUtf8("textEdit_13"));

        gridLayout_2->addWidget(textEdit_13, 1, 0, 1, 1);

        textEdit_14 = new QTextEdit(layoutWidget);
        textEdit_14->setObjectName(QString::fromUtf8("textEdit_14"));

        gridLayout_2->addWidget(textEdit_14, 1, 1, 1, 1);

        textEdit_10 = new QTextEdit(layoutWidget);
        textEdit_10->setObjectName(QString::fromUtf8("textEdit_10"));

        gridLayout_2->addWidget(textEdit_10, 0, 0, 1, 1);

        textEdit_18 = new QTextEdit(layoutWidget);
        textEdit_18->setObjectName(QString::fromUtf8("textEdit_18"));

        gridLayout_2->addWidget(textEdit_18, 2, 2, 1, 1);

        textEdit_15 = new QTextEdit(layoutWidget);
        textEdit_15->setObjectName(QString::fromUtf8("textEdit_15"));

        gridLayout_2->addWidget(textEdit_15, 1, 2, 1, 1);

        textEdit_12 = new QTextEdit(layoutWidget);
        textEdit_12->setObjectName(QString::fromUtf8("textEdit_12"));

        gridLayout_2->addWidget(textEdit_12, 0, 2, 1, 1);

        textEdit_16 = new QTextEdit(layoutWidget);
        textEdit_16->setObjectName(QString::fromUtf8("textEdit_16"));

        gridLayout_2->addWidget(textEdit_16, 2, 0, 1, 1);

        textEdit_11 = new QTextEdit(layoutWidget);
        textEdit_11->setObjectName(QString::fromUtf8("textEdit_11"));

        gridLayout_2->addWidget(textEdit_11, 0, 1, 1, 1);

        textEdit_17 = new QTextEdit(layoutWidget);
        textEdit_17->setObjectName(QString::fromUtf8("textEdit_17"));

        gridLayout_2->addWidget(textEdit_17, 2, 1, 1, 1);

        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(40, 40, 211, 141));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        textEdit = new QTextEdit(widget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout->addWidget(textEdit, 0, 0, 1, 1);

        textEdit_2 = new QTextEdit(widget);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));

        gridLayout->addWidget(textEdit_2, 0, 1, 1, 1);

        textEdit_3 = new QTextEdit(widget);
        textEdit_3->setObjectName(QString::fromUtf8("textEdit_3"));

        gridLayout->addWidget(textEdit_3, 0, 2, 1, 1);

        textEdit_6 = new QTextEdit(widget);
        textEdit_6->setObjectName(QString::fromUtf8("textEdit_6"));

        gridLayout->addWidget(textEdit_6, 1, 0, 1, 1);

        textEdit_5 = new QTextEdit(widget);
        textEdit_5->setObjectName(QString::fromUtf8("textEdit_5"));

        gridLayout->addWidget(textEdit_5, 1, 1, 1, 1);

        textEdit_4 = new QTextEdit(widget);
        textEdit_4->setObjectName(QString::fromUtf8("textEdit_4"));

        gridLayout->addWidget(textEdit_4, 1, 2, 1, 1);

        textEdit_9 = new QTextEdit(widget);
        textEdit_9->setObjectName(QString::fromUtf8("textEdit_9"));

        gridLayout->addWidget(textEdit_9, 2, 0, 1, 1);

        textEdit_8 = new QTextEdit(widget);
        textEdit_8->setObjectName(QString::fromUtf8("textEdit_8"));

        gridLayout->addWidget(textEdit_8, 2, 1, 1, 1);

        textEdit_7 = new QTextEdit(widget);
        textEdit_7->setObjectName(QString::fromUtf8("textEdit_7"));

        gridLayout->addWidget(textEdit_7, 2, 2, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 755, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
