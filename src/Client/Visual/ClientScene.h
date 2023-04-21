#ifndef CLIENTSCENE_H
#define CLIENTSCENE_H

#include <QObject>

#include <QGraphicsView>
#include <QGraphicsScene>

class ClientScene : public QObject
{
    Q_OBJECT

public:
    ClientScene();
    ~ClientScene();

public:
    void SetGraphicsView(QGraphicsView* pGraphicsView);

private:
    QGraphicsView* _pGraphicsView;
    QGraphicsScene* _pGraphicsScene;
};

#endif // CLIENTSCENE_H
