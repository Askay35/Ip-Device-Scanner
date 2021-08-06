#ifndef DEVICE_H
#define DEVICE_H

#include <QString>

struct IPDevice{
    QString ip;
    QString port;
    QString time;//time in ms
    QString auth;//login:password
};

#endif // DEVICE_H
