#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <cstddef>
#include "operations.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = NULL);
    ~MainWindow();

private slots:
    void OnPushButton1Clicked();
    void OnPushButton2Clicked();
    void OnPushButton3Clicked();
    void OnPushButton4Clicked();
    void OnPushButton5Clicked();
    void OnPushButton6Clicked();
    void OnPushButton7Clicked();
    void OnPushButton8Clicked();
    void OnPushButton9Clicked();
    void OnPushButton0Clicked();
    void OnPushButtonPlusClicked();
    void OnPushButtonMinusClicked();
    void OnPushButtonModuloClicked();
    void OnPushButtonEqualsClicked();
    void OnPushButtonClearClicked();

private:
    Ui::MainWindow *ui;
    bool isElement1Confirmed = false;
    bool isElement2Confirmed = false;
    enum enums::Operations currentOperation = enums::NONE;

    void SetConnectionsToWidgets();
    void ConnectKeypad();
    void ConnectOperators();
    void ConnectControlWidgets();
    void AppendTextInElementActiveWidget(QString textToAppend);
    void SwitchElementConfirmationWidget();
    bool ParseToUnsignedLongLong(QString number, unsigned long long & convertee);
    unsigned long long PerformChosenOperation(unsigned long long number1, unsigned long long number2);

};

#endif // MAIN_WINDOW_H
