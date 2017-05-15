#include "DBHelper.hpp"
#include <QStringList>
#include <QSqlError>
#include <cstddef>

QSqlDatabase dbh::DBHelper::dbConnector;

dbh::DBHelper & dbh::DBHelper::operator= ( const DBHelper & rhs )
{
    if ( &rhs != this ) {
        // This should be a utility class.
    }

    return *this;
}

std::vector<std::string> dbh::DBHelper::GetListOfAvailableDrivers()
{
    QStringList list = QSqlDatabase::drivers();
    QStringList::Iterator iterator = list.begin();
    std::vector<std::string> vectorList;

    while ( iterator != list.end() ) {
        QString value = *(iterator);
        vectorList.push_back( value.toStdString() );
        iterator++;
    }

    return vectorList;
}

bool dbh::DBHelper::OpenConnectionToExcelODBC( std::string driverName, std::string connectionString, std::string & error )
{
    QString driver = QString::fromStdString( driverName );
    QString name = QString::fromStdString( connectionString );
    dbConnector = QSqlDatabase::addDatabase( driver, name );

    if ( dbConnector.isValid() ) {
        dbConnector.open();
    }

    if ( !dbConnector.isOpen() ) {
        QString text = dbConnector.lastError().text();
        error = text.toStdString();
    }

    return dbConnector.isOpen();
}

void dbh::DBHelper::CloseConnectionToExcelODBC( std::string connectionString )
{
    dbConnector.close();
    QString name = QString::fromStdString( connectionString );
    dbConnector.removeDatabase( name );
}
