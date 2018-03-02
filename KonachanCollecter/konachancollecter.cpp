#include "konachancollecter.h"

KonachanCollecter::KonachanCollecter(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	// 隐藏进度
	ui.label_progress->hide();
	ui.progressBar->hide();
	// 默认信息
	ui.lineEdit_tags->setPlaceholderText("6 tags at most:dress+long_hair+...");
	ui.lineEdit_folderPath->setText("D:/KonachanImages");
	ui.lineEdit_maxThread->setText("10");
	// ui信号槽
	connect(ui.pushButton_selectFolder, SIGNAL(clicked()), this, SLOT(getFolderPath()));
	connect(ui.pushButton_start, SIGNAL(clicked()), this, SLOT(sendRequest()));
}

KonachanCollecter::~KonachanCollecter()
{
	
}

// 更改保存图片的目标文件夹路径
void KonachanCollecter::getFolderPath()
{
	ui.lineEdit_folderPath->setText(QFileDialog::getExistingDirectory(nullptr, "Please select the destination folder..."));
}

// 开启工作线程
void KonachanCollecter::sendRequest()
{
	ui.label_progress->setText("Please wait for a minute...");
	ui.progressBar->setRange(0, 0);
	ui.label_progress->show();
	ui.progressBar->show();
	thread = new KonachanThread(
		(QUrl)("https://konachan.com/post?tags=" + ui.lineEdit_tags->text()),	// 源地址
		ui.lineEdit_folderPath->text(),											// 保存路径
		ui.lineEdit_maxThread->text().toInt());									// 最大线程数
	connect(thread, SIGNAL(newProgress(int, int)), this, SLOT(updateProgress(int, int)));
	thread->start();
}

// 进度回显
void KonachanCollecter::updateProgress(int value,int max)
{
	if (value == max)
	{
		ui.label_progress->hide();
		ui.progressBar->hide();
		QMessageBox::about(this, "Done", QString("All images matched have been download!(%1/%2)").arg(value).arg(max));
	}
	ui.label_progress->setText(QString("Downloading...(Finished: %1/%2)").arg(value).arg(max));
	ui.progressBar->setMaximum(max);
	ui.progressBar->setValue(value);
}


