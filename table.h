#ifndef TABLE_H
#define TABLE_H

#include <QTableWidget>

class Table : public QObject
{
    Q_OBJECT
public:
    Table();

    QTableWidget *table;

    void addRow(QString ip="", QString port="", QString time="", QString auth="", QString server_name="", QString bssid="");

};

#endif // TABLE_H
