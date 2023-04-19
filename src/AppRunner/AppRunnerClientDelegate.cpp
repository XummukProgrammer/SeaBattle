#include "AppRunnerClientDelegate.h"

#include <Client/Client.h>

#include <QDebug>

AppRunnerClientDelegate::AppRunnerClientDelegate()
{
}

AppRunnerClientDelegate::~AppRunnerClientDelegate()
{
}

void AppRunnerClientDelegate::Run()
{
    qDebug() << "Run client application";

    Client client;
    client.Connect();
}
