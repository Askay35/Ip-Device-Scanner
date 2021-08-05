#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "log.h"
#include "port.h"
#include "progress.h"
#include "ipaddress.h"
#include <QFileDialog>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->authinput.logins_input = ui->loginsInput;
    this->authinput.passwords_input = ui->passwordsInput;

    this->scaninput.ips_input = ui->ipRangesInput;
    this->scaninput.ports_input= ui->portsInput;

    this->table.table = ui->resultTable;

    connect(ui->startBtn, SIGNAL(clicked()), SLOT(start()));

    connect(ui->addLoginsBtn, SIGNAL(clicked()), &authinput, SLOT(addLogins()));
    connect(ui->addIpsBtn, SIGNAL(clicked()),&scaninput, SLOT(addIps()));
    connect(ui->addPasswordsBtn, SIGNAL(clicked()), &authinput, SLOT(addPasswords()));
    connect(ui->addPortsBtn, SIGNAL(clicked()),&scaninput, SLOT(addPorts()));


    connect(ui->erasePortsBtn, SIGNAL(clicked()), &scaninput, SLOT(erasePorts()));
    connect(ui->eraseLoginsBtn, SIGNAL(clicked()), &authinput, SLOT(eraseLogins()));
    connect(ui->eraseIpsBtn, SIGNAL(clicked()), &scaninput, SLOT(eraseIps()));
    connect(ui->clearLogBtn, SIGNAL(clicked()), SLOT(clearLog()));
    connect(ui->erasePasswordsBtn, SIGNAL(clicked()),&authinput, SLOT(erasePasswords()));
    connect(ui->clearResultsBtn, SIGNAL(clicked()), SLOT(clearResults()));

    connect(ui->exportLogBtn, SIGNAL(clicked()), SLOT(exportLog()));
    connect(ui->exportResultsBtn, SIGNAL(clicked()), SLOT(exportResults()));


    //alxndr1_test
    //Test_123


    QHeaderView *vh = table.table->verticalHeader();
    vh->setSectionResizeMode(QHeaderView::Fixed);
    vh->setDefaultSectionSize(12);

    ProgressBar::pb = ui->progressBar;

    Log::log_checkbox = ui->logCheckBox;
    Log::log_field = ui->logField;
    Log::autoscroll_checkbox = ui->autoScrollCheckBox;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::clearResults()
{
    ui->resultTable->setRowCount(0);
    Log::appendLogs("Results cleared");
}

void MainWindow::clearLog()
{
    ui->logField->clear();
}

void MainWindow::start()
{
    bool res =scanner.checkCredentials("alxndr1.beget.tech", "21", "test", "test");
    if(res){
        Log::appendLogs("success");
    }
    else{
        Log::appendLogs("fail");
    }
    //Log::appendLogs("Scan started");
    //QStringList ips = scaninput.getIps();
    //if(ips.empty()){
    //    Log::appendLogs("No IP's specified");
    //    return;
    //}
    //
    //Log::appendLogs("IP ranges OK");
    //QStringList ports = scaninput.getPorts();
    //if(ports.empty()){
    //    Log::appendLogs("No ports specified");
    //    return;
    //}
    //
    //Log::appendLogs("Ports OK");
    //QStringList logins = authinput.getLogins();
    //if(logins.empty()){
    //    Log::appendLogs("No logins specified");
    //    return;
    //}
    //
    //Log::appendLogs("Logins OK");
    //QStringList passwords = authinput.getPasswords();
    //if(passwords.empty()){
    //    Log::appendLogs("No passwords specified");
    //    return;
    //}
    //
    //Log::appendLogs("Passwords OK");


}

void MainWindow::exportResults()
{
    table.addRow("ip","port","time", "auth", "sname", "bssid");
    Log::appendLogs("Results exported");
}

void MainWindow::exportLog()
{
    Log::exportLogs();
    Log::appendLogs("Logs exported");
}
