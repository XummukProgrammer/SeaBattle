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

int AppRunner::Exec(const AppRunnerType& type)
{
    AppRunnerDelegateFactory factory;
    auto delegate = factory.CreateDelegate(type);
    if (delegate)
    {
        int result = delegate->Exec();
        delete delegate;
        return result;
    }
    return 1;
}
