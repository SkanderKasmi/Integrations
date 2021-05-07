#ifndef COMMANDE_C_H
#define COMMANDE_C_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDialog>

class commande_c
{
    int id_commande,prix_commande,id_elem,id_empl,id_client;
    QString type_commande;
public:
    commande_c(){}
    commande_c(int, int, QString, int, int, int);
    int getid_commande(){return id_commande;}
    int getprix_commande(){return prix_commande;}
    QString gettype_commande(){return type_commande;}
    int getid_elem(){return id_elem;}
    int getid_empl(){return id_empl;}
    int getid_client(){return id_client;}

    void settype_commande(QString n){type_commande=n;}
    void setid_commande(int id){this->id_commande=id;}
    void setprix_commande(int nbr){this->prix_commande=nbr;}
    void setid_elem(int idelm){this->id_elem=idelm;}
    void setid_empl(int idempl){this->id_empl=idempl;}
    void setid_client(int idclient){this->id_client=idclient;}

    bool ajouter_commande();
    QSqlQueryModel * afficher_commande();
    QSqlQueryModel * afficher_commande_element(int);
    QSqlQueryModel * afficher_commande_element_modif(int);
    bool supprimer_commande(int);
    bool modifier_commande(int);
    bool ajouter_commande_element();
    bool supprimer_commande_element(int);

};

#endif // COMMANDE_C_H
