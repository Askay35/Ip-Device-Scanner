#ifndef SCANNER_H
#define SCANNER_H

#include "scaninput.h"
#include "ipaddress.h"
#include "curl/curl.h"
#include <QStringList>

class Scanner
{

    bool ftpCheckCredentials(QString ip, QString login, QString password);

    CURL *curl;
public:
    Scanner();
    ~Scanner();

    bool checkCredentials(QString ip, QString port, QString login, QString password);

    void scan(QStringList ips, QStringList ports, QStringList logins, QStringList passwords);


};

#endif // SCANNER_H
