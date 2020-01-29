#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "Fibo.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_testValue, SIGNAL(clicked()), this, SLOT(buttonClick()));
    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(close()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//button is clicked
void MainWindow::buttonClick()
{
    double t_i, t_r;
    uint16_t value = static_cast<uint16_t>(ui->spinBox_fibo->value());
    uint64_t sum = 0u;

    t_i = Fibo::time_func(value, "fib_i", &sum);
    t_r = Fibo::time_func(value, "fib_r", &sum);

    QString text("Results: ");
    text.append("recursive=");
    text.append(QString::number(t_r, 'f', 5));
    text.append("s iterative=");
    text.append(QString::number(t_i, 'f', 5));
    text.append("s sum=");
    text.append(QString::number(sum));
    ui->label_results->setText(text);
}
