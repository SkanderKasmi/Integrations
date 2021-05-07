#include "stock.h"
#include "ui_stock.h"
#include <QMessageBox>

stock::stock(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stock)
{

    ui->setupUi(this);
}

stock::~stock()
{
    delete ui;
}

void stock::setData()
{
    int id=getid_stock();
    QSqlQuery query;
    QString res=QString::number(id);

    query.prepare("Select *   from stock where  ID_STOCK= :id");
        query.bindValue(":id",res);
        query.exec();
       while(query.next())

           {
               ui->lineEdit_9->setText(query.value(1).toString());

               ui->lineEdit_7->setText(query.value(2).toString());
           ui->lineEdit_8->setText(query.value(3).toString());
       }

}

void stock::on_pushButton_43_clicked()
{
    if (getModifier()==0)
    {
        QString nom_stock=ui->lineEdit_9->text();
        QString type_stock=ui->lineEdit_7->text();
        int quantite_stock=ui->lineEdit_8->text().toInt()  ;
        int id_stock=1;
    stock_c s(id_stock,quantite_stock,nom_stock,type_stock);
    bool test=s.ajouter_stock();
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
        QString nom_stock=ui->lineEdit_9->text();
        QString type_stock=ui->lineEdit_7->text();
        int quantite_stock=ui->lineEdit_8->text().toInt()  ;
        int id_stock=getid_stock();
        stock_c s(id_stock,quantite_stock,nom_stock,type_stock);
        bool test=s.modifier_stock(id_stock);
        if(test)
                        {


                            QMessageBox::information(this, QObject::tr("ok"),
                                                     QObject::tr("modofication effectué\n"
                                                        "Click Cancel to exit."), QMessageBox::Cancel);

                        }
                        else
                        {
                            QMessageBox::critical(this, QObject::tr("Not ok"),
                                                     QObject::tr("modification non effectué\n"
                                                        "Click Cancel to exit."), QMessageBox::Cancel);

                        }
                        hide();
    }
}
