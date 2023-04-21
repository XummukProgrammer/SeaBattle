#include "AppRunnerClientDelegate.h"

#include <AppRunner/AppRunner.h>
#include <Client/Client.h>
#include <Client/Visual/ClientMainWindow.h>

#include <QDebug>

AppRunnerClientDelegate::AppRunnerClientDelegate()
{
}

AppRunnerClientDelegate::~AppRunnerClientDelegate()
{
}

int AppRunnerClientDelegate::Exec()
{
    qDebug() << "Run client application";

    Client client;
    client.Connect();

    ClientMainWindow window;
    window.show();

    return g_AppRunner.GetApplication()->exec();
}
