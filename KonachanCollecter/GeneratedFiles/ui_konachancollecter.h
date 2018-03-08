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
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QPushButton *pushButton_selectFolder;
    QLabel *label_2;
    QLabel *label;
    QLineEdit *lineEdit_folderPath;
    QLineEdit *lineEdit_tags;
    QLabel *label_progress;
    QLineEdit *lineEdit_maxThread;
    QPushButton *pushButton_start;
    QProgressBar *progressBar;
    QLabel *label_3;
    QPushButton *pushButton_tags;

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
        KonachanCollecterClass->setStyleSheet(QStringLiteral("background-image: url(:/bottom.jpg);"));
        centralWidget = new QWidget(KonachanCollecterClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(50, 0, 50, 0);
        pushButton_selectFolder = new QPushButton(centralWidget);
        pushButton_selectFolder->setObjectName(QStringLiteral("pushButton_selectFolder"));
        pushButton_selectFolder->setFont(font);
        pushButton_selectFolder->setStyleSheet(QLatin1String("background-image: url();\n"
"background-color: rgba(255, 255, 255, 100);"));

        gridLayout->addWidget(pushButton_selectFolder, 8, 2, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);
        label_2->setStyleSheet(QStringLiteral("background-image: url();"));

        gridLayout->addWidget(label_2, 8, 0, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("background-image: url();"));

        gridLayout->addWidget(label, 5, 0, 1, 1);

        lineEdit_folderPath = new QLineEdit(centralWidget);
        lineEdit_folderPath->setObjectName(QStringLiteral("lineEdit_folderPath"));
        lineEdit_folderPath->setFont(font);
        lineEdit_folderPath->setStyleSheet(QLatin1String("background-image: url();\n"
"background-color: rgba(255, 255, 255, 100);"));
        lineEdit_folderPath->setReadOnly(true);

        gridLayout->addWidget(lineEdit_folderPath, 8, 1, 1, 1);

        lineEdit_tags = new QLineEdit(centralWidget);
        lineEdit_tags->setObjectName(QStringLiteral("lineEdit_tags"));
        lineEdit_tags->setFont(font);
        lineEdit_tags->setStyleSheet(QLatin1String("background-image: url();\n"
"background-color: rgba(255, 255, 255, 100);"));

        gridLayout->addWidget(lineEdit_tags, 5, 1, 1, 1);

        label_progress = new QLabel(centralWidget);
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
        label_progress->setStyleSheet(QLatin1String("color: rgba(0,0,0,180);\n"
"background-image: url();"));

        gridLayout->addWidget(label_progress, 1, 1, 1, 1);

        lineEdit_maxThread = new QLineEdit(centralWidget);
        lineEdit_maxThread->setObjectName(QStringLiteral("lineEdit_maxThread"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit_maxThread->sizePolicy().hasHeightForWidth());
        lineEdit_maxThread->setSizePolicy(sizePolicy1);
        lineEdit_maxThread->setFont(font);
        lineEdit_maxThread->setStyleSheet(QLatin1String("background-image: url();\n"
"background-color: rgba(255, 255, 255, 100);"));

        gridLayout->addWidget(lineEdit_maxThread, 9, 1, 1, 1);

        pushButton_start = new QPushButton(centralWidget);
        pushButton_start->setObjectName(QStringLiteral("pushButton_start"));
        pushButton_start->setFont(font);
        pushButton_start->setStyleSheet(QLatin1String("background-image: url();\n"
"background-color: rgba(255, 255, 255, 100);"));

        gridLayout->addWidget(pushButton_start, 9, 2, 1, 1);

        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setEnabled(true);
        QFont font2;
        font2.setFamily(QStringLiteral("Kristen ITC"));
        font2.setBold(true);
        font2.setWeight(75);
        progressBar->setFont(font2);
        progressBar->setLayoutDirection(Qt::LeftToRight);
        progressBar->setStyleSheet(QLatin1String("QProgressBar {\n"
"   color: rgba(0,0,0,150);\n"
"   text-align: right;\n"
"   border: 1px solid white;\n"
"   background-image: url();\n"
"   background-color: rgba(255,255,255,200);\n"
"}\n"
" \n"
"QProgressBar::chunk {\n"
"   background-color: rgba(210,210,210,255);\n"
"}"));
        progressBar->setMaximum(0);
        progressBar->setValue(0);
        progressBar->setTextVisible(true);

        gridLayout->addWidget(progressBar, 3, 1, 1, 1);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);
        label_3->setStyleSheet(QStringLiteral("background-image: url();"));

        gridLayout->addWidget(label_3, 9, 0, 1, 1);

        pushButton_tags = new QPushButton(centralWidget);
        pushButton_tags->setObjectName(QStringLiteral("pushButton_tags"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_tags->sizePolicy().hasHeightForWidth());
        pushButton_tags->setSizePolicy(sizePolicy2);
        pushButton_tags->setFont(font);
        pushButton_tags->setStyleSheet(QLatin1String("background-image: url();\n"
"background-color: rgba(255, 255, 255, 100);"));

        gridLayout->addWidget(pushButton_tags, 5, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        KonachanCollecterClass->setCentralWidget(centralWidget);

        retranslateUi(KonachanCollecterClass);

        QMetaObject::connectSlotsByName(KonachanCollecterClass);
    } // setupUi

    void retranslateUi(QMainWindow *KonachanCollecterClass)
    {
        KonachanCollecterClass->setWindowTitle(QApplication::translate("KonachanCollecterClass", "KonachanCollecter", 0));
        pushButton_selectFolder->setText(QApplication::translate("KonachanCollecterClass", "Select", 0));
        label_2->setText(QApplication::translate("KonachanCollecterClass", "Folder:", 0));
        label->setText(QApplication::translate("KonachanCollecterClass", "Tag(s):", 0));
        lineEdit_folderPath->setText(QApplication::translate("KonachanCollecterClass", "D:/KonachanImages", 0));
        lineEdit_tags->setText(QString());
        lineEdit_tags->setPlaceholderText(QApplication::translate("KonachanCollecterClass", "6 tags at most like :dress long_hair ... more tags refer to \"All tags\"", 0));
        label_progress->setText(QApplication::translate("KonachanCollecterClass", "Please wait for a minute...", 0));
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
        lineEdit_maxThread->setText(QApplication::translate("KonachanCollecterClass", "10", 0));
        lineEdit_maxThread->setPlaceholderText(QApplication::translate("KonachanCollecterClass", "10 by default and no more than 30 threads is suggested :otherwise you may be blocked", 0));
        pushButton_start->setText(QApplication::translate("KonachanCollecterClass", "Start", 0));
        label_3->setText(QApplication::translate("KonachanCollecterClass", "Threads:", 0));
        pushButton_tags->setText(QApplication::translate("KonachanCollecterClass", "All tags", 0));
    } // retranslateUi

};

namespace Ui {
    class KonachanCollecterClass: public Ui_KonachanCollecterClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KONACHANCOLLECTER_H
