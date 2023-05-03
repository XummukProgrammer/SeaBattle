#include "src/Client/Visual/ClientField.h"
#include "ui_ClientField.h"

ClientField::ClientField(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientField)
{
    ui->setupUi(this);
}

ClientField::~ClientField()
{
    delete ui;
}
