#ifndef INSCRIT_H
#define INSCRIT_H

#include <QDialog>
#include "compte_c.h"

namespace Ui {
class inscrit;
}

class inscrit : public QDialog
{
    Q_OBJECT

public:
    explicit inscrit(QWidget *parent = nullptr);
    ~inscrit();

private slots:
    void on_pushButton_4_clicked();

private:
    Ui::inscrit *ui;
};

#endif // INSCRIT_H
