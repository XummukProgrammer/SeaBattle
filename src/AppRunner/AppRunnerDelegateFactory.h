#ifndef APPRUNNERDELEGATEFACTORY_H
#define APPRUNNERDELEGATEFACTORY_H

#include <AppRunner/AppRunnerType.h>
#include <AppRunner/IAppRunnerDelegate.h>

class AppRunnerDelegateFactory
{
public:
    AppRunnerDelegateFactory();
    ~AppRunnerDelegateFactory();

public:
    IAppRunnerDelegate* CreateDelegate(const AppRunnerType& type) const;
};

#endif // APPRUNNERDELEGATEFACTORY_H
