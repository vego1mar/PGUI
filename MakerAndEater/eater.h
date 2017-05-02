#ifndef EATER_H
#define EATER_H

#include <QThread>

namespace logic
{
    class Eater : public QThread
    {
        Q_OBJECT

    private:
        unsigned long volatile interval;
        bool volatile isPermittedToRunning;

    public:
        Eater( unsigned long productionInterval );
        ~Eater() = default;

    private:
        Eater() = default;
        Eater( const Eater & rhs ) = default;
        Eater & operator= ( const Eater & rhs );

    public:
        void run() Q_DECL_OVERRIDE;
        unsigned long getEatingInterval();
        bool getPermissionToRun();
        void setEatingInterval( unsigned long eatingInterval );
        void setPermissionToRun( bool isPermittedTo );

    signals:
        void Eated();

    };
}

#endif // EATER_H
