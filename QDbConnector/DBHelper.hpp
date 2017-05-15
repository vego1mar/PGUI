#ifndef DB_HELPER_HPP
#define DB_HELPER_HPP

#include <QSqlDatabase>
#include <vector>
#include <string>

namespace dbh
{

class DBHelper
    {

    private :
        static QSqlDatabase dbConnector;

        DBHelper() = default;
        DBHelper( const DBHelper & rhs ) = default;
        DBHelper & operator= ( const DBHelper & rhs );
        ~DBHelper() = default;

    public :
        static std::vector<std::string> GetListOfAvailableDrivers();
        static bool OpenConnectionToExcelODBC( std::string driverName, std::string connectionString, std::string & error );
        static void CloseConnectionToExcelODBC( std::string connectionString );

    };

}

#endif // !DB_HELPER_HPP
