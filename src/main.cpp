#include <QApplication>

#include <AppRunner/AppRunner.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    AppRunner appRunner;
    appRunner.Run(AppRunnerType::Client);

    return a.exec();
}
