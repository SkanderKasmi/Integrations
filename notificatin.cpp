#include "notificatin.h"
#include "ui_notificatin.h"

notificatin::notificatin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::notificatin)
{
    ui->setupUi(this);
    QSqlQuery query;


    QString nom_sto;
    query.prepare("Select *   from stock where QUANTITE_STOCK < 5");
    query.exec();
    while(query.next())
    {
   nom_sto.append(query.value(0).toString()+" : "+query.value(1).toString()+" - "+query.value(2).toString()+" - "+query.value(3).toString()+" KG"+"\n");




}
     ui->label_15->setText(nom_sto);
}

notificatin::~notificatin()
{
    delete ui;
}

void notificatin::on_pushButton_43_clicked()
{
     hide();
}
