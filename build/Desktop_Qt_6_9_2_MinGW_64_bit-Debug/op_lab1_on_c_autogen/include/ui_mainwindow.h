/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *beginTextLabel;
    QLineEdit *inputLineEdit;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *beginBaseComboBox;
    QComboBox *lastBaseComboBox;
    QPushButton *convertButton;
    QPushButton *SwapPushButton;
    QLabel *resultTextLabel;
    QLineEdit *outputLineEdit;
    QPushButton *copyButton;
    QLabel *errorTextLabel;
    QLabel *showErrorLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(468, 533);
        QFont font;
        font.setPointSize(12);
        MainWindow->setFont(font);
        MainWindow->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        MainWindow->setStyleSheet(QString::fromUtf8("widget->setStyleSheet(\"background-color: #f0f0f0;\");"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        beginTextLabel = new QLabel(centralwidget);
        beginTextLabel->setObjectName("beginTextLabel");
        beginTextLabel->setBaseSize(QSize(0, 0));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Times New Roman")});
        font1.setPointSize(14);
        beginTextLabel->setFont(font1);
        beginTextLabel->setLayoutDirection(Qt::LayoutDirection::LeftToRight);

        verticalLayout->addWidget(beginTextLabel);

        inputLineEdit = new QLineEdit(centralwidget);
        inputLineEdit->setObjectName("inputLineEdit");

        verticalLayout->addWidget(inputLineEdit);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        beginBaseComboBox = new QComboBox(centralwidget);
        beginBaseComboBox->addItem(QString());
        beginBaseComboBox->addItem(QString());
        beginBaseComboBox->addItem(QString());
        beginBaseComboBox->setObjectName("beginBaseComboBox");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Times New Roman")});
        font2.setPointSize(12);
        beginBaseComboBox->setFont(font2);
        beginBaseComboBox->setLayoutDirection(Qt::LayoutDirection::LeftToRight);

        horizontalLayout_3->addWidget(beginBaseComboBox);

        lastBaseComboBox = new QComboBox(centralwidget);
        lastBaseComboBox->addItem(QString());
        lastBaseComboBox->addItem(QString());
        lastBaseComboBox->addItem(QString());
        lastBaseComboBox->setObjectName("lastBaseComboBox");
        lastBaseComboBox->setFont(font2);

        horizontalLayout_3->addWidget(lastBaseComboBox);


        verticalLayout->addLayout(horizontalLayout_3);

        convertButton = new QPushButton(centralwidget);
        convertButton->setObjectName("convertButton");
        convertButton->setMinimumSize(QSize(350, 0));
        convertButton->setFont(font2);

        verticalLayout->addWidget(convertButton);

        SwapPushButton = new QPushButton(centralwidget);
        SwapPushButton->setObjectName("SwapPushButton");
        SwapPushButton->setFont(font2);

        verticalLayout->addWidget(SwapPushButton);

        resultTextLabel = new QLabel(centralwidget);
        resultTextLabel->setObjectName("resultTextLabel");
        resultTextLabel->setFont(font1);

        verticalLayout->addWidget(resultTextLabel);

        outputLineEdit = new QLineEdit(centralwidget);
        outputLineEdit->setObjectName("outputLineEdit");
        outputLineEdit->setFont(font1);

        verticalLayout->addWidget(outputLineEdit);

        copyButton = new QPushButton(centralwidget);
        copyButton->setObjectName("copyButton");
        copyButton->setMaximumSize(QSize(16777215, 16777215));
        copyButton->setFont(font2);

        verticalLayout->addWidget(copyButton);

        errorTextLabel = new QLabel(centralwidget);
        errorTextLabel->setObjectName("errorTextLabel");
        errorTextLabel->setFont(font1);

        verticalLayout->addWidget(errorTextLabel);

        showErrorLabel = new QLabel(centralwidget);
        showErrorLabel->setObjectName("showErrorLabel");
        showErrorLabel->setMaximumSize(QSize(16777215, 40));
        showErrorLabel->setFont(font1);
        showErrorLabel->setAutoFillBackground(false);
        showErrorLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 36, 36); \n"
"color: rgb(255, 0, 0);"));
        showErrorLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(showErrorLabel);


        horizontalLayout->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 468, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Converter", nullptr));
        beginTextLabel->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\207\320\270\321\201\320\273\320\276:", nullptr));
        beginBaseComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "2", nullptr));
        beginBaseComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "10", nullptr));
        beginBaseComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "16", nullptr));

        lastBaseComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "2", nullptr));
        lastBaseComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "10", nullptr));
        lastBaseComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "16", nullptr));

        convertButton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\262\320\265\321\201\321\202\320\270", nullptr));
        SwapPushButton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\274\320\265\320\275\321\217\321\202\321\214 ", nullptr));
        resultTextLabel->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202:", nullptr));
        copyButton->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\277\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        errorTextLabel->setText(QCoreApplication::translate("MainWindow", "\320\236\321\210\320\270\320\261\320\272\320\270:", nullptr));
        showErrorLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
