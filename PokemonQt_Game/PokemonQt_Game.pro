# using qtcore, qtgui, multimedia
QT  += core gui multimedia

# for QT5
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

config  += c++14

# name of app
TARGET = PokemonQt
TEMPLATE = app

# The following define tells the compilier to omit any warnings
# that is considered deprecated.
DEFINES += QT_DEPRECATED_WARNINGS

# All .cpp files
SOURCES += \
    Src/boss.cpp \
    Src/main.cpp \
    Src/game.cpp \
    Src/musicplayer.cpp \
    Src/player.cpp \

# All .h files
HEADERS += \
    Headers/game.h \
    Headers/player.h \
    Headers/boss.h \
    Headers/musicplayer.h

RESOURCES += \
    assets.qrc

FORMS += \
    Assets/Forms/game.ui
