#-------------------------------------------------
#
# Project created by QtCreator 2020-11-04T18:06:42
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = modbus
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
LIBS += -Ldll -lws2_32
SOURCES += \
        main.cpp \
        mainwindow.cpp \
    modbus.c \
    modbus-data.c \
    modbus-rtu.c \
    modbus-tcp.c \
    mythread.cpp

HEADERS += \
        mainwindow.h \
    modbus-version.h \
    modbus-tcp-private.h \
    modbus-tcp.h \
    modbus-rtu-private.h \
    modbus-rtu.h \
    modbus-private.h \
    modbus.h \
    config.h \
    mythread.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
