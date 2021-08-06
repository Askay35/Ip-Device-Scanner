#ifndef TABLE_H
#define TABLE_H

#include "device.h"
#include <QTableWidget>

class Table : public QObject
{
    Q_OBJECT
public:
    Table();

    QTableWidget *table;

public slots:
    void addRow(IPDevice device);

};

#endif // TABLE_H
