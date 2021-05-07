#include "connection.h"

connection::connection()
{

}
bool connection::createconnection()
{
    db = QSqlDatabase::addDatabase("QODBC");
    bool test=false;
    db.setDatabaseName("restaurant");
    db.setUserName("restaurant");
    db.setPassword("restaurant");

    if (db.open()) test=true;
    return test;
}
void connection::closeConnection(){db.close();}
