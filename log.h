#ifndef LOG_H
#define LOG_H

#include <QTextBrowser>
#include <QCheckBox>

class Log
{
    Log();

public:
    static QTextBrowser *log_field;
    static QCheckBox *log_checkbox;
    static QCheckBox *autoscroll_checkbox;

    static void appendLogs(QString text);

    static void exportLogs();
};

#endif // LOG_H
