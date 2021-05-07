#ifndef MENU_H
#define MENU_H
#include "menu_c.h"
#include <QDialog>

namespace Ui {
class menu;
}

class menu : public QDialog
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = nullptr);
    ~menu();
    void setModifier(int modifier){modif=modifier;}
    int getModifier() {return modif;}

    void setid_elem(int id){id_elem=id;}
    int getid_elem() {return id_elem;}

    void setData();

private slots:
    void on_pushButton_43_clicked();


    //void on_pushButton_105_clicked();

private:
    Ui::menu *ui;
    int modif;
    int id_elem;
    QString photo_path;
};

#endif // MENU_H
