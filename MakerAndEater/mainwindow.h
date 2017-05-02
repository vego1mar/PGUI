#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "maker.h"
#include "eater.h"
#include <cstddef>
#include <string>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    const unsigned long MAKER_OF_C_MILISECONDS_INTERVAL = 1000;
    const unsigned long MAKER_OF_Q_MILISECONDS_INTERVAL = 750;
    const unsigned long MAKER_OF_T_MILISECONDS_INTERVAL = 500;
    const unsigned long MAKER_OF_A_MILISECONDS_INTERVAL = 250;
    const unsigned int EATER_CONSUMES_NUMBER = 4;
    const std::size_t BUFFER_SIZE = 996;

private:
    Ui::MainWindow * ui;
    logic::Maker * makerOfC;
    logic::Maker * makerOfQ;
    logic::Maker * makerOfT;
    logic::Maker * makerOfA;
    logic::Eater * eater;
    std::string buffer;

public:
    explicit MainWindow( QWidget * parent = NULL );
    ~MainWindow();

private:
    void createAndStartMakersAndEater();
    void connectUIWidgets();
    void connectAndStartMakerThread( logic::Maker * makerThread );
    void createConnectAndStartEater();
    void updateBufferProgressBar();

public slots:
    void OnMakerCreation( QString product );
    void OnEaterConsumption();

private slots:
    void OnQtStartPushButtonClicked();
    void OnQtStopPushButtonClicked();
    void OnQtEaterIntervalSpinBoxValueChanged( int value );

};

#endif // MAINWINDOW_H
