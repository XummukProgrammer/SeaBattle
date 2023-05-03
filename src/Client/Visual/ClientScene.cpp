#include "ClientScene.h"

#include <Client/Visual/ClientField.h>

#include <QPixmap>
#include <QTextEdit>
#include <QPushButton>
#include <QGraphicsProxyWidget>

ClientScene::ClientScene()
    : _pGraphicsView(nullptr)
    , _pGraphicsScene(nullptr)
    , _pForm(nullptr)
    , _pGrid(nullptr)
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

    _pForm = new QGraphicsWidget;
    _pGraphicsScene->addItem(_pForm);

    _pGrid = new QGraphicsGridLayout(_pForm);
}
