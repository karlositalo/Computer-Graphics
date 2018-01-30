#-------------------------------------------------
#
# Project created by QtCreator 2016-11-11T12:37:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RayCasting
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    Face.cpp \
    Material.cpp \
    Kvertex.cpp \
    LightSource.cpp \
    Matrix.cpp \
    Observer.cpp \
    Cube.cpp \
    ViewPort.cpp \
    LinearSystems.cpp \
    Scene.cpp

HEADERS  += MainWindow.h \
    Face.h \
    Material.h \
    Kvertex.h \
    Scene.h \
    LightSource.h \
    Matrix.h \
    Observer.h \
    ViewPort.h \
    LinearSystems.h \
    Cube.h

FORMS    += MainWindow.ui
