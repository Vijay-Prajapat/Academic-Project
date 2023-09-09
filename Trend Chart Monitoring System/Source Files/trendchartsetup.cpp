
#include "trendchart.h"
#include "ui_trendchartsetup.h"

TrendChartSetup::TrendChartSetup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TrendChartSetup)
{
    ui->setupUi(this);
    m_pcParent = parent;
    setAttribute(Qt::WA_DeleteOnClose);
}

TrendChartSetup::~TrendChartSetup()
{
    delete ui;
}

void TrendChartSetup::on_trend_setup_ok_pb_clicked()
{
    ((TrendChart *)m_pcParent)->SetComboboxes();
    close();
}

void TrendChartSetup::on_data_1_clicked(bool bchecked)
{
    if(true == bchecked)
    {
        m_u8Counter++;
        ((TrendChart *)m_pcParent)->UpdateTableValue("trend_chart", "trend_chart2", "data_1", "1", 0);
    }
    else
    {
        m_u8Counter--;
        ((TrendChart *)m_pcParent)->UpdateTableValue("trend_chart", "trend_chart2", "data_1", "0", 0);
    }
}

void TrendChartSetup::on_data_2_clicked(bool bchecked)
{
    if(true == bchecked)
    {
        m_u8Counter++;
        ((TrendChart *)m_pcParent)->UpdateTableValue("trend_chart", "trend_chart2", "data_2", "1", 0);
    }
    else
    {
        m_u8Counter--;
        ((TrendChart *)m_pcParent)->UpdateTableValue("trend_chart", "trend_chart2", "data_2", "0", 0);
    }
}
void TrendChartSetup::on_data_3_clicked(bool bchecked)
{
    if(true == bchecked)
    {
        m_u8Counter++;
        ((TrendChart *)m_pcParent)->UpdateTableValue("trend_chart", "trend_chart2", "data_3", "1", 0);
    }
    else
    {
        m_u8Counter--;
        ((TrendChart *)m_pcParent)->UpdateTableValue("trend_chart", "trend_chart2", "data_3", "0", 0);
    }
}
void TrendChartSetup::on_data_4_clicked(bool bchecked)
{
    if(true == bchecked)
    {
        m_u8Counter++;
        ((TrendChart *)m_pcParent)->UpdateTableValue("trend_chart", "trend_chart2", "data_4", "1", 0);
    }
    else
    {
        m_u8Counter--;
        ((TrendChart *)m_pcParent)->UpdateTableValue("trend_chart", "trend_chart2", "data_4", "0", 0);
    }
}
