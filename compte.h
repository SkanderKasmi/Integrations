#ifndef COMPTE_H
#define COMPTE_H

#include "compte_c.h"
#include <QDialog>

namespace Ui {
class compte;
}

class compte : public QDialog
{
    Q_OBJECT

public:
    explicit compte(QWidget *parent = nullptr);
    ~compte();
    void setModifier(int modifier){modif=modifier;}
    int getModifier() {return modif;}

    void setID_comp(int id){id_com=id;}
    int getID_comp() {return id_com;}

    void setData();


private slots:
    void on_pushButton_43_clicked();

private:
    Ui::compte *ui;
    int modif;
    int id_com;
};

#endif // COMPTE_H
