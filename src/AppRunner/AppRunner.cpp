#include "AppRunner.h"

#include <AppRunner/AppRunnerDelegateFactory.h>

AppRunner::AppRunner()
{
}

AppRunner::~AppRunner()
{
}

void AppRunner::Run(const AppRunnerType& type)
{
    AppRunnerDelegateFactory factory;
    auto delegate = factory.CreateDelegate(type);
    if (delegate)
    {
        delegate->Run();
        delete delegate;
    }
}
