#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow( QWidget * parent )
    : QMainWindow( parent )
    , ui( new Ui::MainWindow )
    , makerOfC( nullptr )
    , makerOfQ( nullptr )
    , makerOfT( nullptr )
    , makerOfA( nullptr )
    , eater( nullptr )
    , buffer( std::string() )
{
    ui->setupUi( this );
    connectUIWidgets();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OnMakerCreation( QString product )
{
    if ( buffer.size() < BUFFER_SIZE ) {
        ui->qtTextEdit->moveCursor( QTextCursor::End );
        ui->qtTextEdit->insertPlainText( product );
        buffer.append( product.toStdString() );
    }

    updateBufferProgressBar();
}

void MainWindow::OnEaterConsumption()
{
    if ( buffer.size() >= EATER_CONSUMES_NUMBER ) {
        QString text = ui->qtTextEdit->toPlainText();
        text.remove( 0, EATER_CONSUMES_NUMBER );
        ui->qtTextEdit->setText( text );
        std::string newBuffer = buffer.substr( EATER_CONSUMES_NUMBER, buffer.size() - EATER_CONSUMES_NUMBER );
        buffer = newBuffer;
    }

    updateBufferProgressBar();
}

void MainWindow::createAndStartMakersAndEater()
{
    makerOfC = new logic::Maker( "C", MAKER_OF_C_MILISECONDS_INTERVAL );
    makerOfQ = new logic::Maker( "Q", MAKER_OF_Q_MILISECONDS_INTERVAL );
    makerOfT = new logic::Maker( "T", MAKER_OF_T_MILISECONDS_INTERVAL );
    makerOfA = new logic::Maker( "A", MAKER_OF_A_MILISECONDS_INTERVAL );
    connectAndStartMakerThread( makerOfC );
    connectAndStartMakerThread( makerOfQ );
    connectAndStartMakerThread( makerOfT );
    connectAndStartMakerThread( makerOfA );
    createConnectAndStartEater();
}

void MainWindow::OnQtStartPushButtonClicked()
{
    createAndStartMakersAndEater();
    ui->qtStartPushButton->setEnabled( false );
    ui->qtStopPushButton->setEnabled( true );
}

void MainWindow::connectUIWidgets()
{
    connect( ui->qtStartPushButton, SIGNAL(clicked()), this, SLOT(OnQtStartPushButtonClicked()) );
    connect( ui->qtStopPushButton, SIGNAL(clicked()), this, SLOT(OnQtStopPushButtonClicked()) );
    connect( ui->qtEaterIntervalSpinBox, SIGNAL(valueChanged(int)), this, SLOT(OnQtEaterIntervalSpinBoxValueChanged(int)) );
}

void MainWindow::connectAndStartMakerThread( logic::Maker * makerThread )
{
    connect( makerThread, SIGNAL(Produced(QString)), SLOT(OnMakerCreation(QString)) );
    connect( makerThread, SIGNAL(finished()), makerThread, SLOT(deleteLater()) );
    makerThread->start();
}

void MainWindow::createConnectAndStartEater()
{
    eater = new logic::Eater( ui->qtEaterIntervalSpinBox->value() );
    connect( eater, SIGNAL(Eated()), SLOT(OnEaterConsumption()) );
    connect( eater, SIGNAL(finished()), eater, SLOT(deleteLater()) );
    eater->start();
}

void MainWindow::updateBufferProgressBar()
{
    double fraction = static_cast<double>( buffer.size() ) / static_cast<double>( BUFFER_SIZE );
    int percentage = static_cast<int>( fraction * 100.0 );
    ui->qtBufferProgressBar->setValue( percentage );
}

void MainWindow::OnQtStopPushButtonClicked()
{
    ui->qtStopPushButton->setEnabled( false );
    makerOfC->setPermissionToRun( false );
    makerOfQ->setPermissionToRun( false );
    makerOfT->setPermissionToRun( false );
    makerOfA->setPermissionToRun( false );
    eater->setPermissionToRun( false );
    ui->qtStartPushButton->setEnabled( true );
}

void MainWindow::OnQtEaterIntervalSpinBoxValueChanged( int value )
{
    if ( eater != nullptr ) {
        eater->setEatingInterval( value );
    }
}
