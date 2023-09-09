#ifndef TRENDCHARTSETUP_H
#define TRENDCHARTSETUP_H

#include <QWidget>
#include "trendchartsetup.h"

namespace Ui {
class TrendChartSetup;
}

class TrendChartSetup : public QWidget
{
    Q_OBJECT

public:
    explicit TrendChartSetup(QWidget *parent = 0);
    ~TrendChartSetup();

private slots:
    void on_trend_setup_ok_pb_clicked();

    void on_data_1_clicked(bool bchecked);
    void on_data_2_clicked(bool bchecked);
    void on_data_3_clicked(bool bchecked);
    void on_data_4_clicked(bool bchecked);

private:
    Ui::TrendChartSetup *ui;
    QWidget *m_pcParent;
    unsigned char m_u8Counter = 0;
};

#endif // TRENDCHARTSETUP_H
