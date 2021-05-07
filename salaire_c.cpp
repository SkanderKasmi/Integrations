#include "salaire_c.h"

salaire_c::salaire_c(int id_empl,int montant_empl,int montant_heure,QString date_salaire)
{
    this->id_empl=id_empl;
    this->montant_empl=montant_empl;
    this->montant_heure=montant_heure;
    this->date_salaire=date_salaire;

}
bool salaire_c::ajouter_salaire()
{
    QSqlQuery query;
    query.prepare("insert into salaire (id_empl,montant_empl,montant_heuresupp,date_salaire) values (:id_empl,:montant_empl,:montant_heuresupp,:date_salaire)");
    query.bindValue(":id_empl",id_empl);
    query.bindValue(":montant_heuresupp",montant_heure);
    query.bindValue(":date_salaire",date_salaire);
    query.bindValue(":montant_empl",montant_empl);
    return query.exec();

}
QSqlQueryModel * salaire_c::afficher_salaire()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select id_empl,montant_empl,montant_heuresupp,date_salaire from salaire");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("montant"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("heures supp"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("date"));
    return model;

}
bool salaire_c::modifier_salaire(int id_empl)
{
    QSqlQuery query;
    QString rs=QString::number(id_empl);
    query.prepare("update salaire set montant_empl=:montant_empl,montant_heuresupp=:montant_heuresupp,date_salaire=:date_salaire where id_empl=:id_empl");
    query.bindValue(":montant_empl",montant_empl);
    query.bindValue(":date_salaire",date_salaire);
    query.bindValue(":montant_heuresupp",montant_heure);
    query.bindValue(":id_empl",rs);
    return query.exec();
}
bool salaire_c::supprimer_salaire(int id_empl)
{
    QSqlQuery query;
    QString rs=QString::number(id_empl);
    query.prepare("delete from salaire where id_empl=:id_empl");
    query.bindValue(":id_empl",rs);
    return query.exec();

}

