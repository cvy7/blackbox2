#QT       += core gui

#greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#CONFIG += c++11

include (Flags.pri)
requires(qtConfig(filedialog))

unix{
POST_TARGETDEPS += ../blackbox2/analogwidgets/build-AnalogWidgets-Desktop_Qt_5_12_6_GCC_64bit-Debug/analogwidgets/libanalogwidgets.a
LIBS += ../blackbox2/analogwidgets/build-AnalogWidgets-Desktop_Qt_5_12_6_GCC_64bit-Debug/analogwidgets/libanalogwidgets.a
}

#win32-g++:{
#POST_TARGETDEPS += ../blackbox2/analogwidgets/build-AnalogWidgets-Desktop_Qt_5_13_1_MinGW_32_bit-Debug/analogwidgets/libanalogwidgets.a
#LIBS += ../blackbox2/analogwidgets/build-AnalogWidgets-Desktop_Qt_5_13_1_MinGW_32_bit-Debug/analogwidgets/libanalogwidgets.a
#}

win32-g++:{
POST_TARGETDEPS += ../blackbox2/analogwidgets/build-AnalogWidgets-Desktop_Qt_5_13_1_MinGW_32_bit-Release/analogwidgets/libanalogwidgets.a
LIBS += ../blackbox2/analogwidgets/build-AnalogWidgets-Desktop_Qt_5_13_1_MinGW_32_bit-Release/analogwidgets/libanalogwidgets.a
}


win32-msvc*:{
 POST_TARGETDEPS += ../analogwidgets/analogwidgets.lib
 LIBS += ../analogwidgets/analogwidgets.lib
}

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
#DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

#INCLUDEPATH += ../analogwidgets/analogwidgets \
#               ../analogwidgets
INCLUDEPATH += ../blackbox2/analogwidgets/AnalogWidgets/analogwidgets/analogwidgets \
               ../blackbox2/analogwidgets/AnalogWidgets/analogwidgets


SOURCES += \
    main.cpp \
    mainwindow.cpp \
    ppch440_72.cpp

HEADERS += \
    mainwindow.h \
    ppch440_72.h \
    ppch440_72.hh \
    ppch8_10td.h \
    ppch8_10td.hh \
    ppch8_32td.h \
    ppch8_32td.hh

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Flags.pri

RESOURCES += \
    application.qrc
