#include "Server.h"

#include <Common/TcpSockerUtils.h>
#include <Server/ServerCommandType.h>

#include <QTcpSocket>

Server::Server(QObject* parent)
    : QObject(parent)
    , _clientId(0)
{
}

Server::~Server()
{
}

void Server::Start()
{
    _pServer = new QTcpServer();
    _pServer->setMaxPendingConnections(2);

    connect(_pServer, &QTcpServer::newConnection, this, &Server::OnClientConnected);

    if (_pServer->listen(QHostAddress::LocalHost, 3214))
    {
        qDebug() << "Server successfull started";
    }
    else
    {
        qDebug() << "An error occurred on the server: " + _pServer->errorString();
    }
}

void Server::OnClientConnected()
{
    auto pSocket = _pServer->nextPendingConnection();
    auto pClient = new Client();

    pClient->SetId(_clientId);
    ++_clientId;

    pClient->SetSocket(pSocket);

    connect(pSocket, &QTcpSocket::disconnected, this, &Server::OnClientDisconnected);

    qDebug() << "Client connected: " << pClient->GetIPPortString();

    _clients.push_back(pClient);

    TcpSocketOutProxy proxy;
    proxy.Begin(pSocket, static_cast<quint16>(ServerCommandType::ClientAuthorized)).Write(pClient->GetId()).End();
}

void Server::OnClientDisconnected()
{
    qDebug() << "Client disconnected: ";
}
