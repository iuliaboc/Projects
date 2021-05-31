QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    YBoard.cpp \
    board.cpp \
    game.cpp \
    havannahBoard.cpp \
    havannahWindow.cpp \
    havannahframe.cpp \
    havannahgame.cpp \
    hexBoard.cpp \
    hexWindow.cpp \
    hexframe.cpp \
    hexgame.cpp \
    main.cpp \
    mainwindow.cpp \
    piece.cpp \
    player.cpp \
    yWindow.cpp \
    yframe.cpp \
    ygame.cpp

HEADERS += \
    YBoard.h \
    board.h \
    game.h \
    havannahBoard.h \
    havannahWindow.h \
    havannahframe.h \
    havannahgame.h \
    hexBoard.h \
    hexWindow.h \
    hexframe.h \
    hexgame.h \
    mainwindow.h \
    piece.h \
    player.h \
    yWindow.h \
    yframe.h \
    ygame.h

FORMS += \
    havannahWindow.ui \
    hexWindow.ui \
    mainwindow.ui \
    yWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
