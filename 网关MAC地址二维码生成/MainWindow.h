#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"
#include "qrcodegen.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);
	~MainWindow();

private slots:
	void on_btnGenerate_clicked();
	void on_btnSave_clicked();

private:
	Ui::MainWindowClass ui;

	qrcodegen_arg qrArg;
	QImage* qrcodeImg = nullptr;

	QString rawMAC;
	QString fatMAC;

};
