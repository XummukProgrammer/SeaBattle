#ifndef CLIENTGAMELOGIC_H
#define CLIENTGAMELOGIC_H

#include <QObject>
#include <Client/Client.h>

class ClientGameLogic : public QObject
{
    Q_OBJECT

public:
    ClientGameLogic();
    ~ClientGameLogic();

public:
    void SetClient(Client* pClient);

    void MousePress();

public:
    void OnInputLock();
    void OnInputUnlock();

private:
    void OnMousePress();

signals:
    void MoveCompleted();
    void InputLocked();
    void InputUnlocked();

public slots:
    void InputUnlock();

private:
    Client* _pClient;
    bool _isInputLocked;
};

#endif // CLIENTGAMELOGIC_H
