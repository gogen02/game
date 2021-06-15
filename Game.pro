QT       += core gui
QT += multimediawidgets
QT += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Bullet.cpp \
    Bullet_h1.cpp \
    Bullet_h2.cpp \
    Enemy.cpp \
    Game.cpp \
    Health.cpp \
    Player.cpp \
    Score.cpp \
    main.cpp

HEADERS += \
    Bullet.h \
    Bullet_h1.h \
    Bullet_h2.h \
    Enemy.h \
    Game.h \
    Health.h \
    Player.h \
    Score.h

TRANSLATIONS += \
    Game_ru_RU.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
