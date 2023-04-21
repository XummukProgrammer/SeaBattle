#include "src/Client/Visual/ClientMainWindow.h"
#include "ui_ClientMainWindow.h"

ClientMainWindow::ClientMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , _pUi(new Ui::ClientMainWindow)
    , _pLogic(nullptr)
{
    _pUi->setupUi(this);
}

ClientMainWindow::~ClientMainWindow()
{
    delete _pUi;
}

void ClientMainWindow::SetLogic(ClientGameLogic* pLogic)
{
    _pLogic = pLogic;
    connect(_pLogic, &ClientGameLogic::MoveCompleted, this, &ClientMainWindow::OnClientMoveCompleted);
    connect(_pLogic, &ClientGameLogic::InputLocked, this, &ClientMainWindow::OnClientInputLocked);
    connect(_pLogic, &ClientGameLogic::InputUnlocked, this, &ClientMainWindow::OnClientInputUnlocked);
}

void ClientMainWindow::mousePressEvent(QMouseEvent* pEvent)
{
    _pLogic->MousePress();
}

void ClientMainWindow::mouseReleaseEvent(QMouseEvent* pEvent)
{
}

void ClientMainWindow::mouseDoubleClickEvent(QMouseEvent* pEvent)
{
}

void ClientMainWindow::mouseMoveEvent(QMouseEvent* pEvent)
{
}

void ClientMainWindow::OnClientMoveCompleted()
{
    _pUi->label->setText("OnClientMoveCompleted");
}

void ClientMainWindow::OnClientInputLocked()
{
    _pUi->label->setText("OnClientInputLocked");
}

void ClientMainWindow::OnClientInputUnlocked()
{
    _pUi->label->setText("OnClientInputUnlocked");
}
