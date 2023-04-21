QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17 console

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/AppRunner/AppRunnerSettings.cpp \
    src/Client/Client.cpp \
    src/Client/Logic/ClientGameLogic.cpp \
    src/Client/Visual/ClientMainWindow.cpp \
    src/Client/Visual/ClientScene.cpp \
    src/Common/TcpSockerUtils.cpp \
    src/Server/Logic/ServerGameLogic.cpp \
    src/Server/Server.cpp \
    src/main.cpp \
    src/AppRunner/AppRunner.cpp \
    src/AppRunner/AppRunnerClientDelegate.cpp \
    src/AppRunner/AppRunnerDelegateFactory.cpp \
    src/AppRunner/AppRunnerServerDelegate.cpp \
    src/AppRunner/IAppRunnerDelegate.cpp

HEADERS += \
    src/AppRunner/AppRunner.h \
    src/AppRunner/AppRunnerClientDelegate.h \
    src/AppRunner/AppRunnerDelegateFactory.h \
    src/AppRunner/AppRunnerServerDelegate.h \
    src/AppRunner/AppRunnerSettings.h \
    src/AppRunner/AppRunnerType.h \
    src/AppRunner/IAppRunnerDelegate.h \
    src/Client/Client.h \
    src/Client/ClientCommandType.h \
    src/Client/Logic/ClientGameLogic.h \
    src/Client/Visual/ClientMainWindow.h \
    src/Client/Visual/ClientScene.h \
    src/Common/TcpSockerUtils.h \
    src/Server/Logic/ServerGameLogic.h \
    src/Server/Server.h \
    src/Server/ServerCommandType.h

INCLUDEPATH += \
    src

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res/Application.qrc

FORMS += \
    ui/ClientMainWindow.ui
