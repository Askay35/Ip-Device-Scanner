#include "table.h"

Table::Table()
{

}

void Table::addRow(IPDevice device)
{
    this->table->insertRow(table->rowCount());
    QTableWidgetItem *ipitem = new QTableWidgetItem(device.ip);
    QTableWidgetItem *portitem = new QTableWidgetItem(device.port);
    QTableWidgetItem *timeitem = new QTableWidgetItem(device.time);
    QTableWidgetItem *authitem = new QTableWidgetItem(device.auth);

    ipitem->setTextAlignment(Qt::AlignCenter);
    portitem->setTextAlignment(Qt::AlignCenter);
    timeitem->setTextAlignment(Qt::AlignCenter);
    authitem->setTextAlignment(Qt::AlignCenter);

    this->table->setItem(table->rowCount()-1, 0, ipitem);
    this->table->setItem(table->rowCount()-1, 1, portitem);
    this->table->setItem(table->rowCount()-1, 2, timeitem);
    this->table->setItem(table->rowCount()-1, 3, authitem);
}

