QT       += core gui
QT += charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

FORMS += \
    mainwindow.ui

DISTFILES +=

HEADERS += \
    chartadapters.h \
    charts.h \
    directoryobserver.h \
    groupbystrategy.h \
    listadapter.h \
    mainwindow.h \
    tablemodel.h \
    unitInformation.h

SOURCES += \
    chartadapters.cpp \
    charts.cpp \
    groupbystrategy.cpp \
    listadapter.cpp \
    main.cpp \
    mainwindow.cpp \
    tablemodel.cpp

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

