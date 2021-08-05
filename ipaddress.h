#ifndef IPADDRESS_H
#define IPADDRESS_H

#include <QString>
#include "types.h"
#include <bitset>

struct IPAddress
{
    IPAddress(uint8 b1,uint8 b2,uint8 b3,uint8 b4);
    IPAddress(QString ip);
    IPAddress();


    QString toString();
    uint8 bytes[4];

    static QString ipFromBitset(std::bitset<32> bs);
    static std::bitset<32> bitsetFromIp(IPAddress ip);
    static QString ipFromCidr(QString start_ip_str, int cidr);
};

#endif // IPADDRESS_H
