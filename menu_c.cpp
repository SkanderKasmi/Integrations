#include "menu_c.h"
#include <QStandardItem>
menu_c::menu_c(int id_elem,int prix_element, QString nom_elem, QString type_elem, QString descrip_elem)
{
    this->id_elem=id_elem;
    this->nom_elem=nom_elem;
    this->type_elem=type_elem;
    this->prix_element=prix_element;
    this->descrip_elem=descrip_elem;


}

bool menu_c::ajouter_menu()
{
    QSqlQuery query;
    QString res = QString::number(id_elem);
      QString prix = QString::number(prix_element);


    query.prepare("insert into menu (NOM_ELEM,TYPE_ELEM,DESCRIP_ELEM,PRIX_ELEM)" "values(:nom_elem, :type_elem ,:descrip_elem ,:prix)");

    query.bindValue(":nom_elem",nom_elem);
    query.bindValue(":type_elem",type_elem);
    query.bindValue(":descrip_elem",descrip_elem);
    query.bindValue(":prix",prix);

    return query.exec();

}

QSqlQueryModel * menu_c::afficher_menu()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select ID_ELEM,NOM_ELEM,TYPE_ELEM,DESCRIP_ELEM,PRIX_ELEM from MENU");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("type"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("description"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("prix"));

    return model;


}
bool menu_c::supprimer_menu(int id_elem)
{
    QSqlQuery query;
    QString res=QString::number(id_elem);


    query.prepare("Delete from menu where ID_ELEM= :id_elem");
    query.bindValue(":id_elem",res);

    return query.exec();
}

bool menu_c::modifier_menu(int id_elem)
{
    QSqlQuery query;
    QString res = QString::number(id_elem);
      QString quantite = QString::number(prix_element);

    query.prepare("UPDATE menu SET NOM_ELEM=:nom_elem,TYPE_ELEM=:type_elem,DESCRIP_ELEM=:descrip_elem , PRIX_ELEM=:prix_element where ID_ELEM= :id_elem");

    query.bindValue(":nom_elem",nom_elem);
    query.bindValue(":type_elem",type_elem);
     query.bindValue(":descrip_elem",descrip_elem);
    query.bindValue(":prix_element",prix_element);
    query.bindValue(":id_elem",res);

    return query.exec();

}
