#include <QApplication>

#include <AppRunner/AppRunner.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    g_AppRunner.SetApplication(&app);
    return g_AppRunner.Exec();
}
