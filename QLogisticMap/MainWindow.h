#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QResizeEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow * ui;

public:
    explicit MainWindow( QWidget * parent = nullptr );
    ~MainWindow();

protected:
    void resizeEvent( QResizeEvent * event ) override;

private:
    void connectMenuEntries();

private slots:
    void menuActionUpdate();

};

#endif // !MAINWINDOW_H
