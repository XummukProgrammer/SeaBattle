#ifndef APPRUNNER_H
#define APPRUNNER_H

#include <AppRunner/AppRunnerType.h>
#include <AppRunner/AppRunnerSettings.h>
#include <QApplication>

class AppRunner
{
public:
    AppRunner();
    ~AppRunner();

public:
    void SetApplication(QApplication* pApplication);
    QApplication* GetApplication() const;

    int Exec();

private:
    AppRunnerType GetAppType() const;

private:
    QApplication* _pApplication;
    AppRunnerSettings _settings;
};

extern AppRunner g_AppRunner;

#endif // APPRUNNER_H
