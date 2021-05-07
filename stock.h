#ifndef STOCK_H
#define STOCK_H
#include "stock_c.h"

#include <QDialog>

namespace Ui {
class stock;
}

class stock : public QDialog
{
    Q_OBJECT

public:
    explicit stock(QWidget *parent = nullptr);
    ~stock();
    void setModifier(int modifier){modif=modifier;}
    int getModifier() {return modif;}

    void setid_stock(int id){id_stock=id;}
    int getid_stock() {return id_stock;}

    void setData();

private slots:
    void on_pushButton_43_clicked();


private:
    Ui::stock *ui;
    int modif;
    int id_stock;
};

#endif // STOCK_H
