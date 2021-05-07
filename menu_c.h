#ifndef MENU_C_H
#define MENU_C_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDialog>

class menu_c
{
    QString nom_elem,type_elem,descrip_elem;
        int id_elem,prix_element;
    public:
        menu_c () {}
        menu_c(int,int,QString,QString,QString);

        int getid_elem(){return id_elem;}
        int getprix_element(){return prix_element;}
        QString getnom_elem(){return nom_elem;}
        QString gettype_elem(){return type_elem;}
        QString getdescrip_elem(){return descrip_elem;}



        void setnom_elem(QString n){nom_elem=n;}
        void settype_stock(QString p){type_elem=p;}
        void setdescrip_elem(QString m){descrip_elem=m;}
        void setprix_element(int f){this->prix_element=f;}
        void setid_stock(int id){this->id_elem=id;}

        bool ajouter_menu();
        QSqlQueryModel * afficher_menu();
        bool supprimer_menu(int);
        bool modifier_menu(int);
};



#endif // MENU_C_H
