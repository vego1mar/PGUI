#include "LogisticMapWidget.h"
#include <QPen>

LogisticMapWidget::LogisticMapWidget( QWidget * parent )
    : QWidget( parent )
    , generator()
{
    setDefaultPalette();
    generator.seed( std::random_device()() );
}

void LogisticMapWidget::update()
{
    QWidget::update();
}

LogisticMapWidget & LogisticMapWidget::operator= ( const LogisticMapWidget & rhs )
{
    if ( &rhs != this ) {
        generator = rhs.generator;
    }

    return *this;
}

void LogisticMapWidget::setDefaultPalette()
{
    QPalette widgetPalette = QPalette();
    widgetPalette.setColor( QPalette::Background, Qt::white );
    setAutoFillBackground( true );
    setPalette( widgetPalette );
}

void LogisticMapWidget::drawLogisticMap( QPainter & painter )
{
    const double PEN_WIDTH = 0.66;
    const uint NUMBER_OF_LOOPS = 220500;
    const uint NUMBER_OF_CYCLES = 1070;
    QPen pen( Qt::black, PEN_WIDTH, Qt::DotLine );
    painter.setPen( pen );
    double minimumRatio = 0.0;
    double maximumRatio = 4.0;
    double currentRatio = minimumRatio;
    double currentChaotic;
    const int WIDGET_WIDTH = static_cast<double>( size().width() ) / maximumRatio;
    const int WIDGET_HEIGHT = size().height();

    for ( uint i=0; i<NUMBER_OF_LOOPS; i++ ) {
        currentRatio += ( maximumRatio - minimumRatio ) / static_cast<double>( NUMBER_OF_LOOPS );
        currentChaotic = iterate( currentRatio, getRandomDoubleUniformed() );
        currentChaotic = iterateChaotic( currentRatio, NUMBER_OF_CYCLES, currentChaotic );
        painter.drawPoint( currentRatio * WIDGET_WIDTH, currentChaotic * WIDGET_HEIGHT );
    }
}

double LogisticMapWidget::iterate( double ratio, double x )
{
    if ( x <= 0.0 || x >= 4.0 ) {
        return 0.0;
    }

    return ratio * x * ( 1.0 - x );
}

double LogisticMapWidget::iterateChaotic( double ratio, uint numberOfLoops, double initialArgument )
{
    double x = initialArgument;

    for ( uint i=0; i<numberOfLoops; i++ ) {
        x = iterate( ratio, x );
    }

    return x;
}

double LogisticMapWidget::getRandomDoubleUniformed()
{
    std::uniform_real_distribution<> distribution( 0.0, 1.0 );
    return distribution( generator );
}

void LogisticMapWidget::paintEvent( QPaintEvent * )
{
    QPainter painter( this );
    painter.save();
    drawLogisticMap( painter );
    painter.restore();
}
