#-------------------------------------------------
#
# Project created by QtCreator 2018-02-08T13:25:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Spectrum
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    graphicswindow.cpp \
    chartbar.cpp

HEADERS  += mainwindow.h \
    graphicswindow.h \
    chartbar.h \
    colourmanager.h

FORMS    += mainwindow.ui
