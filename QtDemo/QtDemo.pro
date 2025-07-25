QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

Debug:DESTDIR= $$PWD/Bin/debug

Release:DESTDIR= $$PWD/Bin/release


SOURCES += \
    bars/infoform.cpp \
    components/tableview/tabledelegate.cpp \
    components/tableview/tablemodel.cpp \
    config.cpp \
    main.cpp \
    widget.cpp

HEADERS += \
    bars/infoform.h \
    components/tableview/tabledelegate.h \
    components/tableview/tablemodel.h \
    components/treeview/treedata.h \
    config.h \
    widget.h

FORMS += \
    bars/infoform.ui \
    widget.ui

INCLUDEPATH += $$PWD/bars \
               $$PWD/components/tableview

TRANSLATIONS += lang_english.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

DISTFILES += \
    ReadMe.md \
    lang_english.qm
