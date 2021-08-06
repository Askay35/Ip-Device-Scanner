#ifndef SCANNER_H
#define SCANNER_H

#include "curl/curl.h"

#include "scaninput.h"
#include "ipaddress.h"
#include "table.h"
#include "device.h"

#include <thread>

#include <QStringList>
#include <QSpinBox>

class Scanner : public QObject
{
    Q_OBJECT

    bool defaultCheckCredentials(QString ip, QString port, QString login, QString password,int timeout);

    bool ftpCheckCredentials(QString ip, QString login, QString password,int timeout);

    CURL *curl;


public:
    Scanner();
    ~Scanner();

    bool checkCredentials(QString ip, QString port, QString login, QString password,int timeout);

    void scan(QStringList ips, QStringList ports, QStringList logins, QStringList passwords, int max_threads, int timeout);

signals:

    void sendRow(IPDevice device);

};

#endif // SCANNER_H
