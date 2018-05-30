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
    void selectColourMap();
    QVector<QRectF> generateBarList(int size);

    void drawBar(QRectF box, QString name, double percent);

};

#endif // GRAPHICSWINDOW_H
