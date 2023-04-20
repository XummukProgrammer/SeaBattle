#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QString>

class Client : public QObject
{
    Q_OBJECT

public:
    explicit Client(QObject* parent = nullptr);
    ~Client();

public:
    void Connect();
    void Disconnect();
    bool IsConnected() const;

    void SetId(int id);
    int GetId() const;

    void SetSocket(QTcpSocket* pSocket);

    QString GetIPPortString() const;

public slots:
    void OnConnected();
    void OnDisconnected();
    void OnReadyRead();

private:
    void OnAuthorized(int id);

private:
    int _id;
    QTcpSocket* _pSocket;
    bool _isConnected;
};

#endif // CLIENT_H
