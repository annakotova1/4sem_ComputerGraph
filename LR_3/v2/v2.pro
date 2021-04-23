######################################################################
# Automatically generated by qmake (3.1) Wed Apr 7 17:30:04 2021
######################################################################

TEMPLATE = app
TARGET = app.exe
INCLUDEPATH += .

# The following define makes your compiler warn you if you use any
# feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += inc/MyAlgorithms.hpp \
           inc/MyGraphicsItemGroup.hpp \
           inc/MyGraphicsView.hpp \
           inc/MyGrid.hpp \
           inc/MyLocale.hpp \
           inc/MyMainWindow.hpp \
           inc/MyPoint.hpp \
           inc/ui_main_window_ui.h
SOURCES += src/draw_algorithms.cpp \
           src/main.cpp \
           src/MyAlgorithms.cpp \
           src/MyGraphicsItemGroup.cpp \
           src/MyGraphicsView.cpp \
           src/MyGrid.cpp \
           src/MyLocale.cpp \
           src/MyMainWindow.cpp \
           src/MyPoint.cpp \
           src/time_algorithms.cpp

QT += charts
QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += qt debug
QMAKE_CXXFLAGS += -O0 -g -ggdb
