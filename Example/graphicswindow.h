#ifndef GRAPHICSWINDOW_H
#define GRAPHICSWINDOW_H
#include<QOpenGLWidget>
#include "chartbar.h"
class GraphicsWindow : public QOpenGLWidget
{  
    Q_OBJECT
public:
    explicit GraphicsWindow(QWidget *parent=0);
    void paintGL();
    void initializeGL();
    void setupView();
    void setupAxis();
    void setupData();
    void selectColourMap();
    void generateBarList(int size);

    void drawAxis();
    void drawChart(QVector<ChartBar> list);
    void drawBar(ChartBar bar);
    void drawBarLabels(ChartBar bar);

    void sortChartByValue();


    QPointF AxisOrigin() const;
    void setAxisOrigin(const QPointF &AxisOrigin);

    QPointF AxisX() const;
    void setAxisX(const QPointF &AxisX);

    QPointF AxisY() const;
    void setAxisY(const QPointF &AxisY);


    int BarCount() const;
    void setBarCount(int BarCount);

private:

    QVector<ChartBar> ChartBarList;

    int m_BarCount;
    QPointF m_AxisOrigin;
    QPointF m_AxisX;
    QPointF m_AxisY;

};

#endif // GRAPHICSWINDOW_H
