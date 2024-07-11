QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    function.cpp \
    account.cpp \
    main.cpp \
    qcount.cpp \
    qend.cpp \
    qifice.cpp \
    qinspect.cpp \
    qoutnum.cpp \
    qtransnum.cpp \
    qlog.cpp \
    qpass.cpp \
    qmain.cpp \
    qinnum.cpp

HEADERS += \
    account.h \
    function.h \
    account.h \
    qcount.h \
    qend.h \
    qifice.h \
    qinspect.h \
    qoutnum.h \
    qtransnum.h \
    qlog.h \
    qpass.h \
    qmain.h \
    qinnum.h

FORMS += \
    qcount.ui \
    qend.ui \
    qifice.ui \
    qinspect.ui \
    qoutnum.ui \
    qtransnum.ui \
    qlog.ui \
    qpass.ui \
    qmain.ui \
    qinnum.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    source.qrc


