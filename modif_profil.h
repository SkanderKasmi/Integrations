#ifndef MODIF_PROFIL_H
#define MODIF_PROFIL_H

#include <QDialog>
#include "employe.h"



namespace Ui {
class MODIF_profil;
}

class MODIF_profil : public QDialog
{
    Q_OBJECT

public:
    explicit MODIF_profil(QWidget *parent = nullptr);
    ~MODIF_profil();
    void setModifier(int modifier){modif=modifier;}
    int getModifier() {return modif;}

    void setID_empl(int id){id_empl=id;}
    int getID_empl() {return id_empl;}

    void setData();






private slots:
    void on_pushButton_43_clicked();



private:
    Ui::MODIF_profil *ui;
    int modif;
    int id_empl;




};

#endif // MODIF_PROFIL_H
