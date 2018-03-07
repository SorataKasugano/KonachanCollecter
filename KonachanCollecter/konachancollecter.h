#ifndef KONACHANCOLLECTER_H
#define KONACHANCOLLECTER_H

#include <QtWidgets/QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QDir>
#include <QDesktopServices>
#include "ui_konachancollecter.h"
#include "konachanthread.h"
class KonachanCollecter : public QMainWindow
{
	Q_OBJECT

public:
	KonachanCollecter(QWidget *parent = 0);
	~KonachanCollecter();

	public slots:
	void hyperlink();
	void changeFolderPath();
	void startMisson();
	void updateProgress(int, int);

private:
	Ui::KonachanCollecterClass ui;
	KonachanThread* thread;// �����߳�
};
#endif // KONACHANCOLLECTER_H
