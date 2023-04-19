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

public slots:
    void OnClientConnected();
    void OnClientDisconnected();

private:
    QTcpServer* _pServer;
    QVector<Client*> _clients;
    int _clientId;
};

#endif // SERVER_H
