#include "stat.h"


Stat::Stat()
{

}

void Stat::setIpsCount(int c)
{
    QString text = "Total IP's: ";
    text.append(c);
    Stat::ips_count->setText(text);
}
