#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "device.h"
#include <QMainWindow>
#include "port.h"
#include "scanner.h"
#include "scaninput.h"
#include "authinput.h"
#include "table.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Scanner scanner;
    Table table;
    AuthInput authinput;
    ScanInput scaninput;

private:
    bool state;

private:
    void start();
    void stop();

private:
    std::thread scan_thread;

private slots:

    void stateChanged(bool work);

    void clearResults();
    void clearLog();


    void exportLog();
    void exportResults();


    void startClick();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
