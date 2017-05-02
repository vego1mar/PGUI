#include "maker.h"

logic::Maker::Maker( QString outputToProduce, unsigned long productionInterval )
    : productee( outputToProduce )
    , interval( productionInterval )
    , isPermittedToRunning( true )
{
}

logic::Maker & logic::Maker::operator= ( const Maker & rhs )
{
    if ( &rhs != this ) {
        productee = rhs.productee;
        interval = rhs.interval;
        isPermittedToRunning = rhs.isPermittedToRunning;
    }

    return *this;
}

void logic::Maker::run()
{
    while ( isPermittedToRunning ) {
        msleep( interval );
        emit Produced( productee );
    }
}

bool logic::Maker::getPermissionToRun()
{
    return isPermittedToRunning;
}

void logic::Maker::setPermissionToRun( bool isPermittedTo )
{
    isPermittedToRunning = isPermittedTo;
}
