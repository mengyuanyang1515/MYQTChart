#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QChartView;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void createChart();
private:
    Ui::MainWindow *ui;
    QChartView *m_pChartView;
};
#endif // MAINWINDOW_H
