#include "client.h"
#include "ui_client.h"


client::client(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::client)
{
    ui->setupUi(this);
}

client::~client()
{

    delete ui;
}
void client::setData()
{
    int id = getID_client();

    QSqlQuery query;
    QString res=QString::number(id);



    query.prepare("Select *   from client where ID_CLIENT= :id");
    query.bindValue(":id",res);
    query.exec();
    while(query.next())
    {
    ui->lineEdit_9->setText(query.value(1).toString());

    ui->lineEdit_7->setText(query.value(2).toString());



}
}


void client::on_pushButton_43_clicked()
{
    if ((ui->lineEdit_7->text()=="" && ui->lineEdit_9->text() == "")   )
    {
        QMessageBox::information(this, QObject::tr("ok"),
                                 QObject::tr("Remplir les case vide\n"));


    }
    else
    {
        if (getModifier()==0)
        {
            int id=getID_client();
            QString nom_client=ui->lineEdit_9->text();
            int nbr_client=ui->lineEdit_7->text().toInt();




            client_c  C(id,nbr_client,nom_client);
            bool test= C.ajouter_client();
                if(test)
                {


                    QMessageBox::information(this, QObject::tr("ok"),
                                             QObject::tr("Ajout effectué\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);

                }
                else
                {
                    QMessageBox::critical(this, QObject::tr("Not ok"),
                                             QObject::tr("Ajout non effectué\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);

                }
                hide();

       }
        else if (getModifier()==1)
        {
            int id=getID_client();
            QString nom_client=ui->lineEdit_9->text();
            int nbr_client=ui->lineEdit_7->text().toInt();
            client_c C(id,nbr_client,nom_client);
            bool test=C.modifier_client(id);
                if(test)
                {


                    QMessageBox::information(this, QObject::tr("ok"),
                                             QObject::tr("Modification effectué\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);

                }
                else
                {
                    QMessageBox::critical(this, QObject::tr("Not ok"),
                                             QObject::tr("Modification non effectué\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);

                }
                hide();

        }

    }


}



