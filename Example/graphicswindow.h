#ifndef GRAPHICSWINDOW_H
#define GRAPHICSWINDOW_H
#include<QOpenGLWidget>
#include "colourmanager.h"
class GraphicsWindow : public QOpenGLWidget
{  
    Q_OBJECT
public:
    explicit GraphicsWindow(QWidget *parent=0);
    void paintGL();
    void initializeGL();
    void setupView();
    void setupAxis();
    void selectColourMap();
    QVector<QRectF> generateBarList(int size);

    void drawAxis();
    void drawBar(QRectF box, QString name, double percent);


    QPointF AxisOrigin() const;
    void setAxisOrigin(const QPointF &AxisOrigin);

    QPointF AxisX() const;
    void setAxisX(const QPointF &AxisX);

    QPointF AxisY() const;
    void setAxisY(const QPointF &AxisY);

private:

    QPointF m_AxisOrigin;
    QPointF m_AxisX;
    QPointF m_AxisY;

};

#endif // GRAPHICSWINDOW_H
