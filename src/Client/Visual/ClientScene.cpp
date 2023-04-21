#include "ClientScene.h"

#include <QGraphicsTextItem>

ClientScene::ClientScene()
    : _pGraphicsView(nullptr)
    , _pGraphicsScene(nullptr)
{
}

ClientScene::~ClientScene()
{
}

void ClientScene::SetGraphicsView(QGraphicsView* pGraphicsView)
{
    _pGraphicsView = pGraphicsView;

    _pGraphicsScene = new QGraphicsScene(_pGraphicsView);
    _pGraphicsView->setScene(_pGraphicsScene);

    _pGraphicsScene->addItem(new QGraphicsTextItem("Hello, World!"));
}
