#include "TcpSockerUtils.h"

TcpSocketOutProxy::TcpSocketOutProxy()
    : _pSocket(nullptr)
    , _command(0)
    , _pPacket(nullptr)
    , _pOut(nullptr)
{
}

TcpSocketOutProxy::~TcpSocketOutProxy()
{
}

TcpSocketOutProxy& TcpSocketOutProxy::Create()
{
    _pPacket = new QByteArray();
    _pOut = new QDataStream(_pPacket, QIODevice::WriteOnly);
    return *this;
}

TcpSocketOutProxy& TcpSocketOutProxy::Remove()
{
    delete _pPacket;
    delete _pOut;

    _pSocket = nullptr;
    _pPacket = nullptr;
    _pOut = nullptr;
    _command = 0;

    return *this;
}

TcpSocketOutProxy& TcpSocketOutProxy::SelectForSize()
{
    (*_pOut) << static_cast<quint16>(0);
    return *this;
}

TcpSocketOutProxy& TcpSocketOutProxy::Resize()
{
    _pOut->device()->seek(0);
    (*_pOut) << static_cast<quint16>(_pPacket->size() - sizeof(quint16));
    return *this;
}

TcpSocketOutProxy &TcpSocketOutProxy::SetSocket(QTcpSocket* pSocket)
{
    _pSocket = pSocket;
    return *this;
}

TcpSocketOutProxy& TcpSocketOutProxy::SetCommand(quint16 command)
{
    (*_pOut) << command;
    return *this;
}

TcpSocketOutProxy &TcpSocketOutProxy::Send()
{
    _pSocket->write(*_pPacket);
    return *this;
}

TcpSocketOutProxy& TcpSocketOutProxy::Begin(QTcpSocket* pSocket, quint16 command)
{
    Create().SelectForSize().SetSocket(pSocket).SetCommand(command);
    return *this;
}

TcpSocketOutProxy &TcpSocketOutProxy::End()
{
    Resize().Send().Remove();
    return *this;
}

TcpSocketInProxy::TcpSocketInProxy()
    : _pSocket(nullptr)
    , _packetSize(0)
    , _pIn(nullptr)
{
}

TcpSocketInProxy::~TcpSocketInProxy()
{
}

TcpSocketInProxy& TcpSocketInProxy::SetSocket(QTcpSocket* pSocket)
{
    _pSocket = pSocket;
    return *this;
}

TcpSocketInProxy& TcpSocketInProxy::Create()
{
    _pIn = new QDataStream(_pSocket);
    return *this;
}

TcpSocketInProxy& TcpSocketInProxy::Remove()
{
    delete _pIn;

    _pSocket = nullptr;
    _pIn = nullptr;

    _commandsHandlers.clear();

    return *this;
}

TcpSocketInProxy &TcpSocketInProxy::AddCommandHandler(quint16 command, const std::function<void()>& handler)
{
    _commandsHandlers[command] = handler;
    return *this;
}

TcpSocketInProxy& TcpSocketInProxy::Wait()
{
    for (;;)
    {
        if (_packetSize == 0)
        {
            if (_pSocket->bytesAvailable() < static_cast<int>(sizeof(quint16)))
            {
                break;
            }

            (*_pIn) >> _packetSize;
        }

        if (_pSocket->bytesAvailable() < _packetSize)
        {
            break;
        }
        else
        {
            _packetSize = 0;
        }

        quint16 command;
        (*_pIn) >> command;

        auto it = _commandsHandlers.find(command);
        if (it != _commandsHandlers.end())
        {
            auto& value = it.value();
            if (value)
            {
                value();
            }
        }
    }

    return *this;
}

TcpSocketInProxy& TcpSocketInProxy::Begin(QTcpSocket* pSocket)
{
    SetSocket(pSocket).Create();
    return *this;
}

TcpSocketInProxy& TcpSocketInProxy::End()
{
    Wait().Remove();
    return *this;
}
