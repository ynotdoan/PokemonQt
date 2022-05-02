# using qtcore, qtgui, multimedia
QT  += core gui multimedia

# for QT5
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

config  += c++11

# name of app
TARGET = PokemonQt
TEMPLATE = app

# The following define tells the compilier to omit any warnings
# that is considered deprecated.
DEFINES += QT_DEPRECATED_WARNINGS

# All .cpp files
SOURCES += \
    Src/arceus.cpp \
    Src/grid.cpp \
    Src/player.cpp \
    Src/game.cpp \
    Src/main.cpp \
    Src/sprite.cpp

# All .h files
HEADERS += \
    Headers/game.h \
    Headers/grid.h \
    Headers/player.h \
    Headers/sprite.h \
    Headers/arceus.h

RESOURCES += \
    assets.qrc
