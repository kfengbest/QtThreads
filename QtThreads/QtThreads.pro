#-------------------------------------------------
#
# Project created by QtCreator 2012-12-30T11:49:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtThreads
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    worker1.cpp \
    thread2.cpp \
    thread3.cpp

HEADERS  += mainwindow.h \
    worker1.h \
    thread2.h \
    thread3.h

FORMS    += mainwindow.ui
