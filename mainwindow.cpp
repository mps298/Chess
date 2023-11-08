#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    setFixedSize(width(),height());

    connect(ui->boardWidget, SIGNAL(figureIsCaptured(const Figure&)), ui->capturedWidget, SLOT(addCapturedFigure(const Figure&)));
    connect(ui->boardWidget, SIGNAL(newGameSignal()), ui->capturedWidget, SLOT(clearCapturedFigures()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_newGameButton_clicked()
{
    ui->boardWidget->newGame();
}
