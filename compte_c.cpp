#include "compte_c.h"

compte_c::compte_c(int id_compte,int confirmation,QString email_compte,QString mdp_compte,QString type_compte)
{
    this->id_compte=id_compte;
    this->confirmation=confirmation;
    this->email_compte=email_compte;
    this->mdp_compte=mdp_compte;
    this->type_compte=type_compte;


}

bool compte_c::ajouter_compte()
{
    QSqlQuery query;
    QString res = QString::number(id_compte);
    QString confirm = QString::number(confirmation);

    query.prepare("insert into compte (EMAIL_COMP,MDP_COMP,TYPE_COMP,CONFIRMATION)" "values(:email_compte, :mdp_compte ,:type_compte ,:confirmation)");

    query.bindValue(":email_compte",email_compte);
    query.bindValue(":mdp_compte",mdp_compte);
    query.bindValue(":type_compte",type_compte);
    query.bindValue(":confirmation",confirm);

    return query.exec();

}

QSqlQueryModel * compte_c::afficher_compte()
{
    QSqlQueryModel *model=new QSqlQueryModel();


    model->setQuery("select ID_COMP, EMAIL_COMP, MDP_COMP, TYPE_COMP, CONFIRMATION  from compte where CONFIRMATION=1");

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("email"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("mdp"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("type"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("confirmation"));

    return model;


}
QSqlQueryModel * compte_c::afficher_compte_confirm()
{
    QSqlQueryModel *model=new QSqlQueryModel();


    model->setQuery("select ID_COMP, EMAIL_COMP, MDP_COMP, TYPE_COMP, CONFIRMATION  from compte where CONFIRMATION=0");

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("email"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("mdp"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("type"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("confirmation"));

    return model;


}
bool compte_c::supprimer_compte(int id_compte)
{
    QSqlQuery query;
    QString res=QString::number(id_compte);

    query.prepare("Delete from compte where ID_COMP= :id_compte");
    query.bindValue(":id_compte",res);

    return query.exec();
}

bool compte_c::modifier_compte(int id_compte)
{
    QSqlQuery query;
    QString res = QString::number(id_compte);
    QString confirm = QString::number(confirmation);


    query.prepare("UPDATE compte SET EMAIL_COMP=:email_compte,MDP_COMP=:mdp_compte,TYPE_COMP=:type_compte,CONFIRMATION=:confirmation where ID_COMP= :id_compte");

    query.bindValue(":email_compte",email_compte);
    query.bindValue(":mdp_compte",mdp_compte);
    query.bindValue(":type_compte",type_compte);
    query.bindValue(":confirmation",confirm);
    query.bindValue(":id_compte",res);

    return query.exec();

}
bool compte_c::confirmer_compte(int id_compte)
{
    QSqlQuery query;
    QString res = QString::number(id_compte);


    query.prepare("UPDATE compte SET CONFIRMATION=1 where ID_COMP= :id_compte");


    query.bindValue(":id_compte",res);

    return query.exec();

}
