#ifndef COMPTE_C_H
#define COMPTE_C_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDialog>



class compte_c
{
    QString email_compte,mdp_compte,type_compte;
    int id_compte,confirmation;
public:
    compte_c () {}
    compte_c(int,int,QString,QString,QString);

    QString getemail_compte(){return email_compte;}
    QString getmdp_compte(){return mdp_compte;}
    QString gettype_compte(){return type_compte;}
    int getconfirmation(){return confirmation;}
    int getid_compte(){return id_compte;}

    void setemail_compte(QString n){email_compte=n;}
    void setmdp_compte(QString p){mdp_compte=p;}
    void settype_compte(QString f){type_compte=f;}
    void setconfirmation(int confir){this->confirmation=confir;}
    void setid_compte(int id){this->id_compte=id;}

    bool ajouter_compte();
    QSqlQueryModel * afficher_compte();
    QSqlQueryModel * afficher_compte_confirm();

    bool supprimer_compte(int);
    bool modifier_compte(int);
    bool confirmer_compte(int);


};

#endif // COMPTE_C_H
