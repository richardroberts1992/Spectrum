#include "chartbar.h"

ChartBar::ChartBar(QString name, QRectF rect, float value)
{
    setName(name);
    setValue(value);
    this->setRect(rect.topLeft().x(),rect.topLeft().y(),rect.width(),rect.height());
}
ChartBar::ChartBar()
{

}

ChartBar::~ChartBar()
{

}
QString ChartBar::Name() const
{
    return m_Name;
}

void ChartBar::setName(const QString &Name)
{
    m_Name = Name;
}
float ChartBar::Value() const
{
    return m_Value;
}

void ChartBar::setValue(float Value)
{
    m_Value = Value;
}



