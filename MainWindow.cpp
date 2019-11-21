#include "MainWindow.h"
#include <QDebug>
#include <string>
#include "ui_MainWindow.h"

// Globale Variable
double r1 = 0;
double r2 = 0;

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
  MainWindow::calculate(u1, u2, reihe);

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

void MainWindow::calculate(int u1, int u2, int reihe)
{
  int r1i = 0;
  int r2i = 0;
  double ereihe[24];
  double prop;
  if (reihe == 1)
  {
    double ereihe[3] = {1.0, 2.2, 4.7};  // E3
  }

  if (reihe == 4)
  {
    double ereihe[24] = {1.0, 1.1, 1.2, 1.3, 1.5, 1.6, 1.8, 2.0,
                         2.2, 2.4, 2.7, 3.0, 3.3, 3.6, 3.9, 4.3,
                         4.7, 5.1, 5.6, 6.2, 6.8, 7.5, 8.2, 9.1};
  }

  double widWerte[3][3];
  double zwischenWert[3][3];
  int anz = 0;

  // Verhältinis berechnen
  prop = u2 / u1;

  // Verhältnis suchen
  for (int i = 0; i < 3; ++i)
  {
    for (int j = 0; j < 3; ++j)
    {
      widWerte[i][j] = ereihe[j] / (ereihe[j] + ereihe[i]);
      zwischenWert[i][j] = prop - widWerte[i][j];

      if (zwischenWert[i][j] < 0)  // Betrag berechnen
      {
        zwischenWert[i][j] *= (-1);
      }

      if (zwischenWert[i][j] < zwischenWert[r2i][r1i])
      {
        r2i = i;  // y-achse
        r1i = j;  // x-achse
        anz++;
      }
    }
  }
  r1 = ereihe[r1i];
  r2 = ereihe[r2i];
  qDebug() << "r1=" << r1 << " r2=" << r2 << endl;
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
