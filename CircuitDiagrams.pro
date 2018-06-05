#-------------------------------------------------
#
# Project created by QtCreator 2016-06-01T13:40:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PROJECT_3
TEMPLATE = app



SOURCES += main.cpp\
        mainwindow.cpp \
    addelement.cpp \
    elements/battery.cpp \
    elements/document.cpp \
    elements/factory.cpp \
    elements/phototransistor.cpp \
    elements/schottkyDiode.cpp \
    elements/volSource.cpp

HEADERS  += mainwindow.h \
    addelement.h \
    elements/baseElem.h \
    elements/battery.h \
    elements/document.h \
    elements/factory.h \
    elements/phototransistor.h \
    elements/schottkyDiode.h \
    elements/volSource.h

FORMS    += mainwindow.ui \
    addelement.ui

DISTFILES +=
