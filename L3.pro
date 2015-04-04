#-------------------------------------------------
#
# Project created by QtCreator 2015-03-18T14:21:17
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = L3
CONFIG   += console
CONFIG   -= app_bundle
CONFIG += C++11


TEMPLATE = app


SOURCES += main.cpp \
    PolishNotationConverter.cpp \
    symboldefiner.cpp

HEADERS += \
    stack.h \
    PolishNotationConverter.h \
    symboldefiner.h \
    node.h \
    list.h
