QT += core
QT -= gui

CONFIG += c++11

TARGET = Expression
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    expression.cpp \
    scopedptr.cpp \
    sharedptr.cpp

HEADERS += \
    expression.h \
    scopedptr.h \
    sharedptr.h
