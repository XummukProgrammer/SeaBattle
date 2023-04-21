#include "AppRunnerServerDelegate.h"

#include <AppRunner/AppRunner.h>
#include <Server/Server.h>
#include <Server/Logic/ServerGameLogic.h>

#include <QDebug>

AppRunnerServerDelegate::AppRunnerServerDelegate()
{
}

AppRunnerServerDelegate::~AppRunnerServerDelegate()
{
}

int AppRunnerServerDelegate::Exec()
{
    qDebug() << "Run server application";

    Server server;
    server.Start();

    ServerGameLogic logic;
    logic.SetServer(&server);

    return g_AppRunner.GetApplication()->exec();
}
