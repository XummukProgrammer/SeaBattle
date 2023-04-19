#include "AppRunnerServerDelegate.h"

#include <Server/Server.h>

#include <QDebug>

AppRunnerServerDelegate::AppRunnerServerDelegate()
{
}

AppRunnerServerDelegate::~AppRunnerServerDelegate()
{
}

void AppRunnerServerDelegate::Run()
{
    qDebug() << "Run server application";

    Server server;
    server.Start();
}
