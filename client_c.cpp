#include "client_c.h"

client_c::client_c(int id_client,int nbr_client,QString nom_client)
{
    this->id_client=id_client;
    this->nbr_client=nbr_client;
    this->nom_client=nom_client;


}

bool client_c::ajouter_client()
{
    QSqlQuery query;
    QString res = QString::number(id_client);
    QString confirm = QString::number(nbr_client);

    query.prepare("insert into client (NOM_CLIENT,NBR_CLIENT)" "values(:nom_client, :nbr_client)");

    query.bindValue(":nom_client",nom_client);
    query.bindValue(":nbr_client",nbr_client);


    return query.exec();

}

QSqlQueryModel * client_c::afficher_client()
{
    QSqlQueryModel *model=new QSqlQueryModel();

    model->setQuery("select ID_CLIENT, NOM_CLIENT, NBR_CLIENT    from client");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("nbr"));


    return model;


}
bool client_c::supprimer_client(int id_client)
{
    QSqlQuery query;
    QString res=QString::number(id_client);

    query.prepare("Delete from client where ID_CLIENT= :id_client");
    query.bindValue(":id_client",res);

    return query.exec();
}

bool client_c::modifier_client(int id_client)
{
    QSqlQuery query;
    QString res = QString::number(id_client);
    QString nombre = QString::number(nbr_client);


    query.prepare("UPDATE client SET NOM_CLIENT=:nom_client,NBR_CLIENT=:nbr_client where ID_CLIENT= :id_client");

    query.bindValue(":nom_client",nom_client);
    query.bindValue(":nbr_client",nombre);
    query.bindValue(":id_client",res);

    return query.exec();

}
