#include "AppRunnerClientDelegate.h"

#include <QDebug>

AppRunnerClientDelegate::AppRunnerClientDelegate()
{
}

AppRunnerClientDelegate::~AppRunnerClientDelegate()
{
}

void AppRunnerClientDelegate::Run()
{
    qDebug() << "Started Client";
}
