#include "Client.h"

#include <Common/TcpSockerUtils.h>
#include <Server/ServerCommandType.h>
#include <Client/ClientCommandType.h>

#include <QHostAddress>

#include <QDebug>

Client::Client(QObject* parent)
    : QObject(parent)
    , _pSocket(nullptr)
    , _isConnected(false)
{
}

Client::~Client()
{
}

void Client::Connect()
{
    _pSocket = new QTcpSocket();
    connect(_pSocket, &QTcpSocket::connected, this, &Client::OnConnected);
    connect(_pSocket, &QTcpSocket::disconnected, this, &Client::OnDisconnected);
    connect(_pSocket, &QTcpSocket::readyRead, this, &Client::OnReadyRead);
    _pSocket->connectToHost("127.0.0.1", 3214);
}

void Client::Disconnect()
{
    _pSocket->disconnectFromHost();
}

bool Client::IsConnected() const
{
    return _isConnected;
}

void Client::SetSocket(QTcpSocket* pSocket)
{
    _pSocket = pSocket;
    _isConnected = true;
}

QTcpSocket* Client::GetSocket() const
{
    return _pSocket;
}

QString Client::GetIPPortString() const
{
    auto ipAddress = _pSocket->peerAddress().toString();
    qint16 port = _pSocket->peerPort();
    return ipAddress + ":" + QString::number(port);
}

void Client::OnConnected()
{
    _isConnected = true;
}

void Client::OnDisconnected()
{
    _isConnected = false;
}

void Client::OnReadyRead()
{
}

