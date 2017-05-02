#include "eater.h"

logic::Eater::Eater( unsigned long productionInterval )
    : interval( productionInterval )
    , isPermittedToRunning( true )
{
}

logic::Eater & logic::Eater::operator= ( const Eater & rhs )
{
    if ( &rhs != this ) {
        interval = rhs.interval;
        isPermittedToRunning = rhs.isPermittedToRunning;
    }

    return *this;
}

void logic::Eater::run()
{
    while ( isPermittedToRunning ) {
        msleep( interval );
        emit Eated();
    }
}

unsigned long logic::Eater::getEatingInterval()
{
    return interval;
}

bool logic::Eater::getPermissionToRun()
{
    return isPermittedToRunning;
}

void logic::Eater::setEatingInterval( unsigned long eatingInterval )
{
    interval = eatingInterval;
}

void logic::Eater::setPermissionToRun( bool isPermittedTo )
{
    isPermittedToRunning = isPermittedTo;
}
