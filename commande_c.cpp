#include "commande_c.h"

commande_c::commande_c(int id_commande,int prix_commande,QString type_commande, int id_client,int id_elem,int id_empl)
{
    this->id_commande=id_commande;
    this->prix_commande=prix_commande;
    this->type_commande=type_commande;
    this->id_client=id_client;
    this->id_elem=id_elem;
    this->id_empl=id_empl;

}
bool commande_c::ajouter_commande()
{
    QSqlQuery query;
    QString res = QString::number(id_commande);
    QString total = QString::number(prix_commande);


    query.prepare("insert into commande (ID_COMMANDE,TYPE_COMMANDE,PRIX_COMMANDE,ID_ELEM,ID_EMPL,ID_CLIENT)" "values(:res ,:type_commande, :prix_commande, :id_elem ,:id_empl , :id_client )");

    query.bindValue(":type_commande",type_commande);
    query.bindValue(":prix_commande",total);
    query.bindValue(":id_elem",id_elem);
    query.bindValue(":id_empl",id_empl);
    query.bindValue(":id_client",id_client);
    query.bindValue(":res",res);



    return query.exec();

}

QSqlQueryModel * commande_c::afficher_commande()
{
    QSqlQueryModel *model=new QSqlQueryModel();

    model->setQuery("select ID_COMMANDE, TYPE_COMMANDE, PRIX_COMMANDE,ID_EMPL,ID_CLIENT   from commande where PRIX_COMMANDE IS NOT NULL");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("type"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("total"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("id_empl"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("id_client"));





    return model;


}
bool commande_c::supprimer_commande(int id_commande)
{
    QSqlQuery query;
    QString res=QString::number(id_commande);

    query.prepare("Delete from commande where ID_COMMANDE = :id_commande");
    query.bindValue(":id_commande",res);

    return query.exec();
}

bool commande_c::modifier_commande(int id_commande)
{
    QSqlQuery query;
    QString res = QString::number(id_commande);
    QString nombre = QString::number(prix_commande);


    query.prepare("UPDATE commande SET ID_COMMANDE=:id_commande,TYPE_COMMANDE=:type_commande,PRIX_COMMANDE=:prix_commande,ID_ELEM=:id_elem,ID_EMPL=:id_empl,ID_CLIENT=:id_client where ID_COMMANDE= :id_commande");

    query.bindValue(":type_commande",type_commande);
    query.bindValue(":prix_commande",nombre);
    query.bindValue(":id_commande",res);
    query.bindValue(":id_elem",id_elem);
    query.bindValue(":id_empl",id_empl);
    query.bindValue(":id_client",id_client);

    return query.exec();

}
bool commande_c::ajouter_commande_element()
{
    QSqlQuery query;
    QString res = QString::number(id_commande);
    query.prepare("insert into commande (ID_COMMANDE,ID_ELEM)" "values(:res  ,:id_elem  )");
    query.bindValue(":id_elem",id_elem);
    query.bindValue(":res",res);
    return query.exec();

}
QSqlQueryModel * commande_c::afficher_commande_element(int id_commande)
{
    QString res = QString::number(id_commande);
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select M.ID_ELEM,M.NOM_ELEM,M.TYPE_ELEM,M.DESCRIP_ELEM,M.PRIX_ELEM,C.ID_COMMANDE,C.ID_ELEM from MENU M,COMMANDE C where C.ID_COMMANDE='"+res+"' AND C.ID_ELEM=M.ID_ELEM");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("type"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("description"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("prix"));

    return model;


}
QSqlQueryModel * commande_c::afficher_commande_element_modif(int id_commande)
{
    QString res = QString::number(id_commande);
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select DISTINCT C.ID_ELEM ,m.nom_elem , m.prix_elem from COMMANDE C INNER JOIN MENU M on   C.ID_ELEM=M.ID_ELEM where C.id_commande='"+res+"'");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prix"));


    return model;


}
bool commande_c::supprimer_commande_element(int id_elem)
{
    QSqlQuery query;
    QString res=QString::number(id_elem);

    query.prepare("Delete from commande where  ID_ELEM=:id_elem");
    query.bindValue(":id_elem",res);

    return query.exec();
}

