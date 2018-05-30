#include "graphicswindow.h"
#include <QDebug>
#include <QOpenGLFunctions>
#include "colourmanager.h"
#include "GL/freeglut.h"

GraphicsWindow::GraphicsWindow(QWidget *parent)
{

}

void GraphicsWindow::paintGL()
{

    generateBarList(20);
    QVector<QRectF> barList;
}

void GraphicsWindow::initializeGL()
{
    setupView();
    selectColourMap();
}

void GraphicsWindow::selectColourMap()
{
    //Get the first Diverging colour map in list.
    ColourMap cMap = CMList::getMapList(CMClassification::DIVERGING)[0];

    //Sets the current map
    ColourManager::setColourMapIndex(cMap.getIndex());
}

QVector<QRectF> GraphicsWindow::generateBarList(int size)
{
    QVector<QRectF> barList;
    for(int i=0;i<size;i++){
        float value = qrand()%100;
        qDebug() << i << value;
    }


    return barList;
}

void GraphicsWindow::drawAxis()
{
    glBegin(GL_LINES);
    glVertex2f(AxisOrigin().x(),AxisOrigin.y());
    glVertex2f(AxisX.x(),AxisX.y());

    glVertex2f(AxisOrigin().x(),AxisOrigin.y());
    glVertex2f(AxisY.x(),AxisY.y());
    glEnd();
}

void GraphicsWindow::drawBar(QRectF box, QString name, double percent)
{
    float upperY = box.top();
    float lowerY = box.bottom();
    float leftX = box.left();
    float rightX = box.right();

    //Instantiate Colour Manager
    ColourManager manager(0,100);

    //Get Colour value from
    Colour col = manager.getInterpolatedColour(percent);

    //Set Colour
    glColor3f(col.getR(),col.getG(),col.getB());

    glBegin(GL_QUADS);
    glVertex2f(leftX,upperY);
    glVertex2f(rightX,upperY);
    glVertex2f(rightX,lowerY);
    glVertex2f(leftX,lowerY);
    glEnd();
}

QPointF GraphicsWindow::AxisOrigin() const
{
    return m_AxisOrigin;
}

void GraphicsWindow::setAxisOrigin(const QPointF &AxisOrigin)
{
    m_AxisOrigin = AxisOrigin;
}

QPointF GraphicsWindow::AxisX() const
{
    return m_AxisX;
}

void GraphicsWindow::setAxisX(const QPointF &AxisX)
{
    m_AxisX = AxisX;
}

QPointF GraphicsWindow::AxisY() const
{
    return m_AxisY;
}

void GraphicsWindow::setAxisY(const QPointF &AxisY)
{
    m_AxisY = AxisY;
}
















void GraphicsWindow::setupView()
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
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void GraphicsWindow::setupAxis()
{
    float axisWidth = width()*0.9f;
    float axisHeight = height()*0.9f;

    float xDist = width() - axisWidth;
    float yDist = height() - axisHeight;

    setAxisOrigin(QPointF(xDist,yDist));
    setAxisX(QPointF((width()-xDist),yDist));
    setAxisy(QPointF(xDist,(height()-yDist)));
}




