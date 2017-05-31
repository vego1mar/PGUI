#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow( QWidget * parent )
    : QMainWindow( parent )
    , ui( new Ui::MainWindow )
{
    ui->setupUi( this );
    connectMenuEntries();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connectMenuEntries()
{
    connect( ui->actionUpdate, SIGNAL(triggered()), this, SLOT(menuActionUpdate()) );
}

void MainWindow::menuActionUpdate()
{
    ui->lmWidget->update();
}

void MainWindow::resizeEvent( QResizeEvent * )
{
    int x = ui->lmWidget->geometry().x();
    int y = ui->lmWidget->geometry().y();
    const int BOTTOM_WINDOW_PADDING = 20;
    int width = ui->centralWidget->geometry().width() - BOTTOM_WINDOW_PADDING;
    int height = ui->centralWidget->geometry().height() - BOTTOM_WINDOW_PADDING;
    ui->lmWidget->setGeometry( x, y, width, height );
}
