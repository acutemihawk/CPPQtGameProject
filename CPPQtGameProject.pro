QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    entity.cpp \
    game.cpp \
    gate.cpp \
    main.cpp \
    map.cpp \
    npc.cpp \
    tree.cpp

    widget.cpp

HEADERS += \
    entity.h \
    game.h \
    gate.h \
    map.h \
    npc.h \
    tree.h

    widget.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32-msvc*{
    LIBS += -luser32
}

RESOURCES += \
    ressources/ressources.qrc
