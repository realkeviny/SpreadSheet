/********************************************************************************
** Form generated from reading UI file '.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI__H
#define UI__H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SpreadSheetClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SpreadSheetClass)
    {
        if (SpreadSheetClass->objectName().isEmpty())
            SpreadSheetClass->setObjectName(QString::fromUtf8("SpreadSheetClass"));
        SpreadSheetClass->resize(600, 400);
        menuBar = new QMenuBar(SpreadSheetClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        SpreadSheetClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SpreadSheetClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        SpreadSheetClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(SpreadSheetClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        SpreadSheetClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(SpreadSheetClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        SpreadSheetClass->setStatusBar(statusBar);

        retranslateUi(SpreadSheetClass);

        QMetaObject::connectSlotsByName(SpreadSheetClass);
    } // setupUi

    void retranslateUi(QMainWindow *SpreadSheetClass)
    {
        SpreadSheetClass->setWindowTitle(QCoreApplication::translate("SpreadSheetClass", "SpreadSheet", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SpreadSheetClass: public Ui_SpreadSheetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI__H
