#include "scaninput.h"
#include "openfile.h"
#include "progress.h"
#include "ipaddress.h"
#include <QTextStream>
#include "log.h"

ScanInput::ScanInput(){}

bool ScanInput::isPort(QString porttext)
{
    bool is_port;
    int port = porttext.toInt(&is_port);
    if(is_port){
        if(port>0 && port < 65536){
            return true;
        }
    }
    return false;
}

bool ScanInput::isIp(QString ip){
    QStringList ipparts = ip.split(".");
    if(ipparts.length() == 4){
        bool isui8 = false;
        int ui8 = 0;
        ui8 = ipparts[0].toUInt(&isui8);
        if(isui8 && ui8<256){
            ui8 = ipparts[1].toUInt(&isui8);
            if(isui8 && ui8<256){
                ui8 = ipparts[2].toUInt(&isui8);
                if(isui8 && ui8<256){
                    ui8 = ipparts[3].toUInt(&isui8);
                    if(isui8 && ui8<256){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

void ScanInput::addPorts()
{
    QString ports = dialogGetContents("Load ports", "TXT file (*.txt)");
    if(ports.length() <1){
        return;
    }
    this->ports_input->appendPlainText(ports);
    Log::appendLogs("Ports loaded");
}

void ScanInput::erasePorts()
{
    this->ports_input->clear();
}

void ScanInput::addIps(){
    QString ips = dialogGetContents("Load ip ranges", "TXT file (*.txt)");
    if(ips.length() <1){
        return;
    }
    this->ips_input->appendPlainText(ips);
    Log::appendLogs("IP's loaded");
}

QStringList ScanInput::getPorts()
{
    QStringList ports;
    QString portstext = this->ports_input->toPlainText();
    if(portstext.length()<1){
        return ports;
    }
    QStringList splited = portstext.split("\n");
    QStringList::iterator iter;
    for(iter = splited.begin(); iter!=splited.end();++iter){
        if(ScanInput::isPort(*iter)){
            ports.append(*iter);
        }
    }
    return ports;
}

QStringList ScanInput::getIps()
{
    QStringList ips;
    QStringList ipranges = ips_input->toPlainText().split("\n");
    //ProgressBar::pb->reset();
    //ProgressBar::pb->setMaximum(ipranges.length());
    for (int i = 0; i < ipranges.length(); i++) {
        if(ScanInput::isIp(ipranges[i])){
            ips.append(ipranges[i]);
            continue;
        }
        if(ipranges[i].contains("-")){
            QStringList iprange = ipranges[i].split("-");
            if(iprange.length()==2){
                ips.append(ScanInput::parseDiap(iprange[0], iprange[1]));
            }
            continue;
        }
        if(ipranges[i].contains("/")){
            QStringList iprange = ipranges[i].split("/");
            if(iprange.length()==2){
                QString stopip = IPAddress::ipFromCidr(iprange[0], iprange[1].toInt());
                ips.append(ScanInput::parseDiap(iprange[0], stopip));
            }
        }
      //  ProgressBar::pb->setValue(ProgressBar::pb->value()+1);
    }
    return  ips;
}

QStringList ScanInput::parseDiap(QString start, QString stop)
{
    QStringList ips;
    if(!ScanInput::isIp(start))return ips;
    if(!ScanInput::isIp(stop))return ips;
    IPAddress ipstart(start);
    IPAddress ipstop(stop);
    for (int i = ipstart.bytes[2]; i <= ipstop.bytes[2]; i++) {
        if(i!=ipstop.bytes[2]){
            for (int j = ipstart.bytes[3]; j < 256; j++) {
                QString ip;
                QTextStream(&ip)<<ipstart.bytes[0]<<"."<<ipstart.bytes[1]<<"."<<i<<"."<<j;
                ips.append(ip);
            }
        }
        else{
            for (int j = ipstart.bytes[3]; j <= ipstop.bytes[3]; j++) {
                QString ip;
                QTextStream(&ip)<<ipstart.bytes[0]<<"."<<ipstart.bytes[1]<<"."<<i<<"."<<j;
                ips.append(ip);
            }
        }
    }
    return ips;
}

void ScanInput::eraseIps()
{
    this->ips_input->clear();
}
