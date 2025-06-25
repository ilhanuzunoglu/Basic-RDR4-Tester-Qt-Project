TEMPLATE    = app
CONFIG      += qt warn_on release
QT          += widgets

HEADERS     += mainwindow.h \
    brightnessdialog.h \
    systeminfowidget.h \
    volumecontrol.h \
    musicplayer.h
SOURCES     += main.cpp \
               mainwindow.cpp \
    brightnessdialog.cpp \
    systeminfowidget.cpp \
    volumecontrol.cpp \
    musicplayer.cpp
FORMS       += mainwindow.ui

TARGET      = ilhan_test1
