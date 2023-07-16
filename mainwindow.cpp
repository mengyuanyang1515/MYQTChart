#include "mainwindow.h"
#include "ui_mainwindow.h"

//#include <QFile>
//#include <QtCharts/QValueAxis>
//#include <QtCharts/QChartView>
//#include <QtCharts/QLineSeries>

#include <QtCharts>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createChart();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_pChartView;
    m_pChartView = nullptr;
}

void MainWindow::createChart()
{
    m_pChartView =new QChartView(this);

    this->setCentralWidget(m_pChartView);

    QChart *chart=new QChart;
    chart->setTitle("数据分析");
    m_pChartView->setChart(chart);  // Chart添加到ChartView
    // 创建折现序列
    QLineSeries *series0 = new QLineSeries();
    
    // 添加到图表
    chart->addSeries(series0);

    QFile file("../numbers.txt");
    
    file.open(QIODevice::ReadOnly|QIODevice::Text);

    int allCnt = 0;    // 一行一行的读
    int index = 0;
    int minValue = INT_MAX;
    int maxValue = INT_MIN;
    while (!file.atEnd())
    {
      int value = file.readLine().toInt();
      series0->append(index, value);
      if (value < minValue)
          minValue = value;
      if (value > maxValue)
          maxValue = value;
      
      index++;
      allCnt++;
    }
    
    file.close();
    
    // 创建X坐标轴
    QValueAxis *axisX = new QValueAxis;
    axisX->setRange(0, allCnt);
    axisX->setTitleText("采样点");

    // 创建Y坐标轴
    QValueAxis *axisY = new QValueAxis;
    axisY->setRange(minValue, maxValue);
    axisY->setTitleText("值");

    // 为序列设置X坐标轴
    chart ->setAxisX(axisX,series0);
    //为序列设置Y坐标轴
    chart ->setAxisY(axisY,series0);
}
 
