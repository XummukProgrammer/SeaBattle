#include "Client.h"

#include <QHostAddress>

Client::Client(QObject* parent)
    : QObject(parent)
    , _pSocket(nullptr)
    , _isConnected(false)
    , _id(0)
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

void Client::SetId(int id)
{
    _id = id;
}

int Client::GetId() const
{
    return _id;
}

void Client::SetSocket(QTcpSocket* pSocket)
{
    _pSocket = pSocket;
    _isConnected = true;
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
