#ifndef APPRUNNER_H
#define APPRUNNER_H

#include <AppRunner/AppRunnerType.h>

class AppRunner
{
public:
    AppRunner();
    ~AppRunner();

public:
    void Run(const AppRunnerType& type);
};

#endif // APPRUNNER_H
