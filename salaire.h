#ifndef SALAIRE_H
#define SALAIRE_H

#include <QDialog>
#include "salaire_c.h"

namespace Ui {
class salaire;
}

class salaire : public QDialog
{
    Q_OBJECT

public:
    explicit salaire(QWidget *parent = nullptr);
    ~salaire();
    void setModifier(int modifier){modif=modifier;}
    int getModifier() {return modif;}
    void setid_empl(int id){id_empl=id;}
    int getid_empl() {return id_empl;}



private slots:
    void on_pushButton_43_clicked();

private:
    Ui::salaire *ui;
    int modif;
    int id_empl;
};

#endif // SALAIRE_H
