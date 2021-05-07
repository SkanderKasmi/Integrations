#include "acceuil.h"
#include "ui_acceuil.h"
#include "mainwindow.h"


acceuil::acceuil(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::acceuil)
{
    ui->setupUi(this);


    QHeaderView *headerGoods = ui->tableView_9->horizontalHeader();

    ui->tableView_5->setModel(Aoc.afficher_commande());
    //ui->tableView_9->setModel(Etmp.afficher_employe());
    ui->tableView_10->setModel(Etmc.afficher_compte());
    ui->tableView_12->setModel(Etmc.afficher_compte_confirm());
    ui->tableView_6->setModel(Etms.afficher_stock());
    ui->tableView_13->setModel(Etmm.afficher_menu());
    filter_empl= new QSortFilterProxyModel(this);
    filter_empl->setSourceModel(Etmp.afficher_employe());
    filter_empl->setFilterCaseSensitivity(Qt::CaseInsensitive);
    ui->tableView_9->setModel(filter_empl);
    ui->tableView_9->setSortingEnabled(true);
    //ui->tableView_9->sortByColumn(0, Qt::AscendingOrder);
    headerGoods->setSortIndicatorShown(true);

    filter_stock= new QSortFilterProxyModel(this);
        filter_stock->setSourceModel(Etms.afficher_stock());
        filter_stock->setFilterCaseSensitivity(Qt::CaseInsensitive);
        ui->tableView_6->setModel(filter_stock);
        ui->tableView_6->setSortingEnabled(true);

        filter_menu= new QSortFilterProxyModel(this);
            filter_menu->setSourceModel(Etmm.afficher_menu());
            filter_menu->setFilterCaseSensitivity(Qt::CaseInsensitive);
             ui->tableView_13->setModel(filter_menu);

             filter_client= new QSortFilterProxyModel(this);
                 filter_client->setSourceModel(Etml.afficher_client());
                 filter_client->setFilterCaseSensitivity(Qt::CaseInsensitive);
                 ui->tableView_11->setModel(filter_client);
                 ui->tableView_11->setSortingEnabled(true);


                 filter_depense= new QSortFilterProxyModel(this);
                 filter_depense->setSourceModel(Etmd.afficher_depense());
                 filter_depense->setFilterCaseSensitivity(Qt::CaseInsensitive);
                 ui->tableView_7->setModel(filter_depense);

                 filter_salaire= new QSortFilterProxyModel(this);
                 filter_salaire->setSourceModel(Etmsa.afficher_salaire());
                 filter_salaire->setFilterCaseSensitivity(Qt::CaseInsensitive);
                 ui->tableView_8->setModel(filter_salaire);

                 ui->tableView_8->setSortingEnabled(true);


    //arduino
    int ret=A.connect_arduino();
    switch(ret)
    {
      case(0):qDebug()<<"arduino is available and connected to :"<< A.getarduino_port_name();
        break;
      case(1):qDebug()<<"arduino is availble but not connected to :"<<A.getarduino_port_name();
        break;
     case(-1):qDebug() << "arduino is not available";

    }
    QSqlQuery query;



    query.prepare("Select *   from stock where quantite_stock < 5");
    query.exec();
    if(query.next())
    {
    QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(message_mouv()));
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
                    notifyIcon->show();
                    notifyIcon->setIcon(QIcon("icone.png"));

                    notifyIcon->showMessage("GESTION Stock ","Manque dans quantité",QSystemTrayIcon::Information,15000);
        }






}

