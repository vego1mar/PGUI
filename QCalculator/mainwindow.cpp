#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    SetConnectionsToWidgets();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SetConnectionsToWidgets()
{
    ConnectKeypad();
    ConnectOperators();
    ConnectControlWidgets();
}

void MainWindow::ConnectKeypad()
{
    ui->centralWidget->connect(ui->pushButton1,SIGNAL(clicked()),this,SLOT(OnPushButton1Clicked()));
    ui->centralWidget->connect(ui->pushButton2,SIGNAL(clicked()),this,SLOT(OnPushButton2Clicked()));
    ui->centralWidget->connect(ui->pushButton3,SIGNAL(clicked()),this,SLOT(OnPushButton3Clicked()));
    ui->centralWidget->connect(ui->pushButton4,SIGNAL(clicked()),this,SLOT(OnPushButton4Clicked()));
    ui->centralWidget->connect(ui->pushButton5,SIGNAL(clicked()),this,SLOT(OnPushButton5Clicked()));
    ui->centralWidget->connect(ui->pushButton6,SIGNAL(clicked()),this,SLOT(OnPushButton6Clicked()));
    ui->centralWidget->connect(ui->pushButton7,SIGNAL(clicked()),this,SLOT(OnPushButton7Clicked()));
    ui->centralWidget->connect(ui->pushButton8,SIGNAL(clicked()),this,SLOT(OnPushButton8Clicked()));
    ui->centralWidget->connect(ui->pushButton9,SIGNAL(clicked()),this,SLOT(OnPushButton9Clicked()));
    ui->centralWidget->connect(ui->pushButton0,SIGNAL(clicked()),this,SLOT(OnPushButton0Clicked()));
}

void MainWindow::ConnectOperators()
{
    ui->centralWidget->connect(ui->pushButtonPlus,SIGNAL(clicked()),this,SLOT(OnPushButtonPlusClicked()));
    ui->centralWidget->connect(ui->pushButtonMinus,SIGNAL(clicked()),this,SLOT(OnPushButtonMinusClicked()));
    ui->centralWidget->connect(ui->pushButtonModulo,SIGNAL(clicked()),this,SLOT(OnPushButtonModuloClicked()));
}

void MainWindow::ConnectControlWidgets()
{
    ui->centralWidget->connect(ui->pushButtonEquals,SIGNAL(clicked()),this,SLOT(OnPushButtonEqualsClicked()));
    ui->centralWidget->connect(ui->pushButtonClear,SIGNAL(clicked()),this,SLOT(OnPushButtonClearClicked()));
}

void MainWindow::AppendTextInElementActiveWidget(QString textToAppend)
{
    if (!isElement1Confirmed){
        QString newText = ui->labelForElement1->text();
        newText += textToAppend;
        ui->labelForElement1->setText(newText);
    }
    else
    if (!isElement2Confirmed){
        QString newText = ui->labelForElement2->text();
        newText += textToAppend;
        ui->labelForElement2->setText(newText);
        }
}

void MainWindow::OnPushButton1Clicked()
{
    AppendTextInElementActiveWidget("1");
}

void MainWindow::OnPushButton2Clicked()
{
    AppendTextInElementActiveWidget("2");
}

void MainWindow::OnPushButton3Clicked()
{
    AppendTextInElementActiveWidget("3");
}

void MainWindow::OnPushButton4Clicked()
{
    AppendTextInElementActiveWidget("4");
}

void MainWindow::OnPushButton5Clicked()
{
    AppendTextInElementActiveWidget("5");
}

void MainWindow::OnPushButton6Clicked()
{
    AppendTextInElementActiveWidget("6");
}

void MainWindow::OnPushButton7Clicked()
{
    AppendTextInElementActiveWidget("7");
}

void MainWindow::OnPushButton8Clicked()
{
    AppendTextInElementActiveWidget("8");
}

void MainWindow::OnPushButton9Clicked()
{
    AppendTextInElementActiveWidget("9");
}

void MainWindow::OnPushButton0Clicked()
{
    AppendTextInElementActiveWidget("0");
}

void MainWindow::SwitchElementConfirmationWidget()
{
    if (!isElement1Confirmed){
        isElement1Confirmed = true;
    }
    else
    if (!isElement2Confirmed){
        isElement2Confirmed = true;
    }
}

void MainWindow::OnPushButtonPlusClicked()
{
    SwitchElementConfirmationWidget();
    currentOperation = enums::PLUS;
}

void MainWindow::OnPushButtonMinusClicked()
{
    SwitchElementConfirmationWidget();
    currentOperation = enums::MINUS;
}

void MainWindow::OnPushButtonModuloClicked()
{
    SwitchElementConfirmationWidget();
    currentOperation = enums::MODULO;
}

bool MainWindow::ParseToUnsignedLongLong(QString number, unsigned long long & convertee)
{
    bool isConverted = false;
    const int CONVERSION_BASE = 10;
    convertee = number.toULongLong(&isConverted,CONVERSION_BASE);
    return isConverted;
}

void MainWindow::OnPushButtonEqualsClicked()
{
    unsigned long long number1;
    unsigned long long number2;

    if (!ParseToUnsignedLongLong(ui->labelForElement1->text(),number1)) {
        ui->labelForResult->setText("Invalid first element!");
    }

    if (!ParseToUnsignedLongLong(ui->labelForElement2->text(),number2)) {
        ui->labelForResult->setText("Invalid second element!");
    }

    unsigned long long result = PerformChosenOperation(number1,number2);
    QString resultText = QString::fromStdString(std::to_string(result));
    ui->labelForResult->setText(resultText);
}

unsigned long long MainWindow::PerformChosenOperation(unsigned long long number1, unsigned long long number2)
{
    switch (currentOperation) {
    case enums::PLUS:
        return number1 + number2;
    case enums::MINUS:
        return number1 - number2;
    case enums::MODULO:
        return number1 % number2;
    case enums::NONE:
        break;
    }

    return 0;
}

void MainWindow::OnPushButtonClearClicked()
{
    ui->labelForElement1->setText("");
    ui->labelForElement2->setText("");
    ui->labelForResult->setText("");
    isElement1Confirmed = false;
    isElement2Confirmed = false;
    currentOperation = enums::NONE;
}
