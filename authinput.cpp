#include "authinput.h"
#include <QFileDialog>
#include "openfile.h"
#include "log.h"

//AuthInput::AuthInput(QPlainTextEdit *loginsinp, QPlainTextEdit *passwordsinp)
//{
//    this->logins_input = loginsinp;
//    this->passwords_input = passwordsinp;
//}


AuthInput::AuthInput()
{
}

void AuthInput::addLogins()
{

    QString loginstext = dialogGetContents("Load logins", "TXT file (*.txt)");
    if(loginstext.length() <2){
        return;
    }
    this->logins_input->appendPlainText(loginstext.replace(" ", ""));
    Log::appendLogs("Logins loaded");
}

void AuthInput::addPasswords()
{
    QString passwords = dialogGetContents("Load passwords","TXT file (*.txt)");
    if(passwords.length() <2){
        return;
    }
    this->passwords_input->appendPlainText(passwords.replace(" ", ""));
    Log::appendLogs("Passwords loaded");
}

QStringList AuthInput::getLogins()
{
    QStringList logins;
    QStringList loginstemp = this->logins_input->toPlainText().split("\n");
    for (int i = 0; i < loginstemp.length(); i++) {
        if(AuthInput::isValid(loginstemp[i])){
            logins.append(loginstemp[i]);
        }
    }
    return logins;
}

QStringList AuthInput::getPasswords()
{
    QStringList passwords;
    QStringList passwordstemp = this->passwords_input->toPlainText().split("\n");
    for (int i = 0; i < passwordstemp.length(); i++) {
        if(AuthInput::isValid(passwordstemp[i])){
            passwords.append(passwordstemp[i]);
        }
    }
    passwords.append("");
    return passwords;
}

bool AuthInput::isValid(QString text)
{
    return text.length()>1 && text.length() < 33;
}

void AuthInput::eraseLogins()
{
    this->logins_input->clear();
}

void AuthInput::erasePasswords()
{
    this->passwords_input->clear();
}
