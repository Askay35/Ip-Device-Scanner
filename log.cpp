#include "log.h"
#include <QTime>
#include <QFileDialog>
#include <QScrollBar>
#include <QTextStream>

Log::Log()
{
}


QTextBrowser * Log::log_field=nullptr;

QCheckBox * Log::log_checkbox=nullptr;

QCheckBox * Log::autoscroll_checkbox=nullptr;

void Log::exportLogs()
{
    QString exporttext = Log::log_field->toPlainText();
    QString filename = QFileDialog::getSaveFileName(NULL, "Save Log", "/", "TXT file (*.txt)");
    if(filename==NULL){
        return;
    }
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly)){
        return;
    }
    QTextStream out(&file);
    out << exporttext;
    file.close();
    QString logtext = "Logs have been exported to ";
    logtext.append(filename);
    Log::appendLogs(logtext);
}

void Log::appendLogs(QString text)
{
    if(Log::log_checkbox->isChecked()){
        QString logtext = "[";
        QTextStream(&logtext) << (QTime::currentTime().toString(Qt::ISODate)) << "] " << text;
        Log::log_field->append(logtext);
        if(Log::autoscroll_checkbox->isChecked()){
            QScrollBar *sb = Log::log_field->verticalScrollBar();
            sb->setValue(sb->maximum());
        }
    }
}
