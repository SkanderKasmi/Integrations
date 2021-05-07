#include "compte.h"
#include "ui_compte.h"
#include<QMessageBox>

compte::compte(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::compte)
{
    ui->setupUi(this);
}

compte::~compte()
{
    delete ui;
}

void compte::setData()
{
    int id = getID_comp();

    QSqlQuery query;
    QString res=QString::number(id);



    query.prepare("Select *   from compte where ID_COMP= :id");
    query.bindValue(":id",res);
    query.exec();
    while(query.next())
    {
    ui->lineEdit_9->setText(query.value(1).toString());

    ui->lineEdit_7->setText(query.value(2).toString());
    QString type_comp = query.value(3).toString();
    if (type_comp == "Gerent")
    {
        ui->checkBox_2->setChecked(true);
    }

    else if (type_comp == "Caissier")
    {
        ui->checkBox_4->setChecked(true);

    }


    }

}
void compte::on_pushButton_43_clicked()
{
    if ((ui->lineEdit_7->text()=="" && ui->lineEdit_9->text() == "" ) && (!ui->checkBox_2->isChecked() || !ui->checkBox_4->isChecked() )  )
    {
        QMessageBox::information(this, QObject::tr("ok"),
                                 QObject::tr("Remplir les cases vides\n"));


    }
    else
    {
        if (getModifier()==0)
        {
            int id=getID_comp();
            QString email_compte=ui->lineEdit_9->text();
            QString mdp_compte=ui->lineEdit_7->text();
            QString type_compte;
            int confirmation = 1;

            if(ui->checkBox_2->isChecked())
            {
                 ui->checkBox_4->setChecked(false);
                 type_compte="Gerent";
            }

            else if (ui->checkBox_4->isChecked())
            {
                ui->checkBox_2->setChecked(false);
                type_compte="Caissier";
            }

            compte_c  C(id,confirmation,email_compte,mdp_compte,type_compte);
            bool test=C.ajouter_compte();
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
            int id=getID_comp();
            QString email_compte=ui->lineEdit_9->text();
            QString mdp_compte=ui->lineEdit_7->text();
            QString type_compte;
            int confirmation = 1;

            if(ui->checkBox_2->isChecked())
            {
                 ui->checkBox_4->setChecked(false);
                 type_compte="Gerent";
            }

            else if (ui->checkBox_4->isChecked())
            {
                ui->checkBox_2->setChecked(false);
                type_compte="Caissier";
            }

            compte_c  C(id,confirmation,email_compte,mdp_compte,type_compte);
            bool test=C.modifier_compte(id);
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
