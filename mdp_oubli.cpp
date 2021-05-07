#include "mdp_oubli.h"
#include "ui_mdp_oubli.h"
#include "mainwindow.h"
#include <QCoreApplication>
#include <QMessageBox>
#include <QSslSocket>
#include <QNetworkAccessManager>
#include <QUrlQuery>
#include <QNetworkReply>
#include <QJsonValue>
#include <QJsonValueRef>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

mdp_oubli::mdp_oubli(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mdp_oubli)
{
    ui->setupUi(this);
}

mdp_oubli::~mdp_oubli()
{
    delete ui;
}

void mdp_oubli::on_pushButton_4_clicked()
{
    QNetworkAccessManager * manager = new QNetworkAccessManager(this);

        QUrl url("https://ACbd9712e3acf574ec887b056a785afa09:eb2da26903eddd85be774e8522ae4bc7@api.twilio.com/2010-04-01/Accounts/ACbd9712e3acf574ec887b056a785afa09/Messages.json");
        //QUrl url("https://AC2de718dd6614da25d92acb2e9b506766:77c281aae1e10141fa98f618768a2c40@api.twilio.com/2010-04-01/Accounts/ACbd9712e3acf574ec887b056a785afa09/Messages.json");
        QNetworkRequest request(url);

        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");


        QUrlQuery params;
        //params.addQueryItem("From", "+18053879768");
       params.addQueryItem("From", "+19286123492");
        params.addQueryItem("To",ui->lineEdit_3->text() );//"+21690101450"
        params.addQueryItem("Body", "test");
       // params.addQueryItem("Body", "test");

        // etc

        connect(manager, SIGNAL(finished(QNetworkReply *)), this, SLOT(replyFinished(QNetworkReply*)));

        manager->post(request, params.query().toUtf8());






    QSqlQuery query;

    QString email_compte=ui->lineEdit_3->text();
    if ((ui->lineEdit_3->text()=="" ) )
    {
        QMessageBox::information(this, QObject::tr("ok"),
                                 QObject::tr("Remplir les cases vides\n"));


    }
    else
    {
        query.prepare("SELECT EMAIL_COMP,MDP_COMP from compte WHERE  EMAIL_COMP=:email_compte ");
        query.bindValue(":email_compte", email_compte);
        if (query.exec())
        {
            if (query.next())
            {

            QMessageBox::information(this, QObject::tr("ok"),
                                     QObject::tr("Mot de passe envoyée\n"));
            }
            else
            {
                QMessageBox::information(this, QObject::tr("ok"),
                                         QObject::tr("Email  incorrecte\n"));

            }
          }
   }



}

void mdp_oubli::on_pushButton_5_clicked()
{
    hide();
    MainWindow *newmain= new MainWindow();
    newmain->show();
}
void mdp_oubli::replyFinished(QNetworkReply* reply)
{
    //QByteArray bts = rep->readAll();


    QByteArray buffer = reply->readAll();
    qDebug() << buffer;
    QJsonDocument jsonDoc(QJsonDocument::fromJson(buffer));
    QJsonObject jsonReply = jsonDoc.object();

    QJsonObject response = jsonReply["response"].toObject();
    QJsonArray  data     = jsonReply["data"].toArray();
    qDebug() << data;
    qDebug() << response;


}
