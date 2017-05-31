#ifndef LOGISTIC_MAP_WIDGET_H
#define LOGISTIC_MAP_WIDGET_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <random>

typedef unsigned int uint;

class LogisticMapWidget : public QWidget
{
    Q_OBJECT

private:
    std::mt19937 generator;

public:
    explicit LogisticMapWidget( QWidget * parent = nullptr );
    ~LogisticMapWidget() = default;
    void update();

private:
    LogisticMapWidget() = default;
    LogisticMapWidget( const LogisticMapWidget & rhs ) = default;
    LogisticMapWidget & operator= ( const LogisticMapWidget & rhs );
    void setDefaultPalette();
    void drawLogisticMap( QPainter & painter );
    double iterate( double ratio, double x );
    double iterateChaotic( double ratio, uint numberOfLoops, double initialArgument = 0.5 );
    double getRandomDoubleUniformed();

protected:
    void paintEvent( QPaintEvent * event ) override;

};

#endif // !LOGISTIC_MAP_WIDGET_H
