QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

FORMS += \
    mainwindow.ui

DISTFILES +=

HEADERS += \
    groupingbyfolder.h \
    groupingbytype.h \
    groupingpattern.h \
    mainwindow.h \
    tablemodel.h \
    unitInformation.h

SOURCES += \
    groupingbyfolder.cpp \
    groupingbytype.cpp \
    main.cpp \
    mainwindow.cpp \
    tablemodel.cpp

