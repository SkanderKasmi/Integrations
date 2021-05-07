#include "depense_c.h"

depense_c::depense_c(int id_depense,QString type_depense,int montant_depense,QString date_depense)
{
    this->id_depense=id_depense;
    this->type_depense=type_depense;
    this->montant_depense=montant_depense;
    this->date_depense=date_depense;

}
bool depense_c::ajouter_depense()
{
    QSqlQuery query;
    query.prepare("insert into depense (type_depense,montant_depense,date_depense) values (:type_depense,:montant_depense,:date_depense)");
    query.bindValue(":type_depense",type_depense);
    query.bindValue(":date_depense",date_depense);
    query.bindValue(":montant_depense",montant_depense);
    return query.exec();



}
QSqlQueryModel * depense_c::afficher_depense()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select id_depense,type_depense,montant_depense,date_depense from depense");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("type"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("montant"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("date"));
    return model;

}
bool depense_c::modifier_depense(int id_depense)
{
    QSqlQuery query;
    QString rs=QString::number(id_depense);
    query.prepare("update depense set type_depense=:type_depense,montant_depense=:montant_depense,date_depense=:date_depense where id_depense=:id_depense");
    query.bindValue(":type_depense",type_depense);
    query.bindValue(":date_depense",date_depense);
    query.bindValue(":montant_depense",montant_depense);
    query.bindValue(":id_depense",rs);
    return query.exec();
}
bool depense_c::supprimer_depense(int id_depense)
{
    QSqlQuery query;
    QString rs=QString::number(id_depense);
    query.prepare("delete from depense where id_depense=:id_depense");
    query.bindValue(":id_depense",rs);
    return query.exec();

}
