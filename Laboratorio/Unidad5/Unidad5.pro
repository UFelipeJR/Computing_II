QT += core gui multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17


SOURCES += \
    ghost.cpp \
    laberinto.cpp \
    main.cpp \
    pacman.cpp \
    recursos.cpp \
    videojuego.cpp

HEADERS += \
    ghost.h \
    laberinto.h \
    pacman.h \
    recursos.h \
    videojuego.h

FORMS += \
    videojuego.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    recursos.qrc
