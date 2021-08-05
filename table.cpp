#include "table.h"

Table::Table()
{

}

void Table::addRow(QString ip, QString port, QString time,  QString auth,QString server_name, QString bssid)
{
    this->table->insertRow(table->rowCount());
    QTableWidgetItem *ipitem = new QTableWidgetItem(ip);
    QTableWidgetItem *portitem = new QTableWidgetItem(port);
    QTableWidgetItem *timeitem = new QTableWidgetItem(time);
    QTableWidgetItem *authitem = new QTableWidgetItem(auth);
    QTableWidgetItem *snameitem = new QTableWidgetItem(server_name);
    QTableWidgetItem *bssiditem = new QTableWidgetItem(bssid);

    ipitem->setTextAlignment(Qt::AlignCenter);
    portitem->setTextAlignment(Qt::AlignCenter);
    timeitem->setTextAlignment(Qt::AlignCenter);
    authitem->setTextAlignment(Qt::AlignCenter);
    snameitem->setTextAlignment(Qt::AlignCenter);
    bssiditem->setTextAlignment(Qt::AlignCenter);

    this->table->setItem(table->rowCount()-1, 0, ipitem);
    this->table->setItem(table->rowCount()-1, 1, portitem);
    this->table->setItem(table->rowCount()-1, 2, timeitem);
    this->table->setItem(table->rowCount()-1, 3, authitem);
    this->table->setItem(table->rowCount()-1, 4, snameitem);
    this->table->setItem(table->rowCount()-1, 5, bssiditem);
}