acceuil::~acceuil()
{
    delete ui;
}
void acceuil::message_mouv()
{
    data=A.read_from_arduino();
    QString ff = data;
    qDebug() <<ff;
    if (data=="1")
    {
        QMessageBox::critical(this, QObject::tr("CLIENT"),
                                 QObject::tr("Nouveau client\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
    }
   else if (data=="2")
       {
        QMessageBox::critical(this, QObject::tr("Commande"),
                                 QObject::tr("Une commande est prete\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
    }
}
void acceuil::on_pushButton_109_clicked()
{



    prof_employ =new MODIF_profil(this);
    prof_employ->setModifier(0);
    prof_employ->show();
    filter_empl= new QSortFilterProxyModel(this);
    filter_empl->setSourceModel(Etmp.afficher_employe());
    filter_empl->setFilterCaseSensitivity(Qt::CaseInsensitive);
    ui->tableView_9->setModel(filter_empl);
    ui->tableView_9->setSortingEnabled(true);
    //ui->tableView_9->sortByColumn(0, Qt::AscendingOrder);
}

void acceuil::on_pushButton_110_clicked()
{
    Compte =new compte(this);
    Compte->setModifier(0);

    Compte->show();
}

void acceuil::on_pushButton_11_clicked()
{
    int id_employe =ui->lineEdit_26->text().toInt();
    QSqlQuery query;
    QString res=QString::number(id_employe);


    query.prepare("Select *   from employes where ID_EMPLOYE= :id_employe");
    query.bindValue(":id_employe",res);
    query.exec();
    if(query.next())
    {
        if (id_employe !=  NULL)
        {

            prof_employ =new MODIF_profil(this);
            prof_employ->setModifier(1);
            prof_employ->setID_empl(id_employe);
            prof_employ->setData();

            prof_employ->show();
            filter_empl= new QSortFilterProxyModel(this);
            filter_empl->setSourceModel(Etmp.afficher_employe());
            filter_empl->setFilterCaseSensitivity(Qt::CaseInsensitive);
            ui->tableView_9->setModel(filter_empl);
            ui->tableView_9->setSortingEnabled(true);
            //ui->tableView_9->sortByColumn(0, Qt::AscendingOrder);

          }
        else
        {
            QMessageBox::critical(this, QObject::tr("Not ok"),
                                     QObject::tr("Remplir ID\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
        }
    }
    else
    {
        QMessageBox::critical(this, QObject::tr("Not ok"),
                                 QObject::tr("ID incorrect\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

    }

}

void acceuil::on_pushButton_12_clicked()
{
    int id_compte =ui->lineEdit_27->text().toInt();
    QSqlQuery query;
    QString res=QString::number(id_compte);


    query.prepare("Select *   from compte where ID_COMP= :id_compte");
    query.bindValue(":id_compte",res);
    query.exec();
    if(query.next())
    {
        if (id_compte !=  NULL)
        {

            Compte =new compte(this);
            Compte->setModifier(1);
            Compte->setID_comp(id_compte);
            Compte->setData();

            Compte->show();
         }
        else
        {
            QMessageBox::critical(this, QObject::tr("Not ok"),
                                     QObject::tr("Remplir ID\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
        }
    }
    else
    {
        QMessageBox::critical(this, QObject::tr("Not ok"),
                                 QObject::tr("ID incorrect\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

    }

}

void acceuil::on_pushButton_107_clicked()
{

            Salaire =new salaire(this);
            Salaire->setModifier(0);

            Salaire->show();

}

void acceuil::on_pushButton_14_clicked()
{
    int id_empl=ui->lineEdit_28->text().toInt();
    QSqlQuery query;
    QString res=QString::number(id_empl);


    query.prepare("Select *   from salaire where ID_EMPL= :id_employe");
    query.bindValue(":id_employe",res);
    query.exec();
    if(query.next())
    {
        if (id_empl !=  NULL)
        {
            Salaire =new salaire(this);
            Salaire->setModifier(1);
            Salaire->setid_empl(id_empl);

            Salaire->show();
        }
        else
        {
            QMessageBox::critical(this, QObject::tr("Not ok"),
                                     QObject::tr("Remplir ID\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
        }

    }
    else
    {
        QMessageBox::critical(this, QObject::tr("Not ok"),
                                 QObject::tr("ID incorrect\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

    }

}

void acceuil::on_pushButton_108_clicked()
{

            Depense =new depense(this);
            Depense->setModifier(0);

            Depense->show();
}

void acceuil::on_pushButton_15_clicked()
{
    int id_depense=ui->lineEdit_29->text().toInt();
    Depense =new depense(this);
    Depense->setModifier(1);
    Depense->setid_depense(id_depense);

    Depense->show();
}

void acceuil::on_pushButton_59_clicked()
{

            Commande =new commande(this);
            Commande->setModifier(0);
            ui->tableView_5->setModel(Aoc.afficher_commande());
            Commande->show();
}

void acceuil::on_pushButton_7_clicked()
{
    int id_commande =ui->lineEdit_15->text().toInt();
    QSqlQuery query;
    QString res=QString::number(id_commande);


    query.prepare("Select *   from commande where ID_COMMANDE= :id_commande");
    query.bindValue(":id_commande",res);
    query.exec();
    if(query.next())
    {
        if (id_commande !=  NULL)
        {
            Commande =new commande(this);
            Commande->setModifier(1);;
            Commande->setID_commande(id_commande);
            Commande->setData();
            Commande->show();


         }
        else
        {
            QMessageBox::critical(this, QObject::tr("Not ok"),
                                     QObject::tr("Remplir ID\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
        }
    }
    else
    {
        QMessageBox::critical(this, QObject::tr("Not ok"),
                                 QObject::tr("ID incorrect\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

    }
}

void acceuil::on_pushButton_104_clicked()
{

    Client =new client(this);
    Client->setModifier(0);
    filter_client= new QSortFilterProxyModel(this);
        filter_client->setSourceModel(Etml.afficher_client());
        filter_client->setFilterCaseSensitivity(Qt::CaseInsensitive);
        ui->tableView_11->setModel(filter_client);
        ui->tableView_11->setSortingEnabled(true);

    Client->show();
}

void acceuil::on_pushButton_17_clicked()
{
    int id_client =ui->lineEdit_31->text().toInt();
    QSqlQuery query;
    QString res=QString::number(id_client);


    query.prepare("Select *   from client where ID_CLIENT= :id_client");
    query.bindValue(":id_client",res);
    query.exec();
    if(query.next())
    {
        if (id_client !=  NULL)
        {
            Client =new client(this);
            Client->setModifier(1);
            Client->setID_client(id_client);
            Client->setData();
            Client->show();


         }
        else
        {
            QMessageBox::critical(this, QObject::tr("Not ok"),
                                     QObject::tr("Remplir ID\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
        }
    }
    else
    {
        QMessageBox::critical(this, QObject::tr("Not ok"),
                                 QObject::tr("ID incorrect\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

    }

}

void acceuil::on_pushButton_105_clicked()
{

            Stock =new stock(this);
            Stock->setModifier(0);

            Stock->show();
}

void acceuil::on_pushButton_16_clicked()
{
    int id_stock =ui->lineEdit_30->text().toInt();
    QSqlQuery query;
    QString res=QString::number(id_stock);


    query.prepare("Select *   from stock where ID_STOCK= :id_stock");
    query.bindValue(":id_stock",res);
    query.exec();
    if(query.next())
    {
        if (id_stock !=  NULL)
        {

    Stock =new stock(this);
    Stock->setModifier(1);
    Stock->setid_stock(id_stock);
    Stock->setData();
    Stock->show();
}
        else
        {
            QMessageBox::critical(this, QObject::tr("Not ok"),
                                     QObject::tr("Remplir ID\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
        }
    }
    else
    {
        QMessageBox::critical(this, QObject::tr("Not ok"),
                                 QObject::tr("ID incorrect\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

    }
}

void acceuil::on_pushButton_106_clicked()
{

            Menu =new menu(this);
            Menu->setModifier(0);

            Menu->show();
}

void acceuil::on_pushButton_33_clicked()
{
    int id_elem =ui->lineEdit_32->text().toInt();
    QSqlQuery query;
    QString res=QString::number(id_elem);


    query.prepare("Select *   from menu where ID_ELEM= :id_elem");
    query.bindValue(":id_elem",res);
    query.exec();
    if(query.next())
    {
        if (id_elem !=  NULL)
        {

    Menu =new menu(this);
    Menu->setModifier(1);
    Menu->setid_elem(id_elem);
    Menu->setData();
    Menu->show();
}
        else
        {
            QMessageBox::critical(this, QObject::tr("Not ok"),
                                     QObject::tr("Remplir ID\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
        }
    }
    else
    {
        QMessageBox::critical(this, QObject::tr("Not ok"),
                                 QObject::tr("ID incorrect\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

    }

}


void acceuil::on_pushButton_34_clicked()
{
    hide();
    MainWindow *newmain= new MainWindow();
    newmain->show();
}

void acceuil::on_pushButton_30_clicked()
{
    int id_employe =ui->lineEdit_26->text().toInt();
    QSqlQuery query;
    QString res=QString::number(id_employe);


    query.prepare("Select *   from employes where ID_EMPLOYE= :id_employe");
    query.bindValue(":id_employe",res);
    query.exec();
    if(query.next())
    {
        if (id_employe != NULL)
        {

            bool test=Etmp.supprimer_employe(id_employe);
            if (test)
            {
                filter_empl= new QSortFilterProxyModel(this);
                filter_empl->setSourceModel(Etmp.afficher_employe());
                filter_empl->setFilterCaseSensitivity(Qt::CaseInsensitive);
                ui->tableView_9->setModel(filter_empl);
                ui->tableView_9->setSortingEnabled(true);
                //ui->tableView_9->sortByColumn(0, Qt::AscendingOrder);
                QMessageBox::information(this, QObject::tr("ok"),
                                         QObject::tr("Supression effectué\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
            }
            else
            {
                QMessageBox::critical(this, QObject::tr("Not ok"),
                                         QObject::tr("Supression non effectué\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);

            }
        }
        else
        {
            QMessageBox::critical(this, QObject::tr("Not ok"),
                                     QObject::tr("Remplir ID\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

        }
    }
    else
    {
        QMessageBox::critical(this, QObject::tr("Not ok"),
                                 QObject::tr("ID incorrect\n"));
    }
}

void acceuil::on_pushButton_35_clicked()
{
    filter_empl= new QSortFilterProxyModel(this);
    filter_empl->setSourceModel(Etmp.afficher_employe());
    filter_empl->setFilterCaseSensitivity(Qt::CaseInsensitive);
    ui->tableView_9->setModel(filter_empl);
    ui->tableView_9->setSortingEnabled(true);
    //ui->tableView_9->sortByColumn(0, Qt::AscendingOrder);
    ui->tableView_10->setModel(Etmc.afficher_compte());

}

void acceuil::on_pushButton_38_clicked()
{
    int id_compte =ui->lineEdit_27->text().toInt();
    QSqlQuery query;
    QString res=QString::number(id_compte);


    query.prepare("Select *   from compte where ID_COMP= :id_compte");
    query.bindValue(":id_compte",res);
    query.exec();
    if(query.next())
    {
        if (id_compte !=  NULL)
        {

            bool test=Etmc.supprimer_compte(id_compte);
            if (test)
            {
                ui->tableView_10->setModel(Etmc.afficher_compte());
                QMessageBox::information(this, QObject::tr("ok"),
                                         QObject::tr("Supression effectué\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
            }
            else
            {
                QMessageBox::critical(this, QObject::tr("Not ok"),
                                         QObject::tr("Supression non effectué\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);

            }
        }
        else
        {
            QMessageBox::critical(this, QObject::tr("Not ok"),
                                     QObject::tr("Remplir ID\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

        }
    }
    else
    {
        QMessageBox::critical(this, QObject::tr("Not ok"),
                                 QObject::tr("ID incorrect\n"));
    }

}

void acceuil::on_pushButton_13_clicked()
{
    int id_compte =ui->lineEdit_33->text().toInt();
    QSqlQuery query;
    QString res=QString::number(id_compte);


    query.prepare("Select *   from compte where ID_COMP= :id_compte");
    query.bindValue(":id_compte",res);
    query.exec();
    if(query.next())
    {
        if (id_compte !=  NULL)
        {
            bool test=Etmc.confirmer_compte(id_compte);
            if (test)
            {
                ui->tableView_12->setModel(Etmc.afficher_compte_confirm());
                ui->tableView_10->setModel(Etmc.afficher_compte());
                QMessageBox::information(this, QObject::tr("ok"),
                                         QObject::tr("Confirmation effectué\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
            }
            else
            {
                QMessageBox::critical(this, QObject::tr("Not ok"),
                                         QObject::tr("Confirmation non effectué\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);

            }
        }
        else
        {
            QMessageBox::critical(this, QObject::tr("Not ok"),
                                     QObject::tr("Remplir ID\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

        }
    }
    else
    {
        QMessageBox::critical(this, QObject::tr("Not ok"),
                                 QObject::tr("ID incorrect\n"));
    }


}

void acceuil::on_pushButton_31_clicked()
{
    int id_compte =ui->lineEdit_33->text().toInt();
    QSqlQuery query;
    QString res=QString::number(id_compte);


    query.prepare("Select *   from compte where ID_COMP= :id_compte");
    query.bindValue(":id_compte",res);
    query.exec();
    if(query.next())
    {
        if (id_compte !=  NULL)
        {

            bool test=Etmc.supprimer_compte(id_compte);
            if (test)
            {
                ui->tableView_12->setModel(Etmc.afficher_compte_confirm());
                QMessageBox::information(this, QObject::tr("ok"),
                                         QObject::tr("Supression effectué\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
            }
            else
            {
                QMessageBox::critical(this, QObject::tr("Not ok"),
                                         QObject::tr("Supression non effectué\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);

            }
        }
        else
        {
            QMessageBox::critical(this, QObject::tr("Not ok"),
                                     QObject::tr("Remplir ID\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

        }
    }
    else
    {
        QMessageBox::critical(this, QObject::tr("Not ok"),
                                 QObject::tr("ID incorrect\n"));
    }


}

void acceuil::on_pushButton_36_clicked()
{
    filter_empl= new QSortFilterProxyModel(this);
    filter_empl->setSourceModel(Etmp.afficher_employe());
    filter_empl->setFilterCaseSensitivity(Qt::CaseInsensitive);
    ui->tableView_9->setModel(filter_empl);
    ui->tableView_9->setSortingEnabled(true);
    //ui->tableView_9->sortByColumn(0, Qt::AscendingOrder);
    ui->tableView_10->setModel(Etmc.afficher_compte());
    ui->tableView_12->setModel(Etmc.afficher_compte_confirm());
}

void acceuil::on_lineEdit_34_textChanged(const QString &arg1)
{
    filter_empl->setFilterFixedString(arg1);
}

void acceuil::on_comboBox_currentIndexChanged(int index)
{
    filter_empl->setFilterKeyColumn(index);


}

void acceuil::on_pushButton_18_clicked()
{
    const QString format("<td>%1</td>");
        QString html;
        QAbstractItemModel *md = ui->tableView_9->model();
        html = "<html><body><table border=\"0\">";

        html += "<td></td>";
        for(int column = 0; column < md->columnCount();
            column++) {
            QString data = md->headerData(column, Qt::Horizontal, Qt::DisplayRole).toString();
            html += format.arg(data);
        }
        for(int row = 0; row < md->rowCount() ; row++) {
            html += "<tr>";
            QString data = md->headerData(row, Qt::Vertical, Qt::DisplayRole).toString();
            html += format.arg(data);
            for(int column = 0; column < md->columnCount();
                column++) {
                QString data = md->index(row, column).data(Qt::DisplayRole).toString();
                html += format.arg(data);
            }
            html += "</tr>";
        }
        html += "</table></body></html>";

        QPrinter printer;
        QPrintDialog *dialog = new QPrintDialog(&printer,this);
        if(dialog->exec() == QDialog::Accepted) {
            QTextDocument document;
            document.setHtml(html);
            document.print(&printer);
        }

}
void acceuil::on_pushButton_42_clicked()
{
    int id_client =ui->lineEdit_31->text().toInt();
    QSqlQuery query;
    QString res=QString::number(id_client);


    query.prepare("Select *   from client where ID_CLIENT= :id_client");
    query.bindValue(":id_client",res);
    query.exec();
    if(query.next())
    {
        if (res !=NULL)
        {

            bool test=Etml.supprimer_client(id_client);
            if (test)
            {
                QMessageBox::information(this, QObject::tr("ok"),
                                         QObject::tr("Supression effectué\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
                ui->tableView_11->setModel(Etml.afficher_client());

            }
            else
            {
                QMessageBox::critical(this, QObject::tr("Not ok"),
                                         QObject::tr("Supression non effectué\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);

            }
        }
        else
        {
            QMessageBox::critical(this, QObject::tr("Not ok"),
                                     QObject::tr("Remplir ID\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

        }
    }
    else
    {
        QMessageBox::critical(this, QObject::tr("Not ok"),
                                 QObject::tr("ID incorrect\n"));
    }
}

void acceuil::on_pushButton_43_clicked()
{
    filter_client= new QSortFilterProxyModel(this);
        filter_client->setSourceModel(Etml.afficher_client());
        filter_client->setFilterCaseSensitivity(Qt::CaseInsensitive);
        ui->tableView_11->setModel(filter_client);
        ui->tableView_11->setSortingEnabled(true);
    ui->tableView_5->setModel(Aoc.afficher_commande());
}
void acceuil::on_pushButton_44_clicked()
{
    filter_stock= new QSortFilterProxyModel(this);
        filter_stock->setSourceModel(Etms.afficher_stock());
        filter_stock->setFilterCaseSensitivity(Qt::CaseInsensitive);
        ui->tableView_6->setModel(filter_stock);
        ui->tableView_6->setSortingEnabled(true);
        QSqlQuery query;



        query.prepare("Select *   from stock where quantite_stock < 5");
        query.exec();
        if(query.next())
        {
        QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(message_mouv()));
        QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
                        notifyIcon->show();
                        notifyIcon->setIcon(QIcon("icone.png"));

                        notifyIcon->showMessage("GESTION Stock ","Manque dans quantité",QSystemTrayIcon::Information,15000);
            }
}


void acceuil::on_pushButton_41_clicked()
{
    int id_stock =ui->lineEdit_30->text().toInt();
    QSqlQuery query;
    QString res=QString::number(id_stock);


    query.prepare("Select *   from stock where ID_STOCK= :id_stock");
    query.bindValue(":id_stock",res);
    query.exec();
    if(query.next())
    {
        if (res !=NULL)
        {

            bool test=Etms.supprimer_stock(id_stock);
            if (test)
            {

                QMessageBox::information(this, QObject::tr("ok"),
                                         QObject::tr("Supression effectué\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);

                filter_stock= new QSortFilterProxyModel(this);
                    filter_stock->setSourceModel(Etms.afficher_stock());
                    filter_stock->setFilterCaseSensitivity(Qt::CaseInsensitive);
                    ui->tableView_6->setModel(filter_stock);
                    ui->tableView_6->setSortingEnabled(true);
            }
            else
            {
                QMessageBox::critical(this, QObject::tr("Not ok"),
                                         QObject::tr("Supression non effectué\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);

            }
        }
        else
        {
            QMessageBox::critical(this, QObject::tr("Not ok"),
                                     QObject::tr("Remplir ID\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

        }
    }
    else
    {
        QMessageBox::critical(this, QObject::tr("Not ok"),
                                 QObject::tr("ID incorrect\n"));
    }


}

void acceuil::on_pushButton_45_clicked()
{
    filter_menu= new QSortFilterProxyModel(this);
        filter_menu->setSourceModel(Etmm.afficher_menu());
        filter_menu->setFilterCaseSensitivity(Qt::CaseInsensitive);
         ui->tableView_13->setModel(filter_menu);
}

void acceuil::on_pushButton_32_clicked()
{
    int id_elem =ui->lineEdit_32->text().toInt();
        bool test = Etmm.supprimer_menu(id_elem);
        if (test)
        {
            filter_menu= new QSortFilterProxyModel(this);
                filter_menu->setSourceModel(Etmm.afficher_menu());
                filter_menu->setFilterCaseSensitivity(Qt::CaseInsensitive);
                 ui->tableView_13->setModel(filter_menu);
            QMessageBox::information(this, QObject::tr("ok"),
                                     QObject::tr("Supression effectué\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
        {
            QMessageBox::critical(this, QObject::tr("Not ok"),
                                     QObject::tr("Supression non effectué\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

        }
}
void acceuil::on_pushButton_19_clicked()
{
    const QString format("<td>%1</td>");
            QString html;
            QAbstractItemModel *md = ui->tableView_13->model();
            html = "<html><body><table border=\"0\">";

            html += "<td></td>";
            for(int column = 0; column < md->columnCount();
                column++) {
                QString data = md->headerData(column, Qt::Horizontal, Qt::DisplayRole).toString();
                html += format.arg(data);
            }
            for(int row = 0; row < md->rowCount() ; row++) {
                html += "<tr>";
                QString data = md->headerData(row, Qt::Vertical, Qt::DisplayRole).toString();
                html += format.arg(data);
                for(int column = 0; column < md->columnCount();
                    column++) {
                    QString data = md->index(row, column).data(Qt::DisplayRole).toString();
                    html += format.arg(data);
                }
                html += "</tr>";
            }
            html += "</table></body></html>";

            QPrinter printer;
            QPrintDialog *dialog = new QPrintDialog(&printer,this);
            if(dialog->exec() == QDialog::Accepted) {
                QTextDocument document;
                document.setHtml(html);
                document.print(&printer);
            }
}
void acceuil::on_lineEdit_35_textChanged(const QString &arg1)
{
    filter_menu->setFilterFixedString(arg1);
}

void acceuil::on_comboBox_2_currentIndexChanged(int index)
{
    filter_menu->setFilterKeyColumn(index);
}




void acceuil::on_pushButton_21_clicked()
{
    Notificatin =new notificatin(this);

    Notificatin->show();

}
void acceuil::on_pushButton_27_clicked()
{
    int id_commande =ui->lineEdit_15->text().toInt();
    QSqlQuery query;
    QString res=QString::number(id_commande);


    query.prepare("Select *   from commande where ID_COMMANDE= :id_commande");
    query.bindValue(":id_commande",res);
    query.exec();
    if(query.next())
    {
        if (res !=NULL)
        {

            bool test=Aoc.supprimer_commande(id_commande);
            if (test)
            {

                QMessageBox::information(this, QObject::tr("ok"),
                                         QObject::tr("Supression effectué\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
                ui->tableView_5->setModel(Aoc.afficher_commande());
            }
            else
            {
                QMessageBox::critical(this, QObject::tr("Not ok"),
                                         QObject::tr("Supression non effectué\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);

            }
        }
        else
        {
            QMessageBox::critical(this, QObject::tr("Not ok"),
                                     QObject::tr("Remplir ID\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

        }
    }
    else
    {
        QMessageBox::critical(this, QObject::tr("Not ok"),
                                 QObject::tr("ID incorrect\n"));
    }
}

void acceuil::on_lineEdit_36_textChanged(const QString &arg1)
{
    filter_client->setFilterFixedString(arg1);

}

void acceuil::on_comboBox_3_currentIndexChanged(int index)
{
    filter_client->setFilterKeyColumn(index);
}

void acceuil::on_pushButton_20_clicked()
{
    const QString format("<td>%1</td>");
            QString html;
            QAbstractItemModel *md = ui->tableView_11->model();
            html = "<html><body><table border=\"0\">";

            html += "<td></td>";
            for(int column = 0; column < md->columnCount();
                column++) {
                QString data = md->headerData(column, Qt::Horizontal, Qt::DisplayRole).toString();
                html += format.arg(data);
            }
            for(int row = 0; row < md->rowCount() ; row++) {
                html += "<tr>";
                QString data = md->headerData(row, Qt::Vertical, Qt::DisplayRole).toString();
                html += format.arg(data);
                for(int column = 0; column < md->columnCount();
                    column++) {
                    QString data = md->index(row, column).data(Qt::DisplayRole).toString();
                    html += format.arg(data);
                }
                html += "</tr>";
            }
            html += "</table></body></html>";

            QPrinter printer;
            QPrintDialog *dialog = new QPrintDialog(&printer,this);
            if(dialog->exec() == QDialog::Accepted) {
                QTextDocument document;
                document.setHtml(html);
                document.print(&printer);
            }
}

void acceuil::on_pushButton_37_clicked()
{
    filter_depense= new QSortFilterProxyModel(this);
    filter_depense->setSourceModel(Etmd.afficher_depense());
    filter_depense->setFilterCaseSensitivity(Qt::CaseInsensitive);
    ui->tableView_7->setModel(filter_depense);

    filter_salaire= new QSortFilterProxyModel(this);
    filter_salaire->setSourceModel(Etmsa.afficher_salaire());
    filter_salaire->setFilterCaseSensitivity(Qt::CaseInsensitive);
    ui->tableView_8->setModel(filter_salaire);

    ui->tableView_8->setSortingEnabled(true);

}

void acceuil::on_lineEdit_38_textChanged(const QString &arg1)
{
filter_depense->setFilterFixedString(arg1);

}

void acceuil::on_comboBox_5_currentIndexChanged(int index)
{
    filter_depense->setFilterKeyColumn(index);
}

void acceuil::on_pushButton_67_clicked()
{
    const QString format("<td>%1</td>");
        QString html;
        QAbstractItemModel *md = ui->tableView_8->model();
        html = "<html><body><table border=\"0\">";

        html += "<td></td>";
        for(int column = 0; column < md->columnCount();
            column++) {
            QString data = md->headerData(column, Qt::Horizontal, Qt::DisplayRole).toString();
            html += format.arg(data);
        }
        for(int row = 0; row < md->rowCount() ; row++) {
            html += "<tr>";
            QString data = md->headerData(row, Qt::Vertical, Qt::DisplayRole).toString();
            html += format.arg(data);
            for(int column = 0; column < md->columnCount();
                column++) {
                QString data = md->index(row, column).data(Qt::DisplayRole).toString();
                html += format.arg(data);
            }
            html += "</tr>";
        }
        html += "</table></body></html>";

        QPrinter printer;
        QPrintDialog *dialog = new QPrintDialog(&printer,this);
        if(dialog->exec() == QDialog::Accepted) {
            QTextDocument document;
            document.setHtml(html);
            document.print(&printer);
        }
}
void acceuil::on_pushButton_39_clicked()
{
    int id_empl=ui->lineEdit_28->text().toInt();
    bool test = Etmsa.supprimer_salaire(id_empl);
    if (test)
    {
        filter_salaire= new QSortFilterProxyModel(this);
        filter_salaire->setSourceModel(Etmsa.afficher_salaire());
        filter_salaire->setFilterCaseSensitivity(Qt::CaseInsensitive);
        ui->tableView_8->setModel(filter_salaire);

        ui->tableView_8->setSortingEnabled(true);

        //ui->tableView_9->sortByColumn(0, Qt::AscendingOrder);
        QMessageBox::information(this, QObject::tr("ok"),
                                 QObject::tr("Supression effectué\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(this, QObject::tr("Not ok"),
                                 QObject::tr("Supression non effectué\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

    }
}
void acceuil::on_pushButton_40_clicked()
{
    int id_depense=ui->lineEdit_29->text().toInt();
    QSqlQuery query;
    QString res=QString::number(id_depense);


    query.prepare("Select *   from depense where ID_depense= :id_depense");
    query.bindValue(":id_depense",res);
    query.exec();
    if(query.next())
    {
        if (id_depense !=  NULL)
        {
        bool test = Etmd.supprimer_depense(id_depense);
        if (test)
        {
            filter_depense= new QSortFilterProxyModel(this);
            filter_depense->setSourceModel(Etmd.afficher_depense());
            filter_depense->setFilterCaseSensitivity(Qt::CaseInsensitive);
            ui->tableView_7->setModel(filter_depense);

            filter_salaire= new QSortFilterProxyModel(this);
            filter_salaire->setSourceModel(Etmsa.afficher_salaire());
            filter_salaire->setFilterCaseSensitivity(Qt::CaseInsensitive);
            ui->tableView_8->setModel(filter_salaire);

            ui->tableView_8->setSortingEnabled(true);

            //ui->tableView_9->sortByColumn(0, Qt::AscendingOrder);
            QMessageBox::information(this, QObject::tr("ok"),
                                     QObject::tr("Supression effectué\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
        {
            QMessageBox::critical(this, QObject::tr("Not ok"),
                                     QObject::tr("Supression non effectué\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

        }
        }
        else
        {
            QMessageBox::critical(this, QObject::tr("Not ok"),
                                     QObject::tr("Remplir ID\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
        }

    }
    else
    {
        QMessageBox::critical(this, QObject::tr("Not ok"),
                                 QObject::tr("ID incorrect\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

    }
}
void acceuil::notif()
{
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
                    notifyIcon->show();
                    notifyIcon->setIcon(QIcon("icone.png"));

                    notifyIcon->showMessage("GESTION Materiel ","Materiel Ajouté",QSystemTrayIcon::Information,15000);
}

void acceuil::on_pushButton_68_clicked()
{
    Stat =new statis(this);

    Stat->show();
}
