#ifndef KONACHANCOLLECTER_H
#define KONACHANCOLLECTER_H

#include <QtWidgets/QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QDir>
#include <QDesktopServices>
#include <unordered_map>
#include "ui_konachancollecter.h"
#include "poolmanager.h"
class KonachanCollecter : public QMainWindow
{
	Q_OBJECT

public:
	KonachanCollecter(QWidget *parent = 0);
	~KonachanCollecter();

	public slots:
	void on_pushButton_tags_clicked();
	void on_pushButton_selectFolder_clicked();
	void on_pushButton_start_clicked();
	void update_progress(QString progress);

private:
	Ui::KonachanCollecterClass ui;
	QThread worker_thread_;
	// possible keys:"new" "dup" "done" "todo"
	std::unordered_map<std::string, int> progress_map_;
};
#endif // KONACHANCOLLECTER_H
