#ifndef APPRUNNER_H
#define APPRUNNER_H

#include <AppRunner/AppRunnerType.h>
#include <QApplication>

class AppRunner
{
public:
    AppRunner();
    ~AppRunner();

public:
    void SetApplication(QApplication* pApplication);
    QApplication* GetApplication() const;

    int Exec(const AppRunnerType& type);

private:
    QApplication* _pApplication;
};

extern AppRunner g_AppRunner;

#endif // APPRUNNER_H
