TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Gra.cpp \
        Gracz.cpp \
        Platformy.cpp \
        Wrogowie.cpp \
        main.cpp

INCLUDEPATH += "F:/SFML/SFML-2.5.1/include"
LIBS += -L"F:/SFML/SFML-2.5.1/lib"
CONFIG(debug, debug|release){
    LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-system-d -lsfml-window-d
} else {
    LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
}

HEADERS += \
    Gra.h \
    Gracz.h \
    Platformy.h \
    Wrogowie.h
