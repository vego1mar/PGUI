#-------------------------------------------------
#
# Project created by QtCreator 2017-05-02T19:49:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MakerAndEater
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    maker.cpp \
    eater.cpp

HEADERS  += mainwindow.h \
    maker.h \
    eater.h

FORMS    += mainwindow.ui
