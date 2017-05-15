#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <cstddef>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private :
    Ui::MainWindow * ui;

public :
    explicit MainWindow( QWidget * parent = NULL );
    ~MainWindow();

private slots :
    void OnPbRefreshDriverListClicked();
    void OnCbODBCSourceDataCurrentIndexChanged( int index );
    void OnPbSelectAFileClicked();
    void OnPbConnectClicked();
    void OnPbDisconnectClicked();

private :
    void connectUISignals();
    void connectSignalsForDBConnectionTab();
    void refreshUIAtStart();
    void itemyODBCSourceDataComboBox();
    void updateODBCSourceDataTextEdit( QString driverName );

};

#endif // !MAINWINDOW_H
