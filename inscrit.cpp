#include "inscrit.h"
#include "ui_inscrit.h"
#include "mainwindow.h"
#include "QMessageBox"

inscrit::inscrit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::inscrit)
{
    ui->setupUi(this);
}

inscrit::~inscrit()
{
    delete ui;
}

void inscrit::on_pushButton_4_clicked()
{

    int id=1;
    QString email_compte=ui->lineEdit_3->text();
    QString mdp_compte=ui->lineEdit_4->text();
    QString type_compte;
    int confirmation = 0;

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
                                     QObject::tr("Ajout effectué attendez la confirmation\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
        {
            QMessageBox::critical(this, QObject::tr("Not ok"),
                                     QObject::tr("Ajout non effectué \n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

        }
        hide();


    hide();
    MainWindow *newmain= new MainWindow();
    newmain->show();
}
