#-------------------------------------------------
#
# Project created by QtCreator 2016-10-30T18:03:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = P4C
TEMPLATE = app
CONFIG += gnu++11

SOURCES += main.cpp\
        mainwindow.cpp \
    execution.cpp

HEADERS  += mainwindow.h \
    execution.h \
    Proceso.h \
    controlador.h

FORMS    += mainwindow.ui \
    execution.ui
