#ifndef DEPENSE_C_H
#define DEPENSE_C_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDialog>


class depense_c
{QString type_depense,date_depense;
    int id_depense,montant_depense;
public:
    depense_c() {}
    depense_c(int,QString,int,QString);
    QString gettype_depense(){return type_depense;}
    QString getdate_depense(){return date_depense;}
    int getid_depense(){return id_depense;}
    int getmontant_depense(){return montant_depense;}
    void settype_depense(QString m){type_depense=m;}
    void setdate_depense(QString s){date_depense=s;}
    void setid_depense(int id){this->id_depense=id;}
    void setmontant_depense(int montant){this->montant_depense=montant;}

    bool ajouter_depense();
    QSqlQueryModel * afficher_depense ();
    bool supprimer_depense(int);
    bool modifier_depense(int);


};

#endif // DEPENSE_C_H
