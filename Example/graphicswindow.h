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

};

#endif // GRAPHICSWINDOW_H
