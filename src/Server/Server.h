#ifndef SERVER_H
#define SERVER_H

#include <Client/Client.h>

#include <QObject>
#include <QTcpServer>

class Server : public QObject
{
    Q_OBJECT

public:
    explicit Server(QObject* parent = nullptr);
    ~Server();

public:
    void Start();

    Client* GetClientFromSocket(QTcpSocket* pSocket) const;

public slots:
    void OnClientConnected();
    void OnClientDisconnected();
    void OnClientReadyRead();

private:
    void OnClientInputLocked(Client* pClient);

private:
    QTcpServer* _pServer;
    QVector<Client*> _clients;
};

#endif // SERVER_H
