#ifndef TCPSOCKERUTILS_H
#define TCPSOCKERUTILS_H

#include <QDataStream>
#include <QByteArray>
#include <QTcpSocket>
#include <QMap>

#include <functional>

class TcpSocketOutProxy
{
public:
    TcpSocketOutProxy();
    ~TcpSocketOutProxy();

public:
    TcpSocketOutProxy& Create();
    TcpSocketOutProxy& Remove();

    TcpSocketOutProxy& SelectForSize();
    TcpSocketOutProxy& Resize();

    TcpSocketOutProxy& SetSocket(QTcpSocket* pSocket);
    TcpSocketOutProxy& SetCommand(quint16 command);

    TcpSocketOutProxy& Send();

    template<typename T>
    TcpSocketOutProxy& Write(const T& value);

    TcpSocketOutProxy& Begin(QTcpSocket* pSocket, quint16 command);
    TcpSocketOutProxy& End();

private:
    QTcpSocket* _pSocket;
    int _command;
    QByteArray* _pPacket;
    QDataStream* _pOut;
};

class TcpSocketInProxy
{
public:
    TcpSocketInProxy();
    ~TcpSocketInProxy();

public:
    TcpSocketInProxy& SetSocket(QTcpSocket* pSocket);

    TcpSocketInProxy& Create();
    TcpSocketInProxy& Remove();

    TcpSocketInProxy& AddCommandHandler(quint16 command, const std::function<void()>& handler);

    TcpSocketInProxy& Wait();

    TcpSocketInProxy& Begin(QTcpSocket* pSocket);
    TcpSocketInProxy& End();

    template<typename T>
    TcpSocketInProxy& Read(T& value);

private:
    QTcpSocket* _pSocket;
    quint16 _packetSize;
    QDataStream* _pIn;
    QMap<quint16, std::function<void()>> _commandsHandlers;
};

template<typename T>
TcpSocketOutProxy& TcpSocketOutProxy::Write(const T& value)
{
    (*_pOut) << value;
    return *this;
}

template<typename T>
TcpSocketInProxy& TcpSocketInProxy::Read(T& value)
{
    (*_pIn) >> value;
    return *this;
}

#endif // TCPSOCKERUTILS_H
