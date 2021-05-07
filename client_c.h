#ifndef CLIENT_C_H
#define CLIENT_C_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDialog>


class client_c
{
    QString nom_client;
    int id_client,nbr_client;
public:
    client_c () {}
    client_c(int,int,QString);

    QString getnom_client(){return nom_client;}
    int getid_client(){return id_client;}
    int getnbr_client(){return nbr_client;}

    void setnom_client(QString n){nom_client=n;}
    void setid_client(int id){this->id_client=id;}
    void setnbr_client(int nbr){this->nbr_client=nbr;}

    bool ajouter_client();
    QSqlQueryModel * afficher_client();
    bool supprimer_client(int);
    bool modifier_client(int);
};

#endif // CLIENT_C_H
