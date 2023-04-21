#ifndef CLIENTMAINWINDOW_H
#define CLIENTMAINWINDOW_H

#include <Client/Logic/ClientGameLogic.h>

#include <QMainWindow>

namespace Ui {
class ClientMainWindow;
}

class ClientMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ClientMainWindow(QWidget *parent = nullptr);
    ~ClientMainWindow();

public:
    void SetLogic(ClientGameLogic* pLogic);

protected:
    void mousePressEvent(QMouseEvent* pEvent) override;
    void mouseReleaseEvent(QMouseEvent* pEvent) override;
    void mouseDoubleClickEvent(QMouseEvent* pEvent) override;
    void mouseMoveEvent(QMouseEvent* pEvent) override;

public slots:
    void OnClientMoveCompleted();
    void OnClientInputLocked();
    void OnClientInputUnlocked();

private:
    Ui::ClientMainWindow* _pUi;
    ClientGameLogic* _pLogic;
};

#endif // CLIENTMAINWINDOW_H
