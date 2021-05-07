#ifndef SALAIRE_C_H
#define SALAIRE_C_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDialog>


class salaire_c
{
    QString date_salaire;
        int id_empl,montant_empl,montant_heure;
    public:
        salaire_c() {}
        salaire_c(int,int,int,QString);

        QString getdate_salaire(){return date_salaire;}
        int getid_empl(){return id_empl;}
        int getmontant_empl(){return montant_empl;}
        int getmontant_heure(){return montant_heure;}

        void setdate_salaire(QString s){date_salaire=s;}
        void setid_empl(int id){this->id_empl=id;}
        void setmontant_empl(int montant){this->montant_empl=montant;}
        void setmontant_heure(int heure){this->montant_heure=heure;}

        bool ajouter_salaire();
        QSqlQueryModel * afficher_salaire ();
        bool supprimer_salaire(int);
        bool modifier_salaire(int);

};

#endif // SALAIRE_C_H
