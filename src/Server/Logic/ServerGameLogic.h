#ifndef SERVERGAMELOGIC_H
#define SERVERGAMELOGIC_H

#include <Server/Server.h>
#include <Client/Client.h>

#include <QObject>

class ServerGameLogic : public QObject
{
    Q_OBJECT

public:
    ServerGameLogic();
    ~ServerGameLogic();

public:
    void SetServer(Server* pServer);

private slots:
    void OnClientAdded(Client* pClient);
    void OnClientInputLocked(Client* pClient);

private:
    Server* _pServer;
    Client* _pFirstPlayer;
    Client* _pSecondPlayer;
    Client* _pLockedPlayer;
};

#endif // SERVERGAMELOGIC_H
