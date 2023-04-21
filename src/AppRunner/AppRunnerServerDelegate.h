#ifndef APPRUNNERSERVERDELEGATE_H
#define APPRUNNERSERVERDELEGATE_H

#include <AppRunner/IAppRunnerDelegate.h>

class AppRunnerServerDelegate : public IAppRunnerDelegate
{
public:
    AppRunnerServerDelegate();
    ~AppRunnerServerDelegate();

public:
    int Exec() override;
};

#endif // APPRUNNERSERVERDELEGATE_H
