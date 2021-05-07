#ifndef NOTIFICATIN_H
#define NOTIFICATIN_H
#include "stock_c.h"

#include <QDialog>

namespace Ui {
class notificatin;
}

class notificatin : public QDialog
{
    Q_OBJECT

public:
    explicit notificatin(QWidget *parent = nullptr);
    ~notificatin();

private slots:
    void on_pushButton_43_clicked();

private:
    Ui::notificatin *ui;
};

#endif // NOTIFICATIN_H
