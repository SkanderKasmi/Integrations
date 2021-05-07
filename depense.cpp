#include "depense.h"
#include "ui_depense.h"
#include <QMessageBox>

depense::depense(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::depense)
{
    ui->setupUi(this);
}

depense::~depense()
{
    delete ui;
}

void depense::on_pushButton_43_clicked()
{
    if (getModifier()==0)
    {
        int id;
        QString type_depense=ui->lineEdit_9->text();
        int montant_depense=ui->lineEdit_7->text().toInt();
        QString date_depense=ui->dateEdit->text();
        depense_c D(id,type_depense,montant_depense,date_depense);

bool test=D.ajouter_depense();
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
        int id=getid_depense();
        QString type_depense=ui->lineEdit_9->text();
        int montant_depense=ui->lineEdit_7->text().toInt();
        QString date_depense=ui->dateEdit->text();
        depense_c D(id,type_depense,montant_depense,date_depense);

bool test=D.modifier_depense(id);
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

