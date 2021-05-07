#ifndef COMMANDE_H
#define COMMANDE_H
#include "menu_c.h"
#include "commande_c.h"



#include <QDialog>


namespace Ui {
class commande;
}

class commande : public QDialog
{
    Q_OBJECT

public:

    explicit commande(QWidget *parent = nullptr);
    ~commande();
    void setModifier(int modifier){modif=modifier;}
    int getModifier() {return modif;}
    void setID_commande(int id){id_commande=id;}
    int getID_commande() {return id_commande;}
    int getPrix_commande(){return prix_commande;}

    void setData();



private slots:
    void on_pushButton_34_clicked();

    void on_pushButton_33_clicked();

    void on_pushButton_32_clicked();

    void on_pushButton_43_clicked();

private:
    Ui::commande *ui;
    int modif;
    menu_c etmm;
    int id_commande;
    int prix_commande;
    int type_commande;
    int id_client;
    int id_elem;
    int id_empl;
    int total=0;

    commande_c Aoc;

};

#endif // COMMANDE_H
