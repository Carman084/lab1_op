#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QClipboard>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lastBaseComboBox->setCurrentIndex(1);
    ui->outputLineEdit->setReadOnly(true);
    initContext(&context);

    connect(ui->convertButton, &QPushButton::clicked, this, &MainWindow::onConvertButtonClicked);
    connect(ui->copyButton, &QPushButton::clicked, this, &MainWindow::onCopyButtonClicked);
    connect(ui->inputLineEdit, &QLineEdit::textChanged, this, &MainWindow::onInputLineEditClicked);
    connect(ui->beginBaseComboBox, &QComboBox::currentIndexChanged, this, &MainWindow::onBeginBaseComboBoxClicked);
    connect(ui->lastBaseComboBox, &QComboBox::currentIndexChanged, this, &MainWindow::onLastBaseComboBoxClicked);
    connect(ui->outputLineEdit, &QLineEdit::textChanged, this, &MainWindow::copyResultToClipboard);
    connect(ui->SwapPushButton, &QPushButton::clicked, this, &MainWindow::swapComboBox);
    connect(ui->SwapPushButton, &QPushButton::clicked, this, &MainWindow::onConvertButtonClicked);
}

MainWindow::~MainWindow()
{
    freeContext(&context);
    delete ui;
}


void MainWindow::onConvertButtonClicked(){
    doOperation(CHECK_ERROR, &context, NULL);
    if (context.status == OK)
        doOperation(CONVERT, &context, NULL);
    updateUi();
}

QString MainWindow::writeErrorStr(Status error){
    QString str;
    switch(error){
    case Status::OK:
        str = "";
        break;
    case Status::ERROR_EMPTY_INPUT:
        str = "Не введено исходное число";
        break;
    case Status::ERROR_INVALID_SYMBOL:
        str = "Введён некорректный символ/символы";
        break;
    case Status::ERROR_MEMORY:
        str = "Не хватает памяти";
        break;
    case Status::ERROR_OUT_OF_RANGE:
        str = "Выход за пределы диапазона числа";
        break;
    }
    return str;
}

void MainWindow::updateUi(){
    ui->showErrorLabel->setText(writeErrorStr(context.status));
    if (context.status != OK)
        ui->outputLineEdit->setText("");
    else
        ui->outputLineEdit->setText(context.output);
}

void MainWindow::onBeginBaseComboBoxClicked(){
    AppParams params;
    params.sourceBase = (Base)ui->beginBaseComboBox->currentText().toInt();
    doOperation(UPDATE_SOURCE_BASE, &context, &params);
}

void MainWindow::onLastBaseComboBoxClicked(){
    AppParams params;
    params.lastBase = (Base)ui->lastBaseComboBox->currentText().toInt();
    doOperation(UPDATE_LAST_BASE, &context, &params);
}

void MainWindow::onInputLineEditClicked(){
    AppParams params;
    std::string str = ui->inputLineEdit->text().toStdString();
    params.input = str.c_str();
    doOperation(UPDATE_INPUT, &context, &params);
    ui->inputLineEdit->setText(context.input);
}

void MainWindow::onCopyButtonClicked(){
    if (context.status == OK && context.output && *context.output){
        QClipboard* clipboard = QApplication::clipboard();
        clipboard->setText(context.output);
    }
}

void MainWindow::copyResultToClipboard(const QString &text){
    if (!text.isEmpty()) {
        QClipboard* clipboard = QApplication::clipboard();
        clipboard->setText(text);
    }
}

void MainWindow::swapComboBox() {
    int idx1 = ui->beginBaseComboBox->currentIndex();
    int idx2 = ui->lastBaseComboBox->currentIndex();
    std::string str = ui->outputLineEdit->text().toStdString();
    ui->beginBaseComboBox->setCurrentIndex(idx2);
    ui->lastBaseComboBox->setCurrentIndex(idx1);
    ui->inputLineEdit->setText(str.c_str());
}
