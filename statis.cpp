#include "statis.h"
#include "ui_statis.h"

statis::statis(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statis)
{
    ui->setupUi(this);
    QPieSeries *series = new QPieSeries();
    QSqlQuery query;

    query.prepare("Select TYPE_DEPENSE , MONTANT_DEPENSE   from depense ");
        query.exec();
       while(query.next())
       {
        series->append(query.value(0).toString(), query.value(1).toInt());

}

        QPieSlice *slice = series->slices().at(1);
        slice->setExploded(true);
        slice->setLabelVisible(true);
        slice->setPen(QPen(Qt::darkGreen, 2));
        slice->setBrush(Qt::green);


        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Qt5 Pie Chart Example");


        QChartView *chartview = new QChartView(chart);
        chartview->setParent(ui->horizontalFrame);

}

statis::~statis()
{
    delete ui;
}
