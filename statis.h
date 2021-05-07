#ifndef STATIS_H
#define STATIS_H

#include <QDialog>
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include <QSqlQuery>

namespace Ui {
class statis;
}

class statis : public QDialog
{
    Q_OBJECT

public:
    explicit statis(QWidget *parent = nullptr);
    ~statis();

private:
    Ui::statis *ui;
};

#endif // STATIS_H
