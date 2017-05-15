#-------------------------------------------------
#
# Project created by QtCreator 2017-05-15T09:31:26
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QDbConnector
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    DBHelper.cpp

HEADERS  += mainwindow.h \
    DBHelper.hpp \
    ODBCSourceDataTypes.hpp

FORMS    += mainwindow.ui
