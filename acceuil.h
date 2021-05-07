#ifndef ACCEUIL_H
#define ACCEUIL_H

#include <QDialog>
#include "modif_profil.h"
#include "compte.h"
#include "salaire.h"
#include "depense.h"
#include "commande.h"
#include "client.h"
#include "stock.h"
#include "menu.h"
#include "menu_c.h"
#include "employe.h"
#include "compte_c.h"
#include "client_c.h"
#include "stock_c.h"
#include <QSortFilterProxyModel>
#include <QTextDocument>
#include <QTextTableCell>
#include <QTableWidgetItem>
#include <QMessageBox>
#include <QPrintDialog>
#include <QPrinter>
#include "arduino.h"
#include "notificatin.h"
#include <QDebug>
#include "commande_c.h"
#include "depense_c.h"
#include "salaire_c.h"
#include <QSystemTrayIcon>
#include "statis.h"



namespace Ui {
class acceuil;



}

class acceuil : public QDialog
{
    Q_OBJECT



public:
    explicit acceuil(QWidget *parent = nullptr);
    ~acceuil();
    QSortFilterProxyModel * filter_empl;
    QSortFilterProxyModel * filter_stock;
    QSortFilterProxyModel * filter_menu;
     QSortFilterProxyModel * filter_client;
     QSortFilterProxyModel * filter_depense;
     QSortFilterProxyModel * filter_salaire;







private slots:
    void on_pushButton_109_clicked();

    void on_pushButton_110_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_107_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_108_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_59_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_104_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_105_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_106_clicked();

    void on_pushButton_33_clicked();

    void on_pushButton_34_clicked();

    void on_pushButton_30_clicked();

    void on_pushButton_35_clicked();
    void on_pushButton_38_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_31_clicked();

    void on_pushButton_36_clicked();

    void on_lineEdit_34_textChanged(const QString &arg1);

    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_18_clicked();
    void on_pushButton_43_clicked();

    void on_pushButton_42_clicked();
    void on_pushButton_44_clicked();

    void on_pushButton_41_clicked();

    void on_pushButton_45_clicked();

    void on_pushButton_32_clicked();
    void message_mouv();
    void on_lineEdit_35_textChanged(const QString &arg1);

    void on_comboBox_2_currentIndexChanged(int index);

    void on_pushButton_19_clicked();


    void on_pushButton_21_clicked();

    void on_pushButton_27_clicked();

    void on_lineEdit_36_textChanged(const QString &arg1);

    void on_comboBox_3_currentIndexChanged(int index);

    void on_pushButton_20_clicked();
    void on_pushButton_37_clicked();

    void on_pushButton_40_clicked();

    void on_pushButton_39_clicked();

    void on_lineEdit_38_textChanged(const QString &arg1);

    void on_comboBox_5_currentIndexChanged(int index);

    void on_pushButton_67_clicked();
    void notif();


    void on_pushButton_68_clicked();

signals :
    void modifi (int);
private:
    Ui::acceuil *ui;
    MODIF_profil *prof_employ;
    compte *Compte;
    salaire *Salaire;
    depense *Depense;
    commande *Commande;
    notificatin *Notificatin;
    client *Client;
    stock *Stock;
    menu *Menu;
    employe Etmp;
    compte_c Etmc;
    client_c Etml;
    stock_c Etms;
    menu_c Etmm;
    QByteArray data;
    arduino A;
    commande_c Aoc;
    depense_c Etmd;
    salaire_c Etmsa;
    statis *Stat;





};

#endif // ACCEUIL_H
