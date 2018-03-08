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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_KonachanCollecterClass
{
public:
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_2;
    QProgressBar *progressBar;
    QLineEdit *lineEdit_tags;
    QLabel *label_progress;
    QPushButton *pushButton_selectFolder;
    QLineEdit *lineEdit_folderPath;
    QLineEdit *lineEdit_maxThread;
    QPushButton *pushButton_tags;
    QPushButton *pushButton_start;

    void setupUi(QMainWindow *KonachanCollecterClass)
    {
        if (KonachanCollecterClass->objectName().isEmpty())
            KonachanCollecterClass->setObjectName(QStringLiteral("KonachanCollecterClass"));
        KonachanCollecterClass->resize(1000, 250);
        KonachanCollecterClass->setMinimumSize(QSize(1000, 250));
        KonachanCollecterClass->setMaximumSize(QSize(1000, 250));
        QFont font;
        font.setFamily(QStringLiteral("Kristen ITC"));
        KonachanCollecterClass->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/konachan.ico"), QSize(), QIcon::Normal, QIcon::Off);
        KonachanCollecterClass->setWindowIcon(icon);
        KonachanCollecterClass->setStyleSheet(QStringLiteral("background-color: rgb(240, 240, 220);"));
        centralWidget = new QWidget(KonachanCollecterClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(60, 30, 881, 181));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 7, 0, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 3, 0, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 6, 0, 1, 1);

        progressBar = new QProgressBar(gridLayoutWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setEnabled(true);
        progressBar->setFont(font);
        progressBar->setStyleSheet(QStringLiteral("color: rgb(55, 200, 11);"));
        progressBar->setMaximum(0);
        progressBar->setValue(0);
        progressBar->setTextVisible(true);

        gridLayout->addWidget(progressBar, 1, 1, 1, 1);

        lineEdit_tags = new QLineEdit(gridLayoutWidget);
        lineEdit_tags->setObjectName(QStringLiteral("lineEdit_tags"));
        lineEdit_tags->setFont(font);

        gridLayout->addWidget(lineEdit_tags, 3, 1, 1, 1);

        label_progress = new QLabel(gridLayoutWidget);
        label_progress->setObjectName(QStringLiteral("label_progress"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_progress->sizePolicy().hasHeightForWidth());
        label_progress->setSizePolicy(sizePolicy);
        label_progress->setMaximumSize(QSize(16777215, 16777215));
        QFont font1;
        font1.setFamily(QStringLiteral("Kristen ITC"));
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        label_progress->setFont(font1);

        gridLayout->addWidget(label_progress, 0, 1, 1, 1);

        pushButton_selectFolder = new QPushButton(gridLayoutWidget);
        pushButton_selectFolder->setObjectName(QStringLiteral("pushButton_selectFolder"));
        pushButton_selectFolder->setFont(font);

        gridLayout->addWidget(pushButton_selectFolder, 6, 2, 1, 1);

        lineEdit_folderPath = new QLineEdit(gridLayoutWidget);
        lineEdit_folderPath->setObjectName(QStringLiteral("lineEdit_folderPath"));
        lineEdit_folderPath->setFont(font);
        lineEdit_folderPath->setReadOnly(true);

        gridLayout->addWidget(lineEdit_folderPath, 6, 1, 1, 1);

        lineEdit_maxThread = new QLineEdit(gridLayoutWidget);
        lineEdit_maxThread->setObjectName(QStringLiteral("lineEdit_maxThread"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit_maxThread->sizePolicy().hasHeightForWidth());
        lineEdit_maxThread->setSizePolicy(sizePolicy1);
        lineEdit_maxThread->setFont(font);

        gridLayout->addWidget(lineEdit_maxThread, 7, 1, 1, 1);

        pushButton_tags = new QPushButton(gridLayoutWidget);
        pushButton_tags->setObjectName(QStringLiteral("pushButton_tags"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_tags->sizePolicy().hasHeightForWidth());
        pushButton_tags->setSizePolicy(sizePolicy2);
        pushButton_tags->setFont(font);

        gridLayout->addWidget(pushButton_tags, 3, 2, 1, 1);

        pushButton_start = new QPushButton(gridLayoutWidget);
        pushButton_start->setObjectName(QStringLiteral("pushButton_start"));
        pushButton_start->setFont(font);

        gridLayout->addWidget(pushButton_start, 7, 2, 1, 1);

        KonachanCollecterClass->setCentralWidget(centralWidget);

        retranslateUi(KonachanCollecterClass);

        QMetaObject::connectSlotsByName(KonachanCollecterClass);
    } // setupUi

    void retranslateUi(QMainWindow *KonachanCollecterClass)
    {
        KonachanCollecterClass->setWindowTitle(QApplication::translate("KonachanCollecterClass", "KonachanCollecter", 0));
        label_3->setText(QApplication::translate("KonachanCollecterClass", "Threads:", 0));
        label->setText(QApplication::translate("KonachanCollecterClass", "Tag(s):", 0));
        label_2->setText(QApplication::translate("KonachanCollecterClass", "Folder:", 0));
        lineEdit_tags->setText(QString());
        lineEdit_tags->setPlaceholderText(QApplication::translate("KonachanCollecterClass", "6 tags at most like :dress long_hair ... more tags refer to \"All tags\"", 0));
        label_progress->setText(QApplication::translate("KonachanCollecterClass", "Please wait for a minute...", 0));
        pushButton_selectFolder->setText(QApplication::translate("KonachanCollecterClass", "Select", 0));
        lineEdit_folderPath->setText(QApplication::translate("KonachanCollecterClass", "D:/KonachanImages", 0));
#ifndef QT_NO_TOOLTIP
        lineEdit_maxThread->setToolTip(QApplication::translate("KonachanCollecterClass", "tooltip", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        lineEdit_maxThread->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        lineEdit_maxThread->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_ACCESSIBILITY
        lineEdit_maxThread->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
#ifndef QT_NO_ACCESSIBILITY
        lineEdit_maxThread->setAccessibleDescription(QString());
#endif // QT_NO_ACCESSIBILITY
        lineEdit_maxThread->setInputMask(QApplication::translate("KonachanCollecterClass", "D9", 0));
        lineEdit_maxThread->setText(QString());
        lineEdit_maxThread->setPlaceholderText(QApplication::translate("KonachanCollecterClass", "10 by default and no more than 30 threads is suggested :otherwise you may be blocked", 0));
        pushButton_tags->setText(QApplication::translate("KonachanCollecterClass", "All tags", 0));
        pushButton_start->setText(QApplication::translate("KonachanCollecterClass", "Start", 0));
    } // retranslateUi

};

namespace Ui {
    class KonachanCollecterClass: public Ui_KonachanCollecterClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KONACHANCOLLECTER_H
