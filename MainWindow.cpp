#include "MainWindow.h"
#include <QDebug>
#include <string>
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  connect(ui->pushButtonCalculate, &QPushButton::clicked, this,
          &MainWindow::startCalculation);
}

void MainWindow::outputValues()
{
  QString text = "Test";
  // Ausgabetext zusammenbasteln
  this->ui->plainTextEditAusgabe->setPlainText(text);
}

void MainWindow::startCalculation()
{
  int u1 = 0;  // Spannung U1 in uV
  int u2 = 0;  // Spannung U2 in uV
  int reihe = 0;
  u1 = this->readU1();
  u2 = this->readU2();
  reihe = this->readReihe();

  // Berechnung

  outputValues();

  // Zum Testen (Braucht es später nicht)
  qDebug() << "U1: " << u1 << endl;
  qDebug() << "U2: " << u2 << endl;
  qDebug() << "Reihe: ";
  if (reihe == E3)
  {
    qDebug() << "E3" << endl;
  }
  if (reihe == E6)
  {
    qDebug() << "E6" << endl;
  }
  if (reihe == E12)
  {
    qDebug() << "E12" << endl;
  }
  if (reihe == E24)
  {
    qDebug() << "E24" << endl;
  }
}

double MainWindow::calculate(int u1, int u2, int reihe)
{
}

int MainWindow::readReihe()
{
  int value = 0;
  if (ui->radioButtonE3->isChecked())
  {
    value = E3;
  }
  if (ui->radioButtonE6->isChecked())
  {
    value = E6;
  }
  if (ui->radioButtonE12->isChecked())
  {
    value = E12;
  }
  if (ui->radioButtonE24->isChecked())
  {
    value = E24;
  }
  return value;
}

int MainWindow::readU1()
{
  int value = 0;
  QString text;
  value = ui->textEditU1->toPlainText().toInt();
  text = ui->comboBoxU1->currentText();
  // qDebug() << text;
  if (0 == QString::compare(text, "mV"))
  {
    value = value * 1000;  // Spannung in uV umrechnen
  }
  if (0 == QString::compare(text, "V"))
  {
    value = value * 1000 * 1000;  // Spannung in uV umrechnen
  }
  if (0 == QString::compare(text, "kV"))
  {
    value = value * 1000 * 1000 * 1000;  // Spannung in uV umrechnen
  }
  return value;
}

int MainWindow::readU2()
{
  int value = 0;
  QString text;
  value = ui->textEditU2->toPlainText().toInt();
  text = ui->comboBoxU2->currentText();
  // qDebug() << text;
  if (0 == QString::compare(text, "mV"))
  {
    value = value * 1000;  // Spannung in uV umrechnen
  }
  if (0 == QString::compare(text, "V"))
  {
    value = value * 1000 * 1000;  // Spannung in uV umrechnen
  }
  if (0 == QString::compare(text, "kV"))
  {
    value = value * 1000 * 1000 * 1000;  // Spannung in uV umrechnen
  }
  return value;
}

MainWindow::~MainWindow()
{
  delete ui;
}
