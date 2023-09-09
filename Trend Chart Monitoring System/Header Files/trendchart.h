#ifndef TRENDCHART_H
#define TRENDCHART_H

#include <iostream>
#include <random>
#include <QWidget>
#include <QVector>
#include <QTimer>
#include <QDebug>
#include "qcustomplot.h"

#include <unordered_map>
#include <string>
#include <string.h>
#include <strings.h>
#include <sqlite3.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "trendchartsetup.h"

#define MAXIMUM_TREND_SAMPLES   43200
#define MINIMUM_TREND_SAMPLES   0

#define NULL_STRING			""
#define ZERO				0
#define SET                 1
#define RESET               0

#define DBDIR "/home/samiksha/minorProject/trendChart/"
#define DB_FAILURE  -1
#define DB_SUCCESS  0
#define DATABASESCAN_DELAY       200000
#define SELECT_FROM     "select * from "
#define MAX_DB_ACCESS_RETRY      5
#define KEY_COLMN               0
#define CURRENT_VALUE_COLMN      5

using namespace std;

typedef unsigned char U8;
typedef char S8;
typedef unsigned short U16;
typedef signed short S16;
typedef unsigned int U32;
typedef signed int S32;
typedef float FLOAT;
typedef double DOUBLE;
typedef long double LONGDOUBLE;
typedef bool BOOL;
typedef unsigned long LONG;
typedef long long int LONGS32;
typedef unsigned long long int LONGU32;


typedef std::unordered_map<std::string, std::string> string_string_map;


namespace Ui {
class TrendChart;
}

class TrendChart : public QWidget
{
    Q_OBJECT

public:
    explicit TrendChart(QWidget *parent = 0);
    void InitTrendChartScreen();
    ~TrendChart();
    void SetComboboxes();
    string GetKeyValueFromDatabaseMap(string strTblName, string strKey);
    string_string_map GetMapOfKeyCurrentValue(string , string , S32 *);
    S32 UpdateTableValue(string strDbName, const string strTblName, string strKey, string strValue, U16 u16TextValue);

private slots:
    void on_trend_chart_exit_pb_clicked();
    void on_trend_chart_setup_pb_clicked();
    void SetPlotValues();
    void ClearTrendChart();
    void StopTrending();
    void on_trend_chart_hold_pb_clicked(bool);
    void SetHoldTime();
    void on_trend_chart_start_pb_clicked();

private:
    Ui::TrendChart *ui;


    QCPAxis *m_RedAxis;
    QCPAxis *m_BlueAxis;
    QCPAxis *m_GreenAxis;
    QCPAxis *m_YellowAxis;

    QTimer *pIOTimer = new QTimer(this);
    QTimer *pHoldTimer = new QTimer(this);
    void UpdatePlotRangeGraphs();
    void SetGraphs();
    void GetValuesGUIMngr();
    double GetTrendValue(int s32getData);
    double getRandomdData(double s32LowRange, double s32HighRange);

    double xValuesTime = 0.0;

    QVector<double> xAxisValues;
    QVector<double> y0AxisValues;
    QVector<double> y1AxisValues;
    QVector<double> y2AxisValues;
    QVector<double> y3AxisValues;

    double xValuesTimeHold = 0.0;
    U8 m_HoldFlag = RESET;
    U8 m_HoldHours = RESET;
    U8 m_HoldMin = RESET;
    U8 m_HoldSec = RESET;

    S32 m_Track0Index = ZERO;
    S32 m_Track1Index = ZERO;
    S32 m_Track2Index = ZERO;
    S32 m_Track3Index = ZERO;
    TrendChartSetup *m_objTrendChartSetup = NULL;
};

#endif // TRENDCHART_H
