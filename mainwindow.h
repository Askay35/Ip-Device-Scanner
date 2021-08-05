#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "port.h"
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
    Table table;
    AuthInput authinput;
    ScanInput scaninput;

private slots:
    void clearResults();
    void clearLog();

    void exportLog();
    void exportResults();

    void start();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H