#include "employe.h"

employe::employe(int id_employe,QString nom_employe,QString prenom_employe,QString fonction_employe)
{
    this->id_employe=id_employe;
    this->nom_employe=nom_employe;
    this->prenom_employe=prenom_employe;
    this->fonction_employe=fonction_employe;


}

bool employe::ajouter_employe()
{
    QSqlQuery query;
    QString res = QString::number(id_employe);

    query.prepare("insert into employes (NOM_EMPLOYE,PRENOM_EMPLOYE,FONCTION_EMPLOYE)" "values(:nom_employe, :prenom_employe ,:fonction_employe)");

    query.bindValue(":nom_employe",nom_employe);
    query.bindValue(":prenom_employe",prenom_employe);
    query.bindValue(":fonction_employe",fonction_employe);

    return query.exec();

}

QSqlQueryModel * employe::afficher_employe()
{
    QSqlQueryModel *model=new QSqlQueryModel();

    model->setQuery("select ID_EMPLOYE, NOM_EMPLOYE, PRENOM_EMPLOYE, FONCTION_EMPLOYE  from EMPLOYES");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("fonction"));

    return model;


}
bool employe::supprimer_employe(int id_employe)
{
    QSqlQuery query;
    QString res=QString::number(id_employe);

    query.prepare("Delete from employes where ID_EMPLOYE= :id_employe");
    query.bindValue(":id_employe",res);

    return query.exec();
}

bool employe::modifier_employe(int id_employe)
{
    QSqlQuery query;
    QString res = QString::number(id_employe);

    query.prepare("UPDATE employes SET NOM_EMPLOYE=:nom_employe,PRENOM_EMPLOYE=:prenom_employe,FONCTION_EMPLOYE=:fonction_employe where ID_EMPLOYE= :id_employe");

    query.bindValue(":nom_employe",nom_employe);
    query.bindValue(":prenom_employe",prenom_employe);
    query.bindValue(":fonction_employe",fonction_employe);
    query.bindValue(":id_employe",res);

    return query.exec();

}
