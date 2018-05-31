#include "graphicswindow.h"
#include <QDebug>
#include <QOpenGLFunctions>
#include "colourmanager.h"
#include "GL/freeglut.h"
#include <ctime>
GraphicsWindow::GraphicsWindow(QWidget *parent)
{

}

void GraphicsWindow::paintGL()
{
    setupView();
    setupData();
    drawChart(ChartBarList);
    drawAxis();
}

void GraphicsWindow::initializeGL()
{
    ChartBarList.clear();
    setupView();
    selectColourMap();
}

void GraphicsWindow::selectColourMap()
{
    //Get the first SEQUENTIAL colour map in list.
    ColourMap cMap = CMList::getMapList(CMClassification::SEQUENTIAL)[0];

    //Sets the current map
    ColourManager::setColourMapIndex(cMap.getIndex());
}

void GraphicsWindow::generateBarList(int size)
{
    ChartBarList.clear();
    float AxisHeight = abs(AxisOrigin().y()-AxisY().y());
    float AxisWidth = abs(AxisOrigin().x()-AxisX().x());
    float barWidth = AxisWidth/(float)size;
    float movingX=AxisOrigin().x();

    for(int i=0;i<size;i++){
        float value = qrand()%100;
        float h = AxisHeight*(value/100.0f);
        QRectF r(movingX,AxisOrigin().y(),barWidth,h);
        ChartBar bar("Student " + QString::number(i),r,value);
        ChartBarList.push_back(bar);
        movingX+=barWidth;
    }
}

void GraphicsWindow::drawAxis()
{
    glColor3f(0,0,0);
    glBegin(GL_LINES);
    glVertex2f(AxisOrigin().x(),AxisOrigin().y());
    glVertex2f(AxisX().x(),AxisX().y());
    glVertex2f(AxisOrigin().x(),AxisOrigin().y());
    glVertex2f(AxisY().x(),AxisY().y());
    glEnd();
}

void GraphicsWindow::drawChart(QVector<ChartBar> list)
{
    for(int i=0;i<list.size();i++){
        drawBar(list[i]);
    }
}

void GraphicsWindow::drawBar(ChartBar bar)
{

    float upperY = bar.top();
    float lowerY = bar.bottom();
    float leftX = bar.left();
    float rightX = bar.right();

    //Instantiate Colour Manager
    ColourManager manager(0,100);

    //Get Colour value from
    Colour col = manager.getInterpolatedColour(bar.Value());

    //Set Colour
    glColor3f(col.getR(),col.getG(),col.getB());

    glBegin(GL_QUADS);
    glVertex2f(leftX,upperY);
    glVertex2f(rightX,upperY);
    glVertex2f(rightX,lowerY);
    glVertex2f(leftX,lowerY);
    glEnd();

    glColor3f(1,1,1);
    glBegin(GL_LINE_LOOP);
    glVertex2f(leftX,upperY);
    glVertex2f(rightX,upperY);
    glVertex2f(rightX,lowerY);
    glVertex2f(leftX,lowerY);
    glEnd();

}

void GraphicsWindow::sortChartByValue()
{
    //----------------Timer------------------------//
    std::clock_t start = std::clock();
    double duration;
    //---------------------------------------------//
    std::sort(ChartBarList.begin(),ChartBarList.end(),
              [](const ChartBar &a, const ChartBar &b){
        return(a.Value() < b.Value());
    });
    //----------------------End-Timer---------------------------//
    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    //qDebug() << "Time to sort list by value = " << duration;
    //----------------------------------------------------------//

    float AxisWidth = abs(AxisOrigin().x()-AxisX().x());
    float barWidth = AxisWidth/(float)ChartBarList.size();
    float movingX=AxisOrigin().x();

    for(int i=0;i<ChartBarList.size();i++){
        ChartBar &bar = ChartBarList[i];
        bar.setLeft(movingX);
        movingX+=barWidth;
        bar.setRight(movingX);
    }
    update();
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
int GraphicsWindow::BarCount() const
{
    return m_BarCount;
}

void GraphicsWindow::setBarCount(int BarCount)
{
    m_BarCount = BarCount;
}

















void GraphicsWindow::setupView()
{
    glClearColor(1,1,1,1);
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
    setAxisY(QPointF(xDist,(height()-yDist)));
}

void GraphicsWindow::setupData()
{
    setupAxis();
}




