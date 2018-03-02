/********************************************************************************
** Form generated from reading UI file 'konachancollecter.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KONACHANCOLLECTER_H
#define UI_KONACHANCOLLECTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_KonachanCollecterClass
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit_tags;
    QLineEdit *lineEdit_folderPath;
    QPushButton *pushButton_selectFolder;
    QPushButton *pushButton_start;
    QProgressBar *progressBar;
    QLabel *label_progress;
    QPushButton *pushButton_tags;
    QLineEdit *lineEdit_maxThread;
    QLabel *label_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *KonachanCollecterClass)
    {
        if (KonachanCollecterClass->objectName().isEmpty())
            KonachanCollecterClass->setObjectName(QStringLiteral("KonachanCollecterClass"));
        KonachanCollecterClass->resize(929, 292);
        centralWidget = new QWidget(KonachanCollecterClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 120, 61, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(100, 160, 61, 16));
        lineEdit_tags = new QLineEdit(centralWidget);
        lineEdit_tags->setObjectName(QStringLiteral("lineEdit_tags"));
        lineEdit_tags->setGeometry(QRect(180, 120, 451, 21));
        lineEdit_folderPath = new QLineEdit(centralWidget);
        lineEdit_folderPath->setObjectName(QStringLiteral("lineEdit_folderPath"));
        lineEdit_folderPath->setGeometry(QRect(180, 160, 451, 21));
        pushButton_selectFolder = new QPushButton(centralWidget);
        pushButton_selectFolder->setObjectName(QStringLiteral("pushButton_selectFolder"));
        pushButton_selectFolder->setGeometry(QRect(650, 160, 92, 28));
        pushButton_start = new QPushButton(centralWidget);
        pushButton_start->setObjectName(QStringLiteral("pushButton_start"));
        pushButton_start->setGeometry(QRect(760, 120, 91, 71));
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setEnabled(true);
        progressBar->setGeometry(QRect(180, 80, 451, 23));
        progressBar->setValue(24);
        progressBar->setTextVisible(true);
        label_progress = new QLabel(centralWidget);
        label_progress->setObjectName(QStringLiteral("label_progress"));
        label_progress->setGeometry(QRect(180, 50, 241, 16));
        pushButton_tags = new QPushButton(centralWidget);
        pushButton_tags->setObjectName(QStringLiteral("pushButton_tags"));
        pushButton_tags->setGeometry(QRect(650, 120, 92, 28));
        lineEdit_maxThread = new QLineEdit(centralWidget);
        lineEdit_maxThread->setObjectName(QStringLiteral("lineEdit_maxThread"));
        lineEdit_maxThread->setGeometry(QRect(180, 200, 113, 21));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(100, 200, 72, 15));
        KonachanCollecterClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(KonachanCollecterClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 929, 26));
        KonachanCollecterClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(KonachanCollecterClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        KonachanCollecterClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(KonachanCollecterClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        KonachanCollecterClass->setStatusBar(statusBar);

        retranslateUi(KonachanCollecterClass);

        QMetaObject::connectSlotsByName(KonachanCollecterClass);
    } // setupUi

    void retranslateUi(QMainWindow *KonachanCollecterClass)
    {
        KonachanCollecterClass->setWindowTitle(QApplication::translate("KonachanCollecterClass", "KonachanCollecter", 0));
        label->setText(QApplication::translate("KonachanCollecterClass", "Tag(s):", 0));
        label_2->setText(QApplication::translate("KonachanCollecterClass", "Folder:", 0));
        lineEdit_tags->setText(QString());
        pushButton_selectFolder->setText(QApplication::translate("KonachanCollecterClass", "Select", 0));
        pushButton_start->setText(QApplication::translate("KonachanCollecterClass", "Start", 0));
        label_progress->setText(QApplication::translate("KonachanCollecterClass", "Please wait for a minute...", 0));
        pushButton_tags->setText(QApplication::translate("KonachanCollecterClass", "All tags", 0));
        label_3->setText(QApplication::translate("KonachanCollecterClass", "Threads:", 0));
    } // retranslateUi

};

namespace Ui {
    class KonachanCollecterClass: public Ui_KonachanCollecterClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KONACHANCOLLECTER_H
