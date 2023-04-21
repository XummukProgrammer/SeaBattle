#include "AppRunnerServerDelegate.h"

#include <AppRunner/AppRunner.h>
#include <Server/Server.h>

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

    return g_AppRunner.GetApplication()->exec();
}
