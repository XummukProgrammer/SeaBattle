#ifndef CLIENTSCENE_H
#define CLIENTSCENE_H

#include <QObject>

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsWidget>
#include <QGraphicsGridLayout>
#include <QGraphicsProxyWidget>
#include <QString>

class ClientScene : public QObject
{
    Q_OBJECT

public:
    ClientScene();
    ~ClientScene();

public:
    void SetGraphicsView(QGraphicsView* pGraphicsView);

    template<typename T, typename ... Args>
    T* MakeGraphicsWidget(int x, int y, Args&& ... args);

private:
    QGraphicsView* _pGraphicsView;
    QGraphicsScene* _pGraphicsScene;
    QGraphicsWidget* _pForm;
    QGraphicsGridLayout* _pGrid;
};

template<typename T, typename ... Args>
T* ClientScene::MakeGraphicsWidget(int x, int y, Args&& ... args)
{
    auto pWidget = new T(std::forward<Args>(args)...);
    QGraphicsWidget* pGraphicsWidget = _pGraphicsScene->addWidget(pWidget);
    _pGrid->addItem(pGraphicsWidget, y, x);
    return pWidget;
}

#endif // CLIENTSCENE_H
