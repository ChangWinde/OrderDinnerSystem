#-------------------------------------------------
#
# Project created by QtCreator 2018-07-05T16:01:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DCXT
TEMPLATE = app


SOURCES += main.cpp\
        appearance.cpp \
    menu.cpp \
    order.cpp

HEADERS  += appearance.h \
    menu.h \
    order.h

FORMS    += appearance.ui \
    menu.ui \
    order.ui

RESOURCES += \
    img.qrc
