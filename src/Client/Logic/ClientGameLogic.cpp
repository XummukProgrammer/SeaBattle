#include "ClientGameLogic.h"

ClientGameLogic::ClientGameLogic()
    : _isInputLocked(false)
    , _pClient(nullptr)
{
}

ClientGameLogic::~ClientGameLogic()
{
}

void ClientGameLogic::SetClient(Client* pClient)
{
    _pClient = pClient;
    connect(_pClient, &Client::InputUnlock, this, &ClientGameLogic::InputUnlock);
}

void ClientGameLogic::MousePress()
{
    if (!_isInputLocked)
    {
        OnMousePress();
    }
}

void ClientGameLogic::OnInputLock()
{
    _isInputLocked = true;
    _pClient->OnInputLocked();

    emit InputLocked();
}

void ClientGameLogic::OnInputUnlock()
{
    _isInputLocked = false;

    emit InputUnlocked();
}

void ClientGameLogic::OnMousePress()
{
    emit MoveCompleted();

    OnInputLock();
}

void ClientGameLogic::InputUnlock()
{
    OnInputUnlock();
}
