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
	dup_ = done_ = sum_ = 0;
	QString tags = ui.lineEdit_tags->text();					// 源地址
	QString folder_path = ui.lineEdit_folderPath->text();		// 保存路径
	QString max_thread = ui.lineEdit_maxThread->text();		// 最大线程数

	if (tags.isEmpty() || folder_path.isEmpty() || max_thread.isEmpty())
	{
		QMessageBox::warning(this, "Error", "Null input parameter(s)!");
		return;
	}
	QDir dir;
	if (!dir.exists(folder_path) && !dir.mkdir(folder_path))
	{
		QMessageBox::warning(this, "Error", "Create directory failed!");
		return;
	}

	ui.label_progress->setText("Please wait for a minute...");
	ui.progressBar->setMaximum(0);
	ui.label_progress->show();
	ui.progressBar->show();
	ui.pushButton_start->setEnabled(false);

	PoolManager* manager = new PoolManager(folder_path, max_thread.toInt());
	manager->moveToThread(&worker_thread_);
	connect(manager, &PoolManager::new_progress, this, &KonachanCollecter::update_progress);
	worker_thread_.start();
	manager->add_new_task("https://konachan.com/post?tags=" + tags);
}

// 进度回显
void KonachanCollecter::update_progress(QString progress)
{
	if (progress == "none")
	{
		ui.label_progress->hide();
		ui.progressBar->hide();
		ui.pushButton_start->setEnabled(true);
		QMessageBox::warning(this, "Error", "No images matched!");
		return;
	}
	else if (progress == "todo") sum_++;
	else if (progress == "done") done_++;
	else if (progress == "dup") dup_++;
	ui.label_progress->setText(QString("Downloading...[%1/%2 new:%3 dup:%4]").arg(done_+dup_).arg(sum_).arg(done_).arg(dup_));
	ui.progressBar->setMaximum(sum_);
	ui.progressBar->setValue(done_);
	// TODO:全部重复如何处理？统计本地图片数量？
	if ((done_ + dup_ == sum_) && (done_ != 0))
	{
		ui.label_progress->hide();
		ui.progressBar->hide();
		ui.pushButton_start->setEnabled(true);
		QMessageBox::about(this, "Congratulations!", QString("All images done.[%1/%2 new:%3]").arg(done_ + dup_).arg(sum_).arg(done_));
	}
}


