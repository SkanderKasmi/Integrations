#ifndef CLIENT_H
#define CLIENT_H

#include "client_c.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDialog>
#include <QMessageBox>
#include <QDialog>


namespace Ui {
class client;
}

class client : public QDialog
{
    Q_OBJECT

public:
    explicit client(QWidget *parent = nullptr);
    ~client();
    void setModifier(int modifier){modif=modifier;}
    int getModifier() {return modif;}

    void setID_client(int id){id_client=id;}
    int getID_client() {return id_client;}

    void setData();




private slots:
    void on_pushButton_43_clicked();

private:
    Ui::client *ui;
    int modif;
    int id_client;
};

#endif // CLIENT_H
