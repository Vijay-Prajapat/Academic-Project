#include "trendchart.h"
#include "ui_trendchart.h"


string g_astrAnalogKeys[4] = {"data_1", "data_2", "data_3","data_4"};

string g_astrAnalogComboKeys[4] = {"Data 1", "Data 2", "Data 3","Data 4"};





TrendChart::TrendChart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TrendChart)
{
    ui->setupUi(this);
    m_objTrendChartSetup = 0;
    //m_objTrendChartSetup->hide();
    InitTrendChartScreen();
}

TrendChart::~TrendChart()
{
    delete ui;
}

void TrendChart::InitTrendChartScreen()
{
    //qDebug() << "InitTrendChartScreen()";
    connect(pIOTimer, SIGNAL(timeout()), this, SLOT(SetPlotValues()));
    connect(pHoldTimer, SIGNAL(timeout()), this, SLOT(SetHoldTime()));
    //connect(ui->trend_chart_plot_w->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->trend_chart_plot_w->yAxis2, SLOT(setRange(QCPRange)));
    //pIOTimer->start(500);

    ui->trend_chart_plot_w->addGraph();
    ui->trend_chart_plot_w->graph(0)->setPen(QPen(Qt::red, 2));
    ui->trend_chart_plot_w->addGraph();
    ui->trend_chart_plot_w->graph(1)->setPen(QPen(Qt::blue, 2));
    ui->trend_chart_plot_w->addGraph();
    ui->trend_chart_plot_w->graph(2)->setPen(QPen(Qt::green, 2));
    ui->trend_chart_plot_w->addGraph();
    ui->trend_chart_plot_w->graph(3)->setPen(QPen(Qt::black, 2));

//    ui->trend_chart_plot_w->setBackground(Qt::white);
//    ui->trend_chart_plot_w->axisRect()->setAutoMargins(QCP::msNone);
//    ui->trend_chart_plot_w->axisRect()->setMargins(QMargins(2,2,2,2));

//    ui->trend_chart_plot_w->yAxis->grid()->setVisible(true);
//    ui->trend_chart_plot_w->xAxis->grid()->setVisible(false);

//    m_BlueAxis = ui->trend_chart_plot_w->axisRect()->addAxis(QCPAxis::atLeft);
//    m_RedAxis = ui->trend_chart_plot_w->axisRect()->addAxis(QCPAxis::atLeft);
//    m_GreenAxis = ui->trend_chart_plot_w->axisRect()->addAxis(QCPAxis::atRight);
//    m_YellowAxis = ui->trend_chart_plot_w->axisRect()->addAxis(QCPAxis::atRight);

//    m_RedAxis->setVisible(true);
//    m_BlueAxis->setVisible(true);
//    m_GreenAxis->setVisible(true);
//    m_YellowAxis->setVisible(true);

    ui->trend_chart_plot_w->xAxis->setRange(0,360);
    ui->trend_chart_plot_w->yAxis->setRange(0,50);
//    m_RedAxis->setRange(0,0.1);
//    m_BlueAxis->setRange(0,0.1);
//    m_GreenAxis->setRange(0,0.1);
//    m_YellowAxis->setRange(0,0.1);

//    foreach(QCPAxisRect *rect, ui->trend_chart_plot_w->axisRects())
//    {
//        foreach(QCPAxis *axis, rect->axes())
//        {
//            axis->setLayer("axes");
//            axis->grid()->setLayer("grid");
//        }
//    }

    //ui->trend_chart_plot_w->xAxis->setRange(0, 360, Qt::AlignRight);
}

void TrendChart::SetPlotValues()
{
    //qDebug() << "SetPlotValues()";
    xValuesTime++;
    GetValuesGUIMngr();
    UpdatePlotRangeGraphs();
}

void TrendChart::UpdatePlotRangeGraphs()
{
    //qDebug() << "UpdatePlotRangeGraphs()";
    SetGraphs();
}

