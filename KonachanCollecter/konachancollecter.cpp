#include "konachancollecter.h"

KonachanCollecter::KonachanCollecter(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	// 隐藏进度
	ui.label_progress->hide();
	ui.progressBar->hide();
}

KonachanCollecter::~KonachanCollecter()
{
	
}

// 查看所有tag(hyperlink)
void KonachanCollecter::on_pushButton_tags_clicked()
{
	QDesktopServices::openUrl(QUrl("https://konachan.com/tag"));
}

// 更改保存路径
void KonachanCollecter::on_pushButton_selectFolder_clicked()
{
	ui.lineEdit_folderPath->setText(QFileDialog::getExistingDirectory(nullptr, "Please select the destination folder..."));
}

// 开始任务
void KonachanCollecter::on_pushButton_start_clicked()
{
	QString tags = ui.lineEdit_tags->text();					// 源地址
	QString folderPath = ui.lineEdit_folderPath->text();		// 保存路径
	QString maxThread = ui.lineEdit_maxThread->text();		// 最大线程数

	if (tags.isEmpty() || folderPath.isEmpty() || maxThread.isEmpty())
	{
		QMessageBox::warning(this, "Error", "Null input parameter(s)!");
		return;
	}
	QDir dir;
	if (!dir.exists(folderPath) && !dir.mkdir(folderPath))
	{
		QMessageBox::warning(this, "Error", "Create directory failed!");
		return;
	}

	ui.label_progress->show();
	ui.progressBar->show();
	ui.pushButton_start->setEnabled(false);

	thread = new KonachanThread(tags, folderPath, maxThread.toInt());
	connect(thread, SIGNAL(newProgress(int, int)), this, SLOT(updateProgress(int, int)));
	thread->start();
}

// 进度回显
void KonachanCollecter::updateProgress(int value,int max)
{
	ui.label_progress->setText(QString("Downloading...(Finished: %1/%2)").arg(value).arg(max));
	ui.progressBar->setMaximum(max);
	ui.progressBar->setValue(value);

	if (value == max)
	{
		ui.label_progress->hide();
		ui.progressBar->hide();
		ui.pushButton_start->setEnabled(true);
		(value == 0) ?
			QMessageBox::warning(this, "Error", "No images matched!") :
			QMessageBox::about(this, "Done", QString("All images matched have been download!(%1/%2)").arg(value).arg(max));
	}
}


