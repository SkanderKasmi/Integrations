#include "menu.h"
#include "ui_menu.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QStandardPaths>
#include <QDebug>
#include <QFileInfo>

menu::menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
}

menu::~menu()
{
    delete ui;
}


void menu::setData()
{
    int id=getid_elem();
    QSqlQuery query;
    QString res=QString::number(id);

    query.prepare("Select *   from menu where  ID_ELEM= :id");
        query.bindValue(":id",res);
        query.exec();
       while(query.next())

           {
               ui->lineEdit_9->setText(query.value(1).toString());

               ui->lineEdit_7->setText(query.value(2).toString());
           //ui->lineEdit_8->setText(query.value(3).toString());
           ui->lineEdit_10->setText(query.value(4).toString());
            ui->lineEdit_11->setText(query.value(3).toString());

       }

}

void menu::on_pushButton_43_clicked()
{
    if (getModifier()==0)
    {
        QString nom_elem=ui->lineEdit_9->text();
        QString type_elem=ui->lineEdit_7->text();
       QString descrip_elem=ui->lineEdit_11->text();
        int prix_element=ui->lineEdit_10->text().toInt()  ;
        int id_stock=1;
    menu_c m(id_stock,prix_element,nom_elem,type_elem,descrip_elem);
    bool test=m.ajouter_menu();
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
        QString nom_elem=ui->lineEdit_9->text();
        QString type_elem=ui->lineEdit_7->text();
        QString descrip_elem=ui->lineEdit_11->text();
        int prix_element=ui->lineEdit_10->text().toInt()  ;
        int id_elem=getid_elem();
       menu_c m(id_elem,prix_element,nom_elem,type_elem,descrip_elem);
        bool test=m.modifier_menu(id_elem);
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

/*void menu::on_pushButton_105_clicked()
{
     //QString   path =QDir::currentPath();

    photo_path = QFileDialog::getOpenFileName(this ,
                                                    QObject::tr("photo files"),
                                                         "C:/", "photo(*)");
    QFileInfo fi(photo_path);
    QString fileName= fi.fileName();
     qDebug() << photo_path;
     QString img_dir="/esprit/2eme année/projet c++/projet/img/menu/"+fileName;

    QFile::copy(photo_path,img_dir );
    ui->label_21->setText(fileName);
    photo_path=img_dir;

}*/
