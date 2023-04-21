#include "AppRunnerClientDelegate.h"

#include <AppRunner/AppRunner.h>
#include <Client/Client.h>
#include <Client/Visual/ClientMainWindow.h>
#include <Client/Logic/ClientGameLogic.h>

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

    ClientGameLogic logic;
    logic.SetClient(&client);

    ClientMainWindow window;
    window.SetLogic(&logic);
    window.show();

    return g_AppRunner.GetApplication()->exec();
}
