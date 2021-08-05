#ifndef SCANINPUT_H
#define SCANINPUT_H


#include <QStringList>
#include <QPlainTextEdit>

class ScanInput : public QObject
{
    Q_OBJECT
public:
    ScanInput();

    QPlainTextEdit *ports_input;
    QPlainTextEdit *ips_input;

    static bool isPort(QString porttext);
    static bool isIp(QString porttext);

    QStringList getPorts();
    QStringList getIps();

    static QStringList parseDiap(QString start, QString stop);

public slots:
    void addPorts();
    void erasePorts();
    void addIps();
    void eraseIps();

};

#endif // SCANINPUT_H
