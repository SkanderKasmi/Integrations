#include "salaire.h"
#include "ui_salaire.h"
#include <QMessageBox>

salaire::salaire(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::salaire)
{
    ui->setupUi(this);
}

salaire::~salaire()
{
    delete ui;
}

void salaire::on_pushButton_43_clicked()
{
    if (getModifier()==0)
    {
        int id_empl=ui->lineEdit_10->text().toInt();
        int montant_empl=ui->lineEdit_9->text().toInt();
        int montant_heure=ui->lineEdit_7->text().toInt();
        QString date_salaire=ui->dateEdit->text();
       salaire_c S(id_empl, montant_empl, montant_heure,date_salaire);

bool test=S.ajouter_salaire();
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
else if(getModifier()==1){
        int id_empl=getid_empl();

        int montant_empl=ui->lineEdit_9->text().toInt();
        int montant_heure=ui->lineEdit_7->text().toInt();
        QString date_salaire=ui->dateEdit->text();
       salaire_c S(id_empl, montant_empl, montant_heure,date_salaire);

bool test=S.modifier_salaire(id_empl);
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
                hide();}

}
