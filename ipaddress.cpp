#include "ipaddress.h"
#include <QTextStream>

IPAddress::IPAddress()
{

}

IPAddress::IPAddress(uint8 b1, uint8 b2, uint8 b3, uint8 b4)
{
    this->bytes[0] = b1;
    this->bytes[1] = b2;
    this->bytes[2] = b3;
    this->bytes[3] = b4;
}

IPAddress::IPAddress(QString ip)
{
    QStringList ipparts = ip.split(".");
    this->bytes[0]=ipparts[0].toInt();
    this->bytes[1]=ipparts[1].toInt();
    this->bytes[2]=ipparts[2].toInt();
    this->bytes[3]=ipparts[3].toInt();
}

QString IPAddress::toString()
{
    QString addr;
    QTextStream(&addr) << bytes[0] << "." << bytes[1] << "." << bytes[2] << "." << bytes[3];
    return addr;
}

QString IPAddress::ipFromBitset(std::bitset<32> bs)
{
    QString ip;
    uint8 bytes[4];
    for (int i = 3; i > -1; i--) {
        std::bitset<8> ibs;
        ibs[0]=bs[0];
        ibs[1]=bs[1];
        ibs[2]=bs[2];
        ibs[3]=bs[3];
        ibs[4]=bs[4];
        ibs[5]=bs[5];
        ibs[6]=bs[6];
        ibs[7]=bs[7];
        bytes[i] = ibs.to_ulong();
        bs >>= 8;
    }

    QTextStream(&ip) << bytes[0]<< "."<< bytes[1]<< "."<< bytes[2]<< "."<< bytes[3];
    return ip;
}

std::bitset<32> IPAddress::bitsetFromIp(IPAddress ip)
{
    std::bitset<32> bs;
    for (int i = 0; i < 4; i++) {
        bs <<= 8;
        std::bitset<32> ui{ip.bytes[i]};
        bs |= ui;
    }
    return bs;
}

QString IPAddress::ipFromCidr(QString start_ip_str, int cidr)
{
    IPAddress start_ip(start_ip_str);
    std::bitset<32> mask{"11111111111111111111111111111111"};
    for (int i = 0; i < 32-cidr; i++) {
        mask.reset(i);
    }
    std::bitset<32> ip{(IPAddress::bitsetFromIp(start_ip)&=mask)|(~mask)};
    return IPAddress::ipFromBitset(ip);
}
