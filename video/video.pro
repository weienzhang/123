#-------------------------------------------------
#
# Project created by QtCreator 2017-07-17T16:33:39
#
#-------------------------------------------------

QT       += core gui multimediawidgets concurrent sql
QT       += multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = video
TEMPLATE = app

include($$PWD/opencv.pri)


#CONFIG += opencv3.0


SOURCES += main.cpp\
        mainwindow.cpp \
    showvideo.cpp

HEADERS  += mainwindow.h \
    showvideo.h

FORMS    += mainwindow.ui

#DISTFILES += \
  #  ../../Desktop/vedioparse/vedio/opencv.pri
