/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QWidget *centralWidget;
    QLineEdit *editMAC;
    QLabel *labelImage;
    QPushButton *btnGenerate;
    QLabel *labelMAC;
    QPushButton *btnSave;
    QLabel *labelResult;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QString::fromUtf8("MainWindowClass"));
        MainWindowClass->resize(300, 480);
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        editMAC = new QLineEdit(centralWidget);
        editMAC->setObjectName(QString::fromUtf8("editMAC"));
        editMAC->setGeometry(QRect(25, 310, 250, 30));
        labelImage = new QLabel(centralWidget);
        labelImage->setObjectName(QString::fromUtf8("labelImage"));
        labelImage->setGeometry(QRect(25, 10, 250, 250));
        btnGenerate = new QPushButton(centralWidget);
        btnGenerate->setObjectName(QString::fromUtf8("btnGenerate"));
        btnGenerate->setGeometry(QRect(30, 350, 100, 40));
        labelMAC = new QLabel(centralWidget);
        labelMAC->setObjectName(QString::fromUtf8("labelMAC"));
        labelMAC->setGeometry(QRect(25, 270, 250, 30));
        btnSave = new QPushButton(centralWidget);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));
        btnSave->setGeometry(QRect(170, 350, 100, 40));
        labelResult = new QLabel(centralWidget);
        labelResult->setObjectName(QString::fromUtf8("labelResult"));
        labelResult->setGeometry(QRect(25, 400, 250, 60));
        MainWindowClass->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindowClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);

        retranslateUi(MainWindowClass);

        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "MainWindow", nullptr));
#ifndef QT_NO_TOOLTIP
        editMAC->setToolTip(QApplication::translate("MainWindowClass", "<html><head/><body><p>dsfdsf</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        labelImage->setText(QString());
        btnGenerate->setText(QApplication::translate("MainWindowClass", "\347\224\237\346\210\220", nullptr));
        labelMAC->setText(QString());
        btnSave->setText(QApplication::translate("MainWindowClass", "\344\277\235\345\255\230", nullptr));
        labelResult->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
