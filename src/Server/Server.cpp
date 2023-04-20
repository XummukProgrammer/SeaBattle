#include "Server.h"

#include <Common/TcpSockerUtils.h>
#include <Server/ServerCommandType.h>
#include <Client/ClientCommandType.h>

#include <QTcpSocket>

Server::Server(QObject* parent)
    : QObject(parent)
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

Client* Server::GetClientFromSocket(QTcpSocket *pSocket) const
{
    for (const auto& pClient : _clients)
    {
        if (pClient->GetSocket() == pSocket)
        {
            return pClient;
        }
    }
    return nullptr;
}

void Server::OnClientConnected()
{
    auto pSocket = _pServer->nextPendingConnection();
    auto pClient = new Client();

    pClient->SetSocket(pSocket);

    connect(pSocket, &QTcpSocket::disconnected, this, &Server::OnClientDisconnected);
    connect(pSocket, &QTcpSocket::readyRead, this, &Server::OnClientReadyRead);

    _clients.push_back(pClient);

    qDebug() << "Client connected: " << pClient->GetIPPortString();
}

void Server::OnClientDisconnected()
{
    auto pSocket = qobject_cast<QTcpSocket*>(sender());
    auto pClient = GetClientFromSocket(pSocket);

    if (pClient)
    {
        qDebug() << "Client disconnected: " << pClient->GetIPPortString();

        for (auto it = _clients.begin(); it != _clients.end(); ++it)
        {
            if (*it == pClient)
            {
                _clients.erase(it);
                break;
            }
        }
    }
}

void Server::OnClientReadyRead()
{
}

