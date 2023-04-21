#ifndef APPRUNNERSETTINGS_H
#define APPRUNNERSETTINGS_H

#include <QString>

class AppRunnerSettings
{
public:
    AppRunnerSettings();
    ~AppRunnerSettings();

public:
    void Load();

    const QString& GetAppType() const;

private:
    QString _appType;

private:
    inline static const QString XML_PATH = ":/Flavour/Runner/Settings.json";
};

#endif // APPRUNNERSETTINGS_H
