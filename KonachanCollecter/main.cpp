#include "konachancollecter.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{// TODO: 加个日志
	QApplication a(argc, argv);
	KonachanCollecter w;
	w.show();
	return a.exec();
}
