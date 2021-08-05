#ifndef AUTHINPUT_H
#define AUTHINPUT_H

#include <QStringList>
#include <QPlainTextEdit>

class AuthInput : public QObject
{
    Q_OBJECT
public:
    AuthInput();

    QPlainTextEdit *logins_input;
    QPlainTextEdit *passwords_input;

    QStringList getLogins();
    QStringList getPasswords();
    static bool isValid(QString text);

public slots:
    void addLogins();
    void addPasswords();
    void eraseLogins();
    void erasePasswords();

};

#endif // AUTHINPUT_H
