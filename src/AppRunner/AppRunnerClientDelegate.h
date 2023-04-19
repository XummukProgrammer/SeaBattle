#ifndef APPRUNNERCLIENTDELEGATE_H
#define APPRUNNERCLIENTDELEGATE_H

#include <AppRunner/IAppRunnerDelegate.h>

class AppRunnerClientDelegate : public IAppRunnerDelegate
{
public:
    AppRunnerClientDelegate();
    ~AppRunnerClientDelegate();

public:
    void Run() override;
};

#endif // APPRUNNERCLIENTDELEGATE_H