void TrendChart::SetGraphs()
{
    //qDebug() << "SetGraphs()";
    if(m_HoldFlag == RESET)
    {
        ui->trend_chart_plot_w->graph(0)->setData(xAxisValues, y0AxisValues);
        ui->trend_chart_plot_w->graph(1)->setData(xAxisValues, y1AxisValues);
        ui->trend_chart_plot_w->graph(2)->setData(xAxisValues, y2AxisValues);
        ui->trend_chart_plot_w->graph(3)->setData(xAxisValues, y3AxisValues);
        ui->trend_chart_plot_w->replot();
    }
}

void TrendChart::GetValuesGUIMngr()
{
    //qDebug() << "GetValuesGUIMngr()";
    xAxisValues.push_back(xValuesTime);
    y0AxisValues.push_back(GetTrendValue(1));
    y1AxisValues.push_back(GetTrendValue(2));
    y2AxisValues.push_back(GetTrendValue(3));
    y3AxisValues.push_back(GetTrendValue(4));

//    for (QVector<double>::iterator iter = y0AxisValues.begin(); iter != y0AxisValues.end(); iter++){
//         qDebug() << *iter;
//     }

}

double TrendChart::GetTrendValue(int s32getData)
{
    //qDebug() << "GetTrendValue()";
    switch(s32getData)
    {
        case 0:
            return 0;
        break;

        case 1:
            return getRandomdData(10.0, 20.0);
        break;

        case 2:
            return getRandomdData(20.0, 30.0);
        break;

        case 3:
            return getRandomdData(30.0, 40.0);
        break;

        case 4:
            return getRandomdData(40.0, 50.0);
        break;

        default:
            break;
   }
   return 0;
}



double TrendChart::getRandomdData(double s32LowRange, double s32HighRange)
{
    //qDebug() << "getRandomdData()";
    double f = (double)rand() / RAND_MAX;
    return s32LowRange + f * (s32HighRange - s32LowRange);

}

void TrendChart::on_trend_chart_exit_pb_clicked()
{
    close();
}

void TrendChart::on_trend_chart_setup_pb_clicked()
{
    m_objTrendChartSetup = new TrendChartSetup(this);
    m_objTrendChartSetup->show();
}

void TrendChart::ClearTrendChart()
{
    // clear previous values of graph plotted.
    xAxisValues.erase(xAxisValues.begin(), xAxisValues.end());
    y0AxisValues.erase(y0AxisValues.begin(), y0AxisValues.end());
    y1AxisValues.erase(y1AxisValues.begin(), y1AxisValues.end());
    y2AxisValues.erase(y2AxisValues.begin(), y2AxisValues.end());
    y3AxisValues.erase(y3AxisValues.begin(), y3AxisValues.end());
    xValuesTime = ZERO;
}

void TrendChart::on_trend_chart_start_pb_clicked()
{
    if(m_HoldFlag == SET)
    {
        return;
    }
    QString qstrEnglishString = NULL_STRING;

    qstrEnglishString = ui->trend_chart_start_pb->text();

    if((qstrEnglishString == "Start") || (qstrEnglishString == "START"))
    {
        ui->trend_chart_start_pb->setText(tr("Stop", "9"));
        ui->trend_chart_start_pb->setStyleSheet("background-color:red");
        ui->trend_chart_setup_pb->setDisabled(true);
        // Enable the Hold Button
        ui->trend_chart_hold_pb->setCheckable(true);
        ui->trend_chart_hold_pb->setDisabled(false);

        ClearTrendChart();
        ui->trend_chart_trace_pb->setChecked(false);
        SetPlotValues();

        pIOTimer->start(500);
        ui->trend_chart_plot_w->replot();
    }
    else if((qstrEnglishString == "Stop") || (qstrEnglishString == "STOP"))
    {
        StopTrending();
    }
}

