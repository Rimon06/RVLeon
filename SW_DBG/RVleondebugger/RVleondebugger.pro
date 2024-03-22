#-------------------------------------------------
#
# Project created by QtCreator 2024-01-24T16:56:13
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QMAKE_CXXFLAGS += -std=c++0x

TARGET = RVleondebugger
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dtmcontroller.cpp \
    DialogDTM.cpp \
    pipelinereg.cpp \
    coresegmentacion.cpp

HEADERS  += mainwindow.h \
    dtmcontroller.h \
    DialogDTM.h \
    pipelinereg.h \
    coresegmentacion.h

FORMS    += mainwindow.ui \
    DialogDTM.ui \
    pipelinereg.ui
