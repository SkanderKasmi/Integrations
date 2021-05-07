#ifndef DEPENSE_H
#define DEPENSE_H

#include <QDialog>
#include "depense_c.h"

namespace Ui {
class depense;
}

class depense : public QDialog
{
    Q_OBJECT

public:
    explicit depense(QWidget *parent = nullptr);
    ~depense();
    void setModifier(int modifier){modif=modifier;}
    int getModifier() {return modif;}
    void setid_depense(int id){id_depense=id;}
    int getid_depense() {return id_depense;}


private slots:
    void on_pushButton_43_clicked();

private:
    Ui::depense *ui;
    int modif;
    int id_depense;
};

#endif // DEPENSE_H
