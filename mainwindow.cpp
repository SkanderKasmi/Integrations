#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_4_clicked()
{
    QSqlQuery query;
    QString email_compte=ui->lineEdit_3->text();
    QString mdp_compte=ui->lineEdit_4->text();

    if ((ui->lineEdit_3->text()=="" && ui->lineEdit_4->text() == "" ) )
    {
        QMessageBox::information(this, QObject::tr("ok"),
                                 QObject::tr("Remplir les cases vides\n"));


    }
    else
    {
        query.prepare("SELECT EMAIL_COMP,MDP_COMP,CONFIRMATION,TYPE_COMP  from compte WHERE  EMAIL_COMP=:email_compte AND MDP_COMP=:mdp_compte AND CONFIRMATION=1 ");
        query.bindValue(":email_compte", email_compte);
        query.bindValue(":mdp_compte", mdp_compte);
        if (query.exec())
        {
            if (query.next())
            {
                if(query.value(3).toString()=="Gerent")
                {
                    hide();
                    accu =new acceuil(this);

                    accu->show();
                  }
                else
                {
                    hide();
                    comm = new commande(this);

                    comm->show();
                }
            }
            else
            {
                QMessageBox::information(this, QObject::tr("ok"),
                                         QObject::tr("Email ou Mot de passe incorrecte\n"));

            }
        }
    }
}

void MainWindow::on_pushButton_5_clicked()
{
            hide();
            Inscrit =new inscrit(this);

            Inscrit->show();
}

void MainWindow::on_pushButton_6_clicked()
{
    hide();
    MDP =new mdp_oubli(this);

    MDP->show();

}
