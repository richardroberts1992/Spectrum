#ifndef CHARTBAR_H
#define CHARTBAR_H
#include <QRectF>
#include <QString>

class ChartBar : public QRectF
{
public:
    ChartBar();
    ChartBar(QString name, QRectF rect, float value);
    ~ChartBar();

    QString Name() const;
    void setName(const QString &Name);

    float Value() const;
    void setValue(float Value);

private:

    QString m_Name;
    float m_Value;
};

#endif // CHARTBAR_H
