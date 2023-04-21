#include "AppRunnerSettings.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>

AppRunnerSettings::AppRunnerSettings()
{
}

AppRunnerSettings::~AppRunnerSettings()
{
}

void AppRunnerSettings::Load()
{
    QFile file(XML_PATH);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        auto jsonDocument = QJsonDocument::fromJson(file.readAll());
        auto jsonObject = jsonDocument.object();

        _appType = jsonObject["type"].toString();
    }
}

const QString& AppRunnerSettings::GetAppType() const
{
    return _appType;
}
