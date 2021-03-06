TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        AssetManager.cpp \
        Cloud.cpp \
        Collision.cpp \
        Cow.cpp \
        FirstGame.cpp \
        FirstGameState.cpp \
        GameOverstate.cpp \
        InstructionState.cpp \
        MainMenuState.cpp \
        Score.cpp \
        SplashState.cpp \
        StateMachine.cpp \
        White.cpp \
        inputmanager.cpp \
        main.cpp
INCLUDEPATH += "C:\SFML-2.5.1-windows-gcc-7.3.0-mingw-64-bit\SFML-2.5.1\include"
LIBS += -L"C:\SFML-2.5.1-windows-gcc-7.3.0-mingw-64-bit\SFML-2.5.1\lib"
CONFIG(debug, debug|release){
    LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-system-d -lsfml-window-d
} else {
    LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
}

HEADERS += \
    AssetManager.h \
    Cloud.h \
    Collision.h \
    Cow.h \
    Definitions.hpp \
    FirstGame.h \
    FirstGameState.h \
    GameOverstate.h \
    InstructionState.h \
    MainMenuState.h \
    Score.h \
    SplashState.h \
    State.hpp \
    StateMachine.hpp \
    White.h \
    inputmanager.h
