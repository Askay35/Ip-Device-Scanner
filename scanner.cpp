#include "scanner.h"
#include "log.h"
#include <QTextStream>

bool Scanner::ftpCheckCredentials(QString ip, QString login, QString password)
{
    QString url = "ftp://";
    QTextStream(&url) << ip;
    curl_easy_setopt(curl, CURLOPT_USERNAME, login.toStdString().c_str());
    curl_easy_setopt(curl, CURLOPT_PASSWORD, password.toStdString().c_str());
    curl_easy_setopt(curl, CURLOPT_URL, url.toStdString().c_str());
    CURLcode res = curl_easy_perform(curl);
    if(res == CURLE_OK){
       return true;
    }
    return false;
}

Scanner::Scanner()
{
    curl_global_init(CURL_GLOBAL_ALL);
    this->curl = curl_easy_init();
    if (!this->curl){
        Log::appendLogs("CURL init failed");
        Sleep(2000);
        exit(-1);
    }
}

Scanner::~Scanner()
{
    curl_global_cleanup();
}

bool Scanner::checkCredentials(QString ip, QString port, QString login, QString password)
{
    int intport = port.toInt();
    switch (intport) {
    case 21:
        return this->ftpCheckCredentials(ip, login, password);
        break;
    default:
        return false;
        break;
    }
}

void Scanner::scan(QStringList ips, QStringList ports, QStringList logins, QStringList passwords)
{

}

