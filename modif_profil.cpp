#include "modif_profil.h"
#include "ui_modif_profil.h"
#include <QMessageBox>
#include<QDebug>


MODIF_profil::MODIF_profil(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MODIF_profil)
{
    ui->setupUi(this);


        }

MODIF_profil::~MODIF_profil()
{
    delete ui;
}

void MODIF_profil::setData()
{
    int id = getID_empl();

    QSqlQuery query;
    QString res=QString::number(id);
    qDebug()<< res;
    //qInfo("%d",id) ;

    query.prepare("Select *   from employes where ID_EMPLOYE= :id");
    query.bindValue(":id",res);
    query.exec();
    while(query.next())
    {
    ui->lineEdit_7->setText(query.value(1).toString());

    ui->lineEdit_8->setText(query.value(2).toString());
    QString fonction_employe = query.value(3).toString();
    if (fonction_employe == "Gerent")
    {
        ui->checkBox_2->setChecked(true);
    }
    else if (fonction_employe == "Serveur")
    {
        ui->checkBox_3->setChecked(true);

    }
    else if (fonction_employe == "Caissier")
    {
        ui->checkBox_4->setChecked(true);

    }
    else if (fonction_employe == "Cuisinier")
    {
        ui->checkBox_5->setChecked(true);

    }
    else if (fonction_employe == "nettoyage")
    {
        ui->checkBox_6->setChecked(true);

    }

    }

}
void MODIF_profil::on_pushButton_43_clicked()
{
    if ((ui->lineEdit_7->text()=="" && ui->lineEdit_8->text() == "" ) && (!ui->checkBox_2->isChecked() || !ui->checkBox_3->isChecked() || !ui->checkBox_4->isChecked() || !ui->checkBox_5->isChecked() || !ui->checkBox_6->isChecked())  )
    {
        QMessageBox::information(this, QObject::tr("ok"),
                                 QObject::tr("Remplir les case vide\n"));


    }
    else
    {
        int s = getID_empl();
        qInfo("%d",s);
        if (getModifier()==0)
        {


            QString nom_employe=ui->lineEdit_7->text();
            QString prenom_employe=ui->lineEdit_8->text();
            QString fonction_employe;
            int id=1;
            if(ui->checkBox_2->isChecked())
            {
                 ui->checkBox_3->setChecked(false);
                 ui->checkBox_4->setChecked(false);
                 ui->checkBox_5->setChecked(false);
                 ui->checkBox_6->setChecked(false);
                 fonction_employe="Gerent";
            }
            else if (ui->checkBox_3->isChecked())
            {
                ui->checkBox_2->setChecked(false);
                ui->checkBox_4->setChecked(false);
                ui->checkBox_5->setChecked(false);
                ui->checkBox_6->setChecked(false);
                fonction_employe="Serveur";
            }
            else if (ui->checkBox_4->isChecked())
            {
                ui->checkBox_3->setChecked(false);
                ui->checkBox_2->setChecked(false);
                ui->checkBox_5->setChecked(false);
                ui->checkBox_6->setChecked(false);
                fonction_employe="Caissier";
            }
            else if (ui->checkBox_5->isChecked())
            {
                ui->checkBox_3->setChecked(false);
                ui->checkBox_4->setChecked(false);
                ui->checkBox_2->setChecked(false);
                ui->checkBox_6->setChecked(false);
                fonction_employe="Cuisinier";
            }
            else if (ui->checkBox_6->isChecked())
            {
                ui->checkBox_3->setChecked(false);
                ui->checkBox_4->setChecked(false);
                ui->checkBox_5->setChecked(false);
                ui->checkBox_2->setChecked(false);
                fonction_employe="nettoyage";
            }
            employe  E(id,nom_employe,prenom_employe,fonction_employe);
            bool test=E.ajouter_employe();
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



            int id=getID_empl();
            QString nom_employe=ui->lineEdit_7->text();
            QString prenom_employe=ui->lineEdit_8->text();
            QString fonction_employe;

            if(ui->checkBox_2->isChecked())
            {
                 ui->checkBox_3->setChecked(false);
                 ui->checkBox_4->setChecked(false);
                 ui->checkBox_5->setChecked(false);
                 ui->checkBox_6->setChecked(false);
                 fonction_employe="Gerent";
            }
            else if (ui->checkBox_3->isChecked())
            {
                ui->checkBox_2->setChecked(false);
                ui->checkBox_4->setChecked(false);
                ui->checkBox_5->setChecked(false);
                ui->checkBox_6->setChecked(false);
                fonction_employe="Serveur";
            }
            else if (ui->checkBox_4->isChecked())
            {
                ui->checkBox_3->setChecked(false);
                ui->checkBox_2->setChecked(false);
                ui->checkBox_5->setChecked(false);
                ui->checkBox_6->setChecked(false);
                fonction_employe="Caissier";
            }
            else if (ui->checkBox_5->isChecked())
            {
                ui->checkBox_3->setChecked(false);
                ui->checkBox_4->setChecked(false);
                ui->checkBox_2->setChecked(false);
                ui->checkBox_6->setChecked(false);
                fonction_employe="Cuisinier";
            }
            else if (ui->checkBox_6->isChecked())
            {
                ui->checkBox_3->setChecked(false);
                ui->checkBox_4->setChecked(false);
                ui->checkBox_5->setChecked(false);
                ui->checkBox_2->setChecked(false);
                fonction_employe="nettoyage";
            }
            employe  E(id,nom_employe,prenom_employe,fonction_employe);
            bool test=E.modifier_employe(id);
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
