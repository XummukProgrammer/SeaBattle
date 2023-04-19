#include "AppRunnerDelegateFactory.h"

#include <AppRunner/AppRunnerServerDelegate.h>
#include <AppRunner/AppRunnerClientDelegate.h>

AppRunnerDelegateFactory::AppRunnerDelegateFactory()
{
}

AppRunnerDelegateFactory::~AppRunnerDelegateFactory()
{
}

IAppRunnerDelegate* AppRunnerDelegateFactory::CreateDelegate(const AppRunnerType& type) const
{
    switch (type)
    {
        case AppRunnerType::Server:
            return new AppRunnerServerDelegate();

        case AppRunnerType::Client:
            return new AppRunnerClientDelegate();
    }
    return nullptr;
}
