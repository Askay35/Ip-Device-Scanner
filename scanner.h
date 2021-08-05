#ifndef SCANNER_H
#define SCANNER_H

#include "scaninput.h"
#include "ipaddress.h"
#include <QStringList>

class Scanner
{
public:
    Scanner();

    void scan(QStringList ips, QStringList ports);
};

#endif // SCANNER_H
