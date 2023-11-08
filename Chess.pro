#-------------------------------------------------
#
# Project created by QtCreator 2018-03-17T13:42:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Chess
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


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    board.cpp \
    capturedwidget.cpp \
    figure.cpp

HEADERS += \
        mainwindow.h \
    board.h \
    capturedwidget.h \
    figure.h

FORMS += \
        mainwindow.ui

RESOURCES += \
    mypieces.qrc

DISTFILES += \
    pieces/Chess_bdt45.svg \
    pieces/Chess_blt45.svg \
    pieces/Chess_kdt45.svg \
    pieces/Chess_klt45.svg \
    pieces/Chess_ndt45.svg \
    pieces/Chess_nlt45.svg \
    pieces/Chess_pdt45.svg \
    pieces/Chess_plt45.svg \
    pieces/Chess_qdt45.svg \
    pieces/Chess_qlt45.svg \
    pieces/Chess_rdt45.svg \
    pieces/Chess_rlt45.svg
