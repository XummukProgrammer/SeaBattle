#include "ServerGameLogic.h"

ServerGameLogic::ServerGameLogic()
    : _pServer(nullptr)
    , _pFirstPlayer(nullptr)
    , _pSecondPlayer(nullptr)
    , _pLockedPlayer(nullptr)
{
}

ServerGameLogic::~ServerGameLogic()
{
}

void ServerGameLogic::SetServer(Server* pServer)
{
    _pServer = pServer;
    connect(_pServer, &Server::ClientAdded, this, &ServerGameLogic::OnClientAdded);
    connect(_pServer, &Server::ClientInputLocked, this, &ServerGameLogic::OnClientInputLocked);
}

void ServerGameLogic::OnClientAdded(Client* pClient)
{
    if (!_pFirstPlayer)
    {
        _pFirstPlayer = pClient;
    }
    else if (!_pSecondPlayer)
    {
        _pSecondPlayer = pClient;
    }
}

void ServerGameLogic::OnClientInputLocked(Client* pClient)
{
    _pLockedPlayer = pClient;
    Client* pUnlockedPlayer = nullptr;

    if (_pFirstPlayer == _pLockedPlayer)
    {
        pUnlockedPlayer = _pSecondPlayer;
    }
    else if (_pSecondPlayer == _pLockedPlayer)
    {
        pUnlockedPlayer = _pFirstPlayer;
    }

    _pServer->ClientInputUnlock(pUnlockedPlayer);
}
