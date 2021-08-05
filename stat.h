#ifndef STAT_H
#define STAT_H

#include <QLabel>

class Stat : public QObject
{
    Q_OBJECT
public:
    Stat();

    QLabel *ips_count;
    QLabel *ports_count;
    QLabel *good_count;
    QLabel *logins_count;
    QLabel *passwords_count;
public slots:
    void setIpsCount(int c);

};

#endif // STAT_H

//alxndr1_test
//Test_123
