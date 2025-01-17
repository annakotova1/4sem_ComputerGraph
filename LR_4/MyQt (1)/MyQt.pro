######################################################################
# Automatically generated by qmake (3.1) Sat May 8 11:04:16 2021
######################################################################

TEMPLATE = app
TARGET = MyQt
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
HEADERS += MyAlgorithms/MyAlgorithms.hpp \
           MyController/MyController.hpp \
           MyGraphicsItemGroup/MyGraphicsItemGroup.hpp \
           MyGraphicsView/MyGraphicsView.hpp \
           MyGrid/MyGrid.hpp \
           MyHistogramView/MyHistogramView.hpp \
           MyLocale/MyLocale.hpp \
           MyMainWindow/MyMainWindow.hpp \
           MyPlotView/MyPlotView.hpp \
           MyPoint/MyPoint.hpp \
           MyPushButton\MyPushButton.hpp \
           MyColorInput\MyColorInput.hpp \
           MyToolButton\MyToolButton.hpp \
           MyAction\MyAction.hpp

SOURCES += main.cpp \
           MyAlgorithms/draw_algorithms.cpp \
           MyAlgorithms/MyAlgorithms.cpp \
           MyAlgorithms/time_algorithms.cpp \
           MyController/MyController.cpp \
           MyGraphicsItemGroup/MyGraphicsItemGroup.cpp \
           MyGraphicsView/MyGraphicsView.cpp \
           MyGrid/MyGrid.cpp \
           MyHistogramView/MyHistogramView.cpp \
           MyLocale/MyLocale.cpp \
           MyMainWindow/MyMainWindow.cpp \
           MyPlotView/MyPlotView.cpp \
           MyPoint/MyPoint.cpp \
           MyPushButton\MyPushButton.cpp \
           MyColorInput\MyColorInput.cpp \
           MyAction\MyAction.cpp \
           MyToolButton\MyToolButton.cpp 

QT += charts
QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += qt debug
QMAKE_CXXFLAGS += -O0 -g -ggdb