#include "openfile.h"



QString dialogGetContents(QString caption, QString filter)
{
    QString filename = QFileDialog::getOpenFileName(NULL, caption, "/", filter);
    if(filename==NULL){
        return "";
    }
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        return "";
    }
    QString text = file.readAll();
    return text;
}
