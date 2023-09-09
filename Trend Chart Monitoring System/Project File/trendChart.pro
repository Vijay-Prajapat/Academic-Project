#-------------------------------------------------
#
# Project created by QtCreator 2022-11-06T23:16:34
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = trendChart
TEMPLATE = app

LIBS += -lsqlite3

SOURCES += main.cpp\
        trendchart.cpp \
    trendchartsetup.cpp \
    qcustomplot.cpp

HEADERS  += trendchart.h \
    trendchartsetup.h \
    qcustomplot.h

FORMS    += trendchart.ui \
    trendchartsetup.ui
