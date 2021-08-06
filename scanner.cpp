#include "scanner.h"
#include "log.h"
#include <vector>

bool Scanner::defaultCheckCredentials(QString ip, QString port, QString login, QString password, int timeout)
{
    QString url;
    url.append(ip);
    double connect;
    curl_easy_setopt(curl, CURLOPT_USERNAME, login.toStdString().c_str());
    curl_easy_setopt(curl, CURLOPT_PASSWORD, password.toStdString().c_str());
    curl_easy_setopt(curl, CURLOPT_TIMEOUT_MS, timeout);
    curl_easy_setopt(curl, CURLOPT_URL, url.toStdString().c_str());
    curl_easy_setopt(curl, CURLOPT_PORT, port.toInt());
    CURLcode res = curl_easy_perform(curl);

    IPDevice device{ip, port, "", login};
    device.auth.append(":");
    device.auth.append(password);

    if(res == CURLE_OK){
        res = curl_easy_getinfo(curl, CURLINFO_CONNECT_TIME, &connect);
        if(res == CURLE_OK){
            device.time = QString::number(connect);
            emit sendRow(device);
        }
        else{
            emit sendRow(device);
        }

        curl_easy_cleanup(curl);
        return true;
    }
    curl_easy_cleanup(curl);
    return false;
}

bool Scanner::ftpCheckCredentials(QString ip, QString login, QString password, int timeout)
{
    QString url = "ftp://";
    url.append(ip);
    double connect;
    curl_easy_setopt(curl, CURLOPT_USERNAME, login.toStdString().c_str());
    curl_easy_setopt(curl, CURLOPT_PASSWORD, password.toStdString().c_str());
    curl_easy_setopt(curl, CURLOPT_TIMEOUT_MS, timeout);
    curl_easy_setopt(curl, CURLOPT_URL, url.toStdString().c_str());
    CURLcode res = curl_easy_perform(curl);

    IPDevice device{ip, "21", "",login};
    device.auth.append(":");
    device.auth.append(password);

    if(res == CURLE_OK){
        res = curl_easy_getinfo(curl, CURLINFO_CONNECT_TIME, &connect);
        if(res == CURLE_OK){
            device.time = QString::number(connect);
            emit sendRow(device);
        }
        else{
            emit sendRow(device);
        }

        curl_easy_cleanup(curl);
        return true;
    }

    curl_easy_cleanup(curl);
    return false;
}


Scanner::Scanner()
{
    curl_global_init(CURL_GLOBAL_ALL);
    this->curl = curl_easy_init();
    if (!this->curl){
        Log::appendLogs("CURL init failed");
        exit(-1);
    }
}

Scanner::~Scanner()
{
    curl_easy_cleanup(this->curl);
    curl_global_cleanup();
}

bool Scanner::checkCredentials(QString ip, QString port, QString login, QString password, int timeout)
{
    if(port=="21"){
        return ftpCheckCredentials(ip, login, password, timeout);
    }
    else{
        return defaultCheckCredentials(ip, port, login, password, timeout);
    }
    return false;
}




void Scanner::scan(QStringList ips, QStringList ports, QStringList logins, QStringList passwords,int max_threads, int timeout)
{
    std::vector<std::thread> threads;

    for (QString &ip : ips) {
        for (QString &port : ports) {
            for (QString &login : logins) {
                for (QString &password : passwords) {
                    if(threads.size()<max_threads){
                        threads.push_back(std::thread(&Scanner::checkCredentials, this, ip, port, login, password, timeout));
                    }
                    else{
                        for(std::thread &t : threads){
                            t.join();
                        }
                        threads.clear();
                    }
                }
            }
        }
    }
}
