QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    authinput.cpp \
    ipaddress.cpp \
    log.cpp \
    main.cpp \
    mainwindow.cpp \
    openfile.cpp \
    progress.cpp \
    scaninput.cpp \
    scanner.cpp \
    table.cpp

HEADERS += \
    authinput.h \
    device.h \
    ipaddress.h \
    log.h \
    mainwindow.h \
    openfile.h \
    progress.h \
    scaninput.h \
    scanner.h \
    table.h \
    types.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# DISTFILES +=

DEFINES += "CURL_STATICLIB"

RESOURCES += \
    res.qrc

INCLUDEPATH += $$PWD/include

LIBS += -lAdvapi32 -lNormaliz


LIBS += -L$$PWD/lib -lwinmm -lws2_32 -lwldap32 -llibcurl_a -lcrypt32