void TrendChart::StopTrending()
{
    ui->trend_chart_start_pb->setText(tr("Start", "9"));
    ui->trend_chart_start_pb->setStyleSheet("background-color:green");
    ui->trend_chart_setup_pb->setDisabled(false);

    // Disable the Hold Button
    ui->trend_chart_hold_pb->setCheckable(false);
    ui->trend_chart_hold_pb->setDisabled(true);
    pIOTimer->stop();
}

void TrendChart::on_trend_chart_hold_pb_clicked(bool clicked)
{
    if(clicked)
    {
        m_HoldSec = ZERO; m_HoldMin = ZERO; m_HoldHours = ZERO;
        m_HoldFlag = SET;
        xValuesTimeHold = xValuesTime;
        ui->trend_hold_time_l->setText(tr("Hold Time", "9") + " :");
        ui->trend_hold_time_info_l->setText("0:00.0");
        ui->trend_chart_hold_pb->setDown(true);
        pHoldTimer->start(500);
    }
    else
    {
        m_HoldFlag = RESET;
        xValuesTimeHold = 0.0;
        pHoldTimer->stop();
        ui->trend_hold_time_l->setText("");
        ui->trend_hold_time_info_l->setText("");
        ui->trend_chart_hold_pb->setDown(false);
        ui->trend_chart_plot_w->replot();
    }
}

void TrendChart::SetHoldTime()
{
    if(ui->trend_chart_start_pb->text() == "Stop")
    {
        m_HoldSec++;
        if( (m_HoldSec % 6) == ZERO )
        {
            m_HoldSec = ZERO;
            m_HoldMin++;
            if( (m_HoldMin % 60) == ZERO )
            {
                m_HoldMin = ZERO;
                m_HoldHours++;
            }
        }

        QString strHoldTime = "";
        if(m_HoldMin < 10)
        {
            strHoldTime = QString::number(m_HoldHours) + ":" + "0" + QString::number(m_HoldMin) + "." + QString::number(((5*m_HoldSec)/3));
        }
        else
        {
            strHoldTime = QString::number(m_HoldHours) + ":" + QString::number(m_HoldMin) + "." + QString::number(((5*m_HoldSec)/3));
        }
        ui->trend_hold_time_info_l->setText(strHoldTime);
    }
}


void TrendChart::SetComboboxes()
{
    bool bCurrentState1 = ui->track_0_cbox->blockSignals(true);
    bool bCurrentState2 = ui->track_1_cbox->blockSignals(true);
    bool bCurrentState3 = ui->track_2_cbox->blockSignals(true);
    bool bCurrentState4 = ui->track_3_cbox->blockSignals(true);

    ui->track_0_cbox->clear(); ui->track_1_cbox->clear();
    ui->track_2_cbox->clear(); ui->track_3_cbox->clear();
    S32 s32Index = ZERO;
    ui->track_0_cbox->addItem("None"); ui->track_1_cbox->addItem("None");
    ui->track_2_cbox->addItem("None"); ui->track_3_cbox->addItem("None");
    for(s32Index = ZERO; s32Index <= 3; s32Index++)
    {
        QString qstr = g_astrAnalogComboKeys[s32Index].c_str();
        if(::atoi((GetKeyValueFromDatabaseMap("trend_chart2", g_astrAnalogKeys[s32Index]).c_str())))
        {
            ui->track_0_cbox->addItem(qstr); ui->track_1_cbox->addItem(qstr);
            ui->track_2_cbox->addItem(qstr); ui->track_3_cbox->addItem(qstr);
        }
    }

    ui->track_0_cbox->setCurrentText(GetKeyValueFromDatabaseMap("trend_chart1", "track_0").c_str());
    ui->track_1_cbox->setCurrentText(GetKeyValueFromDatabaseMap("trend_chart1", "track_1").c_str());
    ui->track_2_cbox->setCurrentText(GetKeyValueFromDatabaseMap("trend_chart1", "track_2").c_str());
    ui->track_3_cbox->setCurrentText(GetKeyValueFromDatabaseMap("trend_chart1", "track_3").c_str());

    ui->track_0_cbox->blockSignals(bCurrentState1);
    ui->track_1_cbox->blockSignals(bCurrentState2);
    ui->track_2_cbox->blockSignals(bCurrentState3);
    ui->track_3_cbox->blockSignals(bCurrentState4);

    m_Track0Index = ui->track_0_cbox->currentIndex();
    m_Track1Index = ui->track_1_cbox->currentIndex();
    m_Track2Index = ui->track_2_cbox->currentIndex();
    m_Track3Index = ui->track_3_cbox->currentIndex();
}

