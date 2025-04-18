QT       += core gui
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    authregform.cpp \
    logic.cpp \
    main.cpp \
    formsmanager.cpp \
    queue.cpp \
    queuecreator.cpp \
    queuehub.cpp \
    singletonclient.cpp

HEADERS += \
    authregform.h \
    formsmanager.h \
    logic.h \
    queue.h \
    queuecreator.h \
    queuehub.h \
    singletonclient.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS += \
    authregform.ui \
    queue.ui \
    queuecreator.ui \
    queuehub.ui

win32::RC_FILE = iconManager.rc

RESOURCES += \
    res.qrc
