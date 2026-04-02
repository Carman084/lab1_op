#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
extern "C" {
#include "entrypoint.h"
#include "logic.h"
#include "validator.h"
}

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    AppContext context;
    void updateUi();
    void onConvertButtonClicked();
    QString writeErrorStr(Status error);
    void onCopyButtonClicked();
    void onBeginBaseComboBoxClicked();
    void onLastBaseComboBoxClicked();
    void onInputLineEditClicked();
    void copyResultToClipboard(const QString &text);
    void swapComboBox();
};
#endif // MAINWINDOW_H
