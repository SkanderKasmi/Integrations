#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDialog>



class employe
{
    QString nom_employe,prenom_employe,fonction_employe;
    int id_employe;
public:
    employe () {}
    employe(int,QString,QString,QString);

    QString getNom_employe(){return nom_employe;}
    QString getprenom_employe(){return prenom_employe;}
    QString getfonction_employe(){return fonction_employe;}
    int getid_employ(){return id_employe;}

    void setNom_employe(QString n){nom_employe=n;}
    void setprenom_employe(QString p){prenom_employe=p;}
    void setfonction_employe(QString f){fonction_employe=f;}
    void setid_employ(int id){this->id_employe=id;}

    bool ajouter_employe();
    QSqlQueryModel * afficher_employe();
    bool supprimer_employe(int);
    bool modifier_employe(int);

};

#endif // EMPLOYE_H
