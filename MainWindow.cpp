#include "MainWindow.h"
#include <QDebug>
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  // **** Interaktives Verhalten initialisieren:
  /*
  connect(ui->pushButtonCalculate, &QPushButton::clicked, this,
          &MainWindow::readGUI);
  */
  connect(ui->pushButtonCalculate, &QPushButton::clicked, this,
          &MainWindow::startCalculation);
}

void MainWindow::startCalculation()
{
  int u1 = 0;
  int u2 = 0;
  int reihe = 0;
  u1 = this->readU1();
  u2 = this->readU2();
  qDebug() << "U1: " << u1 << endl;
  qDebug() << "U2: " << u2 << endl;
}

int MainWindow::readU1()
{
  int value = 0;
  value = ui->textEditU1->toPlainText().toInt();
  return value;
}

int MainWindow::readU2()
{
  int value = 0;
  value = ui->textEditU2->toPlainText().toInt();
  return value;
}

MainWindow::~MainWindow()
{
  delete ui;
}
