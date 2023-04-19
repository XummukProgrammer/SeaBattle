#include "AppRunnerServerDelegate.h"

#include <QDebug>

AppRunnerServerDelegate::AppRunnerServerDelegate()
{
}

AppRunnerServerDelegate::~AppRunnerServerDelegate()
{
}

void AppRunnerServerDelegate::Run()
{
    qDebug() << "Started Server";
}
