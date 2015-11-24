QT       += core gui widgets
TARGET = BSTVisualizer
TEMPLATE = app

SOURCES += main.cpp \
    BST.cpp

HEADERS  += \
    BST.h \
    BST.h

FORMS    +=

CONFIG += console
INCLUDEPATH += $$PWD/../qtsingleapplication-2.6-opensource/src/
