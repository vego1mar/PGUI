#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "DBHelper.hpp"
#include "ODBCSourceDataTypes.hpp"
#include <QStringList>
#include <QFileDialog>
#include <QMessageBox>
#include <vector>
#include <string>

MainWindow::MainWindow( QWidget * parent ) :
    QMainWindow( parent ),
    ui( new Ui::MainWindow )
{
    ui->setupUi( this );
    connectUISignals();
    refreshUIAtStart();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OnPbRefreshDriverListClicked()
{
    std::vector<std::string> driversList = dbh::DBHelper::GetListOfAvailableDrivers();
    ui->lwDrivers->clear();

    for ( std::size_t i=0; i<driversList.size(); i++ ) {
        QString driverName = QString::fromStdString( driversList[i] );
        ui->lwDrivers->addItem( driverName );
    }

    ui->lwDrivers->setCurrentRow( 0 );
}

void MainWindow::connectUISignals()
{
    connectSignalsForDBConnectionTab();
}

void MainWindow::connectSignalsForDBConnectionTab()
{
    connect( ui->pbRefreshDriverList, SIGNAL(clicked()), this, SLOT(OnPbRefreshDriverListClicked()) );
    connect( ui->cbODBCSourceData, SIGNAL(currentIndexChanged(int)), this, SLOT(OnCbODBCSourceDataCurrentIndexChanged(int)) );
    connect( ui->pbSelectAFile, SIGNAL(clicked()), this, SLOT(OnPbSelectAFileClicked()) );
    connect( ui->pbConnect, SIGNAL(clicked()), this, SLOT(OnPbConnectClicked()) );
    connect( ui->pbDisconnect, SIGNAL(clicked()), this, SLOT(OnPbDisconnectClicked()) );
}

void MainWindow::refreshUIAtStart()
{
    OnPbRefreshDriverListClicked();
    itemyODBCSourceDataComboBox();
    OnCbODBCSourceDataCurrentIndexChanged( odbc::MS_EXCEL_2013_2016 );
}

void MainWindow::itemyODBCSourceDataComboBox()
{
    ui->cbODBCSourceData->addItem( "Microsoft Excel 97, 2000, 2002, 2003" );
    ui->cbODBCSourceData->addItem( "Microsoft Excel 2013, 2016" );
    ui->cbODBCSourceData->setCurrentIndex( odbc::MS_EXCEL_2013_2016 );
}

void MainWindow::OnCbODBCSourceDataCurrentIndexChanged( int index )
{
    switch ( index ) {
    case odbc::MS_EXCEL_97_2000_2002_2003 :
        updateODBCSourceDataTextEdit( tr( "Driver={Microsoft Excel Driver (*.xls)};DriverId=790;Dbq=" ) );
        break;
    case odbc::MS_EXCEL_2013_2016 :
        updateODBCSourceDataTextEdit( tr( "DRIVER={Microsoft Excel Driver (*.xls, *.xlsx, *.xlsm, *.xlsb)};DBQ=" ) );
        break;
    default :
        ui->teODBCSourceData->setText( "Driver unrecognized" );
        break;
    }
}

void MainWindow::OnPbSelectAFileClicked()
{
    QString caption = tr( "Select a file" );
    QString directory = QDir::currentPath();
    QString fileName = QFileDialog::getOpenFileName( this, caption, directory );
    ui->teSelectAFile->setText( fileName );
    OnCbODBCSourceDataCurrentIndexChanged( ui->cbODBCSourceData->currentIndex() );
}

void MainWindow::updateODBCSourceDataTextEdit( QString driverName )
{
    QString path = ui->teSelectAFile->toPlainText();
    // Windows specific path
    path.replace( '/', "\\\\" );
    ui->teODBCSourceData->setText( driverName + path );
}

void MainWindow::OnPbConnectClicked()
{
    QString selectedDriver = ui->lwDrivers->currentItem()->text();
    std::string driverName = selectedDriver.toStdString();
    QString buildedConnectionString = ui->teODBCSourceData->toPlainText();
    std::string connectionString = buildedConnectionString.toStdString();
    QString title = tr( "Opening connection to Excel ODBC" );
    std::string errorInfo;

    if ( dbh::DBHelper::OpenConnectionToExcelODBC( driverName, connectionString, errorInfo ) ) {
        ui->pbDisconnect->setEnabled( true );
        ui->pbConnect->setEnabled( false );
        QString text = tr( "Connection opened successfully." );
        QMessageBox::information( this, title, text );
    }
    else {
        ui->pbDisconnect->setEnabled( false );
        ui->pbConnect->setEnabled( true );
        QString text = tr("Connection opening fails.") + QString::fromStdString( errorInfo );
        QMessageBox::information( this, title, text );
    }
}

void MainWindow::OnPbDisconnectClicked()
{
    QString buildedConnectionString = ui->teODBCSourceData->toPlainText();
    std::string connectionString = buildedConnectionString.toStdString();
    dbh::DBHelper::CloseConnectionToExcelODBC( connectionString );
}
