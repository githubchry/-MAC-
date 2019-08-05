#include "MainWindow.h"

#define BLACK qRgb(0,0,0)
#define WHITE qRgb(255,255,255)

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	qrArg.qrcodeBuffer = (uint8_t*)calloc(1, qrcodegen_BUFFER_LEN_MAX * sizeof(uint8_t));
	qrArg.tempBuffer = (uint8_t*)calloc(1, qrcodegen_BUFFER_LEN_MAX * sizeof(uint8_t));

	QFont ft("Microsoft YaHei", 15);
	ui.editMAC->setFont(ft);
	ui.editMAC->setAlignment(Qt::AlignCenter);

	ft.setBold(QFont::Bold);
	ui.labelMAC->setFont(ft);
	ui.labelMAC->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);

	QPalette palette;
	palette.setColor(QPalette::Background, QColor(255, 255, 255));
	ui.labelImage->setAutoFillBackground(true);
	ui.labelImage->setPalette(palette);
	ui.labelMAC->setAutoFillBackground(true);
	ui.labelMAC->setPalette(palette);


	palette.setColor(QPalette::WindowText, Qt::red);
	ui.labelResult->setPalette(palette);
	//鼠标可选
	ui.labelResult->setTextInteractionFlags(Qt::TextSelectableByMouse);
	//自动换行
	ui.labelResult->setWordWrap(true);
	ui.labelResult->setAlignment(Qt::AlignTop);
}

MainWindow::~MainWindow()
{
	if (qrArg.qrcodeBuffer) { free(qrArg.qrcodeBuffer); qrArg.qrcodeBuffer = NULL; }
	if (qrArg.tempBuffer) { free(qrArg.tempBuffer); qrArg.tempBuffer = NULL; }
}

void MainWindow::on_btnGenerate_clicked()
{
	if (ui.editMAC->text().length() <= 0)
	{
		return;
	}
	//去掉mac地址里面的冒号和空格
	rawMAC = ui.editMAC->text();
	fatMAC = rawMAC.remove(":").remove(" ").toUpper();


	qrArg.ecclel = qrcodegen_Ecc_LOW;
	qrArg.mask = qrcodegen_Mask_0;
	qrArg.length = fatMAC.length();

	QByteArray temp = fatMAC.toLocal8Bit();
	strcpy((char *)qrArg.tempBuffer, temp.data());
	qrcodegen_encodeBinary(qrArg.tempBuffer, qrArg.length, qrArg.qrcodeBuffer, qrArg.ecclel, qrcodegen_VERSION_MIN, qrcodegen_VERSION_MAX, qrArg.mask, true);

	int qrcodegen_border = 2;
	int qrcodegen_scale = 10;
	int qrcodeSize = qrcodegen_getSize(qrArg.qrcodeBuffer);
	int width = (qrcodeSize + qrcodegen_border * 2) * qrcodegen_scale;
	int height = (qrcodeSize + qrcodegen_border * 2) * qrcodegen_scale;

	if (qrcodeImg) 
		delete qrcodeImg;

	qrcodeImg = new QImage(width, height, QImage::Format_RGB888);


	//3.将qrcode转成图片像素数据
	for (int y = 0; y < width; ++y)
		for (int x = 0; x < height; ++x) {
			qrcodeImg->setPixel(x, y, qrcodegen_getModule(qrArg.qrcodeBuffer, x / qrcodegen_scale - qrcodegen_border, y / qrcodegen_scale - qrcodegen_border) ? BLACK : WHITE);
		}

	QPixmap pm = QPixmap::fromImage(*qrcodeImg);

	pm.scaled(ui.labelImage->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

	ui.labelImage->setPixmap(pm);
	ui.labelMAC->setText(fatMAC);


	return;
}


void MainWindow::on_btnSave_clicked()
{
	if (nullptr == qrcodeImg || fatMAC.length() <= 0)
		return;

	char file_name[256] = { 0 };
	sprintf(file_name, "%s.jpg", fatMAC.toLocal8Bit().data());
	//qrcodeImg->save(file_name, "jpg", 100);
	QPixmap p = this->grab(QRect(25, 25, 250, 280));
	p.save(file_name, "jpg", 100);

	QString currentPath = QCoreApplication::applicationDirPath();
	ui.labelResult->setText(currentPath + '/' + file_name);
}