#include "stock_c.h"

stock_c::stock_c(int id_stock,int quantite_stock,QString nom_stock,QString type_stock)
{
    this->id_stock=id_stock;
    this->nom_stock=nom_stock;
    this->type_stock=type_stock;
    this->quantite_stock=quantite_stock;


}

bool stock_c::ajouter_stock()
{
    QSqlQuery query;
    QString res = QString::number(id_stock);
      QString quantite = QString::number(quantite_stock);

    query.prepare("insert into stock (NOM_STOCK,TYPE_STOCK,QUANTITE_STOCK)" "values(:nom_stock, :type_stock ,:quantite_stock)");

    query.bindValue(":nom_stock",nom_stock);
    query.bindValue(":type_stock",type_stock);
    query.bindValue(":quantite_stock",quantite);

    return query.exec();

}

QSqlQueryModel * stock_c::afficher_stock()
{
    QSqlQueryModel *model=new QSqlQueryModel();

    model->setQuery("select ID_STOCK,NOM_STOCK,TYPE_STOCK,QUANTITE_STOCK from STOCK");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("type"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("quantite"));

    return model;


}
bool stock_c::supprimer_stock(int id_stock)
{
    QSqlQuery query;
    QString res=QString::number(id_stock);


    query.prepare("Delete from stock where ID_STOCK= :id_stock");
    query.bindValue(":id_stock",res);

    return query.exec();
}

bool stock_c::modifier_stock(int id_stock)
{
    QSqlQuery query;
    QString res = QString::number(id_stock);
      QString quantite = QString::number(quantite_stock);

    query.prepare("UPDATE stock SET NOM_STOCK=:nom_stock,TYPE_STOCK=:type_stock,QUANTITE_STOCK=:quantite_stock where ID_STOCK= :id_stock");

    query.bindValue(":nom_stock",nom_stock);
    query.bindValue(":type_stock",type_stock);
    query.bindValue(":quantite_stock",quantite);
    query.bindValue(":id_stock",res);

    return query.exec();

}
