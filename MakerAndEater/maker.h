#ifndef MAKER_H
#define MAKER_H

#include <QThread>

namespace logic
{
    class Maker : public QThread
    {
        Q_OBJECT

    private:
        QString productee;
        unsigned long interval;
        bool volatile isPermittedToRunning;

    public:
        Maker( QString outputToProduce, unsigned long productionInterval );
        ~Maker() = default;

    private:
        Maker() = default;
        Maker( const Maker & rhs ) = default;
        Maker & operator= ( const Maker & rhs );

    public:
        void run() Q_DECL_OVERRIDE;
        bool getPermissionToRun();
        void setPermissionToRun( bool isPermittedTo );

    signals:
        void Produced( QString product );

    };
}

#endif // MAKER_H
