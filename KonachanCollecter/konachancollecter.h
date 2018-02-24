#ifndef KONACHANCOLLECTER_H
#define KONACHANCOLLECTER_H

#include <QtWidgets/QMainWindow>
#include "ui_konachancollecter.h"

class KonachanCollecter : public QMainWindow
{
	Q_OBJECT

public:
	KonachanCollecter(QWidget *parent = 0);
	~KonachanCollecter();

private:
	Ui::KonachanCollecterClass ui;
};

#endif // KONACHANCOLLECTER_H