string TrendChart::GetKeyValueFromDatabaseMap(string strTblName, string strKey)
{
    string strValue = "";
    S32 s32Error = DB_FAILURE;
    string_string_map g_strMapTrendChart1, g_strMapTrendChart2;
    if(!strcmp(strTblName.c_str(),"trend_chart1"))
    {
        g_strMapTrendChart1 = GetMapOfKeyCurrentValue("trend_chart", "trend_chart1", &s32Error);
        if(!g_strMapTrendChart1.empty())
        {
            strValue = g_strMapTrendChart1[strKey];
        }
    }
    else if(!strcmp(strTblName.c_str(),"trend_chart2"))
    {
        g_strMapTrendChart2 = GetMapOfKeyCurrentValue("trend_chart", "trend_chart2", &s32Error);
        if(!g_strMapTrendChart2.empty())
        {
            strValue = g_strMapTrendChart2[strKey];
        }
    }
    return strValue;
}

string_string_map TrendChart::GetMapOfKeyCurrentValue(string strDbName, string strTblName, S32 *s32Error)
{
    sqlite3_stmt *selectStmt = NULL;
    sqlite3 *db = NULL;
    string strDbPath = DBDIR + strDbName;
    S32 s32Ret = DB_FAILURE, s32Ret1 = DB_FAILURE;
    S32 s32Row = 0;
    const S8 *ps8Key = NULL, *ps8CurrentValue = NULL;
    string strSelectQuery = "";

    //map of Table
    string_string_map TblMap;
    U8 u8RetryCnt = ZERO;
    U8 u8RetryCnt2 = ZERO;

    /* Open database */
    s32Ret = sqlite3_open(strDbPath.c_str(), &db);

    if(SQLITE_OK == s32Ret)
    {
        s32Ret = DB_SUCCESS;
        #ifdef DEBUG_INFO
        printf("DbTableApi:: Opened database successfully\n");
        #endif

        /* Create a Select Query */
        strSelectQuery = SELECT_FROM + strTblName;

        do
        {
            /* Prepare a Select Query Statement */
            s32Ret = sqlite3_prepare(db, strSelectQuery.c_str(), strlen(strSelectQuery.c_str())+1, &selectStmt, NULL);

            if(SQLITE_OK == s32Ret)
            {
                if(NULL != selectStmt)
                {
                    do
                    {
                        /* Execute select Statement to get row value*/
                        s32Ret = sqlite3_step (selectStmt);
                        if (SQLITE_ROW == s32Ret)
                        {
                            /* Key Value */
                            ps8Key = (const S8 *)sqlite3_column_text (selectStmt, KEY_COLMN);
                            /* Current Value */
                            ps8CurrentValue = (const S8 *)sqlite3_column_text (selectStmt, CURRENT_VALUE_COLMN);

                            //Check if strings are empty
                            if((NULL == ps8Key) || (NULL == ps8CurrentValue))
                            {
                                s32Ret = DB_FAILURE;
                                break;
                            }

                            /* Increment row number */
                            s32Row++;

                            TblMap[string(ps8Key)] = string(ps8CurrentValue);
                        }
                        else if (SQLITE_DONE == s32Ret)
                        {
                            s32Ret = DB_SUCCESS;
                            break;
                        }
                        else if((SQLITE_BUSY == s32Ret) || (SQLITE_LOCKED == s32Ret))
                        {
                            //If Sqlite is busy or locked wait for some time and retry
                            #ifdef DEBUG_INFO
                            printf("DbTableApi:: Wait to get SQLite database file access");
                            #endif

                            /* Wait for 200 msec and retry */
                            usleep(DATABASESCAN_DELAY);

                            /* need to add retry count if failed forever in this case to break the condition */
                            if(u8RetryCnt >= MAX_DB_ACCESS_RETRY)
                            {
                                s32Ret = DB_FAILURE;
                                #ifdef DEBUG_ERR
                                printf("DbTableApi:: GetMapOfKeyCurrentValue >> database is busy or locked, sqlite3_step max retries reached\n");
                                #endif
                                break;
                            }
                            else
                            {
                                u8RetryCnt++;
                            }
                        }
                        else
                        {
                            #ifdef DEBUG_INFO
                            printf("DbTableApi:: GetMapOfTbl Failed.\n");
                            #endif
                            //Return Error
                            s32Ret = DB_FAILURE;
                        }
                    } while((SQLITE_ROW == s32Ret)||(SQLITE_BUSY == s32Ret)||(SQLITE_LOCKED == s32Ret));

                    /* Delete prepared Select Query Statement */
                    s32Ret1 = sqlite3_finalize(selectStmt);
                    if( s32Ret1 != SQLITE_OK )
                    {
                        s32Ret1 = DB_FAILURE;
                        #ifdef DEBUG_INFO
                        printf("DbTableApi:: Destroying preapared statment object failed");
                        #endif
                    }
                    else
                    {
                        s32Ret1 = DB_SUCCESS;
                    }
                    if((DB_FAILURE == s32Ret) || (DB_FAILURE == s32Ret1))
                    {
                        //Any of the above operations failed result will be failure
                        s32Ret = DB_FAILURE;
                    }

                }//end of selectStmt check
                else
                {
                    s32Ret = DB_FAILURE;
                    #ifdef DEBUG_INFO
                    printf("DbTableApi:: Pointer to prepared statement is NULL");
                    #endif
                }
            }
            else if((SQLITE_BUSY == s32Ret) ||  (SQLITE_LOCKED == s32Ret))
            {
                //If Sqlite is busy or locked wait for some time and retry
                #ifdef DEBUG_INFO
                printf("DbTableApi:: Wait to get SQLite database file access");
                #endif

                /* Wait for 200 msec and retry */
                usleep(DATABASESCAN_DELAY);

                /* need to add retry count if failed forever in this case to break the condition */
                if(u8RetryCnt2 >= MAX_DB_ACCESS_RETRY)
                {
                    s32Ret = DB_FAILURE;
                    #ifdef DEBUG_ERR
                    printf("DbTableApi:: GetMapOfKeyCurrentValue >> database is busy or locked, sqlite3_prepare max retries reached\n");
                    #endif
                    break;
                }
                else
                {
                    u8RetryCnt2++;
                }
            }
            else
            {
                //return error prepare failed
                s32Ret = DB_FAILURE;
            }
        } while((SQLITE_BUSY == s32Ret)||(SQLITE_LOCKED == s32Ret));
    }
    else
    {
        #ifdef DEBUG_INFO
        printf("DbTableApi:: Can't open database: %s\n", sqlite3_errmsg(db));
        #endif
        s32Ret = DB_FAILURE;
    }

    /* close database */
    s32Ret1 = sqlite3_close(db);
    if(SQLITE_OK != s32Ret1)
    {
        s32Ret1 = DB_FAILURE;
        #ifdef DEBUG_INFO
        //printf("DbTableApi:: Database Close Failed %s\n", *zErrMsg);
        #endif
    }
    else
    {
        s32Ret1 = DB_SUCCESS;
        #ifdef DEBUG_INFO
        printf("DbTableApi:: Database Closed successfully\n");
        #endif
    }

    if((DB_FAILURE == s32Ret) || (DB_FAILURE == s32Ret1))
    {
        //Any of the above operations failed result will be failure
        s32Ret = DB_FAILURE;
    }

    //Return Database Error Status Value
    *s32Error = s32Ret;

    return TblMap;
}


