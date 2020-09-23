#-------------------------------------------------
#
# Project created by QtCreator 2020-04-13T11:24:28
#
#-------------------------------------------------

QT       += core gui
QT       += network
QT       += xml
#串口模块
QT       += serialport
QT       += concurrent

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


TARGET = Demo1
TEMPLATE = app

#INCLUDEPATH += /usr/local/include/opencv \
                  # /usr/local/include/opencv2
#LIBS += /usr/local/lib/libopencv_core.so.3.4
#LIBS += /usr/local/lib/libopencv_highgui.so.3.4
#LIBS += /usr/local/lib/libopencv_calib3d.so.3.4
#LIBS += /usr/local/lib/libopencv_features2d.so.3.4
#LIBS += /usr/local/lib/libopencv_flann.so.3.4
#LIBS += /usr/local/lib/libopencv_imgcodecs.so.3.4
#LIBS += /usr/local/lib/libopencv_imgproc.so.3.4
#LIBS += /usr/local/lib/libopencv_ml.so.3.4
#LIBS += /usr/local/lib/libopencv_objdetect.so.3.4
#LIBS += /usr/local/lib/libopencv_video.so.3.4



TRANSLATIONS = zh_cn.ts\
lang_en.ts

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += main.cpp\
    cleanform.cpp \
    indexform.cpp \
    mainwindow.cpp \
    renderthread.cpp \
    roundprogressbartest.cpp \
    roundprogressbar.cpp \
    selfcheckform.cpp \
    singlecheckdevice.cpp \
    uidemo08.cpp \
    battery.cpp \
    batterynew.cpp \
    formchild.cpp \
    flatui.cpp \
    QRoundProgressBar.cpp \
    tool/loghelper.cpp \
    PrintMod/printmod.cpp \
    SendMod/sendmod.cpp \
    tool/domparser.cpp \
    LamMod/lammod.cpp \
    SortMod/sortmod.cpp \
    tool/appinit.cpp \
    tool/commhelper.cpp \
    tool/iconhelper.cpp \
    tool/fontawesomeicons.cpp \
    control/imageswitch.cpp \
    control/lightbutton.cpp \
    parawindow.cpp \
    control/DRoundProgressBar.cpp \
    newmainwindow.cpp \
    control/cthermometer.cpp \
    cardsenderform.cpp \
    CardSender/cardsender.cpp \
    concurrentform.cpp \
    devicebase.cpp \
    lamform.cpp \
    sortform.cpp \
    control/deviceanimation.cpp \
    Print/print_rck600.cpp \
    printform.cpp \
    tool/paramterclass.cpp

HEADERS  += mainwindow.h \
    cleanform.h \
    indexform.h \
    renderthread.h \
    roundprogressbar.h \
    roundprogressbartest.h \
    selfcheckform.h \
    singlecheckdevice.h \
    uidemo08.h \
    battery.h \
    batterynew.h \
    formchild.h \
    flatui.h \
    QRoundProgressBar.h \
    tool/loghelper.h \
    PrintMod/printmod.h \
    SendMod/sendmod.h \
    deviceinfo.h \
    tool/domparser.h \
    LamMod/lammod.h \
    SortMod/sortmod.h \
    tool/appinit.h \
    tool/commhelper.h \
    tool/iconhelper.h \
    tool/fontawesomeicons.h \
    control/imageswitch.h \
    control/lightbutton.h \
    parawindow.h \
    control/DRoundProgressBar.h \
    newmainwindow.h \
    control/cthermometer.h \
    cardsenderform.h \
    CardSender/cardsender.h \
    concurrentform.h \
    devicebase.h \
    lamform.h \
    sortform.h \
    control/deviceanimation.h \
    Print/print_rck600.h \
    printform.h \
    tool/paramterclass.h

FORMS    += mainwindow.ui \
    cleanform.ui \
    indexform.ui \
    roundprogressbartest.ui \
    selfcheckform.ui \
    singlecheckdevice.ui \
    uidemo08.ui \
    formchild.ui \
    parawindow.ui \
    newmainwindow.ui \
    cardsenderform.ui \
    concurrentform.ui \
    lamform.ui \
    sortform.ui \
    printform.ui

RESOURCES += \
    ImageSource.qrc


unix:!macx: LIBS += -L$$PWD/../../SVN-144/代码/打印机/build-R600Printer-unknown-u8c03u8bd5/ -lR600Printer -lDSRetransfer600App -lzint

INCLUDEPATH += $$PWD/../../SVN-144/代码/打印机/R600Printer
DEPENDPATH += $$PWD/../../SVN-144/代码/打印机/build-R600Printer-unknown-u8c03u8bd5
