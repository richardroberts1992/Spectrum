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
    glClearColor(0.9f,0.9f,0.9f,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0,width(),0,height(),-1,1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_MULTISAMPLE);
    glEnable( GL_LINE_SMOOTH );
    //glDisable( GL_POLYGON_SMOOTH );
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}