S32 TrendChart::UpdateTableValue(string strDbName, const string strTblName, string strKey, string strValue, U16 u16TextValue)
{
    sqlite3 *db = NULL;
    string strDbDir = DBDIR;
    string strDbPath = strDbDir + strDbName;
    S32 s32Ret = DB_FAILURE, s32Ret1 = DB_FAILURE;
    char *zErrMsg = NULL;

    /* Open database */
    s32Ret = sqlite3_open(strDbPath.c_str(), &db);

    if(s32Ret)
    {
        #ifndef DEBUG_INFO
        printf("DbTableApi:: Can't open database: %s, %d\n", sqlite3_errmsg(db),s32Ret);
        //printDbLog("DbTableApi::UpdateTableValue >> Can't open database: %s, %d\n", sqlite3_errmsg(db),s32Ret);
        #endif
        s32Ret = DB_FAILURE;
    }
    else
    {
        s32Ret = DB_SUCCESS;
        #ifdef DEBUG_INFO
        printf("DbTableApi:: Opened database successfully\n");
        #endif
    }

    #ifdef DEBUG_INFO
    cout << strDbPath << endl;
    cout << strDbName << " " << strKey << " " << strValue << " " << u16TextValue << " " << endl;
    #endif //DEBUG_INFO

    /* If open success then execute query */
    if(DB_SUCCESS == s32Ret)
    {
        //Prepare Key as a string
        strKey = "'" + strKey + "'";

        if (u16TextValue)
        {
            strValue = "'" + strValue + "'"; // sqlite needs string quotes for updating text
        }

        /* Prepare Update Query */
        string strSql = "UPDATE " + strTblName + " SET " + "CurrentValue" + " = " + strValue + " where Key IS " + strKey + ";";

        #ifdef DEBUG_INFO
        cout << strSql << endl;
        #endif

        /* Execute SQL Query Statment */
        s32Ret = sqlite3_exec(db, strSql.c_str(), NULL, NULL, &zErrMsg);

        if(SQLITE_OK != s32Ret)
        {
            #ifndef DEBUG_INFO
            printf("DbTableApi:: SQL exec Failed %d, strSql = %s\n", s32Ret, strSql.c_str());
            //printDbLog("DbTableApi:: UpdateTableValue >> SQL exec Failed %d\n",s32Ret);
            #endif
            s32Ret = DB_FAILURE;
            sqlite3_free(zErrMsg);
        }
        else
        {
            s32Ret = DB_SUCCESS;
            #ifndef DEBUG_INFO
            printf("DbTableApi:: Table updated successfully\n");
            #endif
        }
    }

    /* Close database */
    s32Ret1 = sqlite3_close(db);
    if(SQLITE_OK != s32Ret1)
    {
        s32Ret1 = DB_FAILURE;
        #ifndef DEBUG_INFO
        //printf("DbTableApi:: Database Close Failed %s, %d\n", *zErrMsg,s32Ret1);
        //printDbLog("DbTableApi:: UpdateTableValue >> Database Close Failed %s, %d\n", *zErrMsg,s32Ret1);
        #endif
    }
    else
    {
        s32Ret1 = DB_SUCCESS;
        #ifdef DEBUG_INFO
        printf("DbTableApi:: Database Closed successfully\n");
        #endif
    }

    if((DB_FAILURE == s32Ret) || (DB_FAILURE == s32Ret1))
    {
        s32Ret = DB_FAILURE;
    }

    return s32Ret;
}
