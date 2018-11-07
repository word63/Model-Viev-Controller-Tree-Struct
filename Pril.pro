#-------------------------------------------------
#
# Project created by QtCreator 2018-11-07T15:22:53
#
#-------------------------------------------------

QT       += \
        core gui widgets network charts serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Pril
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    tcpserver.cpp \
    visualisation/chartwidget.cpp \
    visualisation/datavisualisator.cpp \
    visualisation/logwidget.cpp \
    models/datadispatcher.cpp \
    models/node.cpp \
    models/simpletreemodel.cpp \
    device/abstractiodevice.cpp \
    device/comportdevice.cpp \
    device/serverdevice.cpp \
    device/socketdevice.cpp

HEADERS += \
        mainwindow.h \
    tcpserver.h \
    visualisation/chartwidget.h \
    visualisation/datavisualisator.h \
    visualisation/logwidget.h \
    models/datadispatcher.h \
    models/node.h \
    models/simpletreemodel.h \
    device/abstractiodevice.h \
    device/comportdevice.h \
    device/serverdevice.h \
    device/socketdevice.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
