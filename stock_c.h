#ifndef STOCK_C_H
#define STOCK_C_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDialog>

class stock_c
{
    QString nom_stock,type_stock;
        int id_stock,quantite_stock;
    public:
        stock_c () {}
        stock_c(int,int,QString,QString);

        int getid_stock(){return id_stock;}
        int getquantite_stock(){return quantite_stock;}
        QString getnom_stock(){return nom_stock;}
        QString gettype_stock(){return type_stock;}



        void setnom_stock(QString n){nom_stock=n;}
        void settype_stock(QString p){type_stock=p;}
        void setquantite_stock(int f){this->quantite_stock=f;}
        void setid_stock(int id){this->id_stock=id;}

        bool ajouter_stock();
        QSqlQueryModel * afficher_stock();
        bool supprimer_stock(int);
        bool modifier_stock(int);
};




#endif // STOCK_C_H
