#-------------------------------------------------
#
# Project created by QtCreator 2015-12-31T00:29:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 15Puzzle1
TEMPLATE = app


SOURCES += main.cpp\
    Puzzleboard.cpp \
    Mainwindow.cpp \
    Puzzleblock.cpp

HEADERS  += \
    Puzzleboard.h \
    Interfaces.h \
    Mainwindow.h \
    Puzzleblock.h

FORMS    += mainwindow.ui
