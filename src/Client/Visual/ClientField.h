#ifndef CLIENTFIELD_H
#define CLIENTFIELD_H

#include <QWidget>

namespace Ui {
class ClientField;
}

class ClientField : public QWidget
{
    Q_OBJECT

public:
    explicit ClientField(QWidget *parent = nullptr);
    ~ClientField();

private:
    Ui::ClientField *ui;
};

#endif // CLIENTFIELD_H
