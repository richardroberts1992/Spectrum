#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->openGLWidget->setBarCount(ui->barCountHorizontalSlider->value());
    this->setWindowTitle("Spectrum Example");
    ui->openGLWidget->generateBarList(ui->barCountHorizontalSlider->value());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_barCountHorizontalSlider_sliderMoved(int position)
{
    ui->barCountLabelValue->setText(QString::number(position));
    ui->openGLWidget->generateBarList(position);
}

void MainWindow::on_sortListPushButton_clicked()
{
    ui->openGLWidget->sortChartByValue();
}
