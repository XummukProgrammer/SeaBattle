#include "AppRunner.h"

#include <AppRunner/AppRunnerDelegateFactory.h>

AppRunner g_AppRunner;

AppRunner::AppRunner()
    : _pApplication(nullptr)
{
}

AppRunner::~AppRunner()
{
}

void AppRunner::SetApplication(QApplication* pApplication)
{
    _pApplication = pApplication;
}

QApplication* AppRunner::GetApplication() const
{
    return _pApplication;
}

int AppRunner::Exec()
{
    _settings.Load();

    AppRunnerDelegateFactory factory;
    auto delegate = factory.CreateDelegate(GetAppType());
    if (delegate)
    {
        int result = delegate->Exec();
        delete delegate;
        return result;
    }
    return 1;
}

AppRunnerType AppRunner::GetAppType() const
{
    const auto& appType = _settings.GetAppType();
    if (appType == "Client")
    {
        return AppRunnerType::Client;
    }
    else if (appType == "Server")
    {
        return AppRunnerType::Server;
    }
    return AppRunnerType::Client;
}
