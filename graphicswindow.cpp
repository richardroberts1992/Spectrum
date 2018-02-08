#include "graphicswindow.h"
#include <QOpenGLFunctions>
#include "GL/freeglut.h"

GraphicsWindow::GraphicsWindow(QWidget *parent)
{

}

void GraphicsWindow::paintGL()
{

}

void GraphicsWindow::initializeGL()
{
    glClearColor(1,0,0,1);
}


