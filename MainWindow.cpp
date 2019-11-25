#include "MainWindow.h"
#include <QDebug>
#include <iostream>
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

void MainWindow::outputValues(double r1, double r2, bool possibility);
{
  double x1 = r1;  // R1
  double x2 = r2;  // R2
  bool ratio =
      possibility;  // das spannungsverhältnis erlaubt mehrere möglichkeiten.
  QString unit1 = "Ohm";
  QString unit2 = "Ohm";
  QString text;
  QString ratiotext =
      "Das Widerstandsverhältnis ist 1:1. R1 = R2. \nAlle Werte möglich.";
  if (ratio == 1)
  {
    text = ratiotext;
  }
  else
  {
    if ((x1 < 1000) && (x2 < 1000))
    {
      x1 = x1 * 1000;
      x2 = x2 * 1000;
    }

    if (x1 > 1000)
    {
      unit1 = "kOhm";
      x1 = x1 / 1000;
      if (x1 > 1000)
      {
        unit1 = "MOhm";
        x1 = x1 / 1000;
      }
    }

    if (x2 > 1000)
    {
      unit2 = "kOhm";
      x2 = x2 / 1000;
      if (x2 > 1000)
      {
        unit2 = "MOhm";
        x2 = x2 / 1000;
      }
    }
    text =
        QString("R1: %1 %2 \nR2: %3 %4").arg(r1).arg(unit1).arg(r2).arg(unit2);
  }

  qDebug() << text;

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
  bool possibility;

  // Berechnung
  possibility = MainWindow::calculate(u1, u2, reihe);

  outputValues(r1, r2, possibility);

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

bool MainWindow::calculate(int u1, int u2, int reihe)
{
  // Variablen
  int r1i = 0;
  int r2i = 0;
  r1 = 0;
  r2 = 0;

  double ereihe1[27] = {
      1,        2.2,      4.7,      10,        22,        47,       100,
      220,      470,      1000,     2200,      4700,      10000,    22000,
      47000,    100000,   220000,   470000,    1000000,   2200000,  4700000,
      10000000, 22000000, 47000000, 100000000, 220000000, 470000000};
  double ereihe2[54] = {
      1,         1.5,       2.2,       3.3,       4.7,      6.8,      10,
      15,        22,        33,        47,        68,       100,      150,
      220,       330,       470,       680,       1000,     1500,     2200,
      3300,      4700,      6800,      10000,     15000,    22000,    33000,
      47000,     68000,     100000,    150000,    220000,   330000,   470000,
      680000,    1000000,   1500000,   2200000,   3300000,  4700000,  6800000,
      10000000,  15000000,  22000000,  33000000,  47000000, 68000000, 100000000,
      150000000, 220000000, 330000000, 470000000, 680000000};
  double ereihe3[108] = {
      1,         1.2,       1.5,       1.8,       2.2,       2.7,
      3.3,       3.9,       4.7,       5.6,       6.8,       8.2,
      10,        12,        15,        18,        22,        27,
      33,        39,        47,        56,        68,        82,
      100,       120,       150,       180,       220,       270,
      330,       390,       470,       560,       680,       820,
      1000,      1200,      1500,      1800,      2200,      2700,
      3300,      3900,      4700,      5600,      6800,      8200,
      10000,     12000,     15000,     18000,     22000,     27000,
      33000,     39000,     47000,     56000,     68000,     82000,
      100000,    120000,    150000,    180000,    220000,    270000,
      330000,    390000,    470000,    560000,    680000,    820000,
      1000000,   1200000,   1500000,   1800000,   2200000,   2700000,
      3300000,   3900000,   4700000,   5600000,   6800000,   8200000,
      10000000,  12000000,  15000000,  18000000,  22000000,  27000000,
      33000000,  39000000,  47000000,  56000000,  68000000,  82000000,
      100000000, 120000000, 150000000, 180000000, 220000000, 270000000,
      330000000, 390000000, 470000000, 560000000, 680000000, 820000000};
  double ereihe4[216] = {
      1,         1.1,       1.2,       1.3,       1.5,       1.6,
      1.8,       2,         2.2,       2.4,       2.7,       3,
      3.3,       3.6,       3.9,       4.3,       4.7,       5.1,
      5.6,       6.2,       6.8,       7.5,       8.2,       9.1,
      10,        11,        12,        13,        15,        16,
      18,        20,        22,        24,        27,        30,
      33,        36,        39,        43,        47,        51,
      56,        62,        68,        75,        82,        91,
      100,       110,       120,       130,       150,       160,
      180,       200,       220,       240,       270,       300,
      330,       360,       390,       430,       470,       510,
      560,       620,       680,       750,       820,       910,
      1000,      1100,      1200,      1300,      1500,      1600,
      1800,      2000,      2200,      2400,      2700,      3000,
      3300,      3600,      3900,      4300,      4700,      5100,
      5600,      6200,      6800,      7500,      8200,      9100,
      10000,     11000,     12000,     13000,     15000,     16000,
      18000,     20000,     22000,     24000,     27000,     30000,
      33000,     36000,     39000,     43000,     47000,     51000,
      56000,     62000,     68000,     75000,     82000,     91000,
      100000,    110000,    120000,    130000,    150000,    160000,
      180000,    200000,    220000,    240000,    270000,    300000,
      330000,    360000,    390000,    430000,    470000,    510000,
      560000,    620000,    680000,    750000,    820000,    910000,
      1000000,   1100000,   1200000,   1300000,   1500000,   1600000,
      1800000,   2000000,   2200000,   2400000,   2700000,   3000000,
      3300000,   3600000,   3900000,   4300000,   4700000,   5100000,
      5600000,   6200000,   6800000,   7500000,   8200000,   9100000,
      10000000,  11000000,  12000000,  13000000,  15000000,  16000000,
      18000000,  20000000,  22000000,  24000000,  27000000,  30000000,
      33000000,  36000000,  39000000,  43000000,  47000000,  51000000,
      56000000,  62000000,  68000000,  75000000,  82000000,  91000000,
      100000000, 110000000, 120000000, 130000000, 150000000, 160000000,
      180000000, 200000000, 220000000, 240000000, 270000000, 300000000,
      330000000, 360000000, 390000000, 430000000, 470000000, 510000000,
      560000000, 620000000, 680000000, 750000000, 820000000, 910000000};

  double prop;

  // Verhältinis berechnen
  prop = double(u2) / double(u1);

  if (reihe == 1)
  {
    double widWerte[27][27];
    double zwischenWert[27][27];

    // Verhältnis suchen
    for (int i = 0; i < 27; ++i)
    {
      for (int j = 0; j < 27; ++j)
      {
        widWerte[i][j] = ereihe1[j] / (ereihe1[j] + ereihe1[i]);
        zwischenWert[i][j] = prop - widWerte[i][j];

        if (zwischenWert[i][j] < 0)  // Betrag berechnen
        {
          zwischenWert[i][j] *= (-1);
        }

        if (zwischenWert[i][j] < zwischenWert[r2i][r1i])
        {
          r2i = i;  // y-achse
          r1i = j;  // x-achse
        }
      }
    }
    r1 = ereihe1[r1i];
    r2 = ereihe1[r2i];
    qDebug() << "r1=" << r1 << " r2=" << r2 << endl;
    qDebug() << "r1i=" << r1i << " r2i=" << r2i << endl;
  }

  if (reihe == 2)
  {
    double widWerte[54][54];
    double zwischenWert[54][54];

    // Verhältnis suchen
    for (int i = 0; i < 54; ++i)
    {
      for (int j = 0; j < 54; ++j)
      {
        widWerte[i][j] = ereihe2[j] / (ereihe2[j] + ereihe2[i]);
        zwischenWert[i][j] = prop - widWerte[i][j];

        if (zwischenWert[i][j] < 0)  // Betrag berechnen
        {
          zwischenWert[i][j] *= (-1);
        }

        if (zwischenWert[i][j] < zwischenWert[r2i][r1i])
        {
          r2i = i;  // y-achse
          r1i = j;  // x-achse
        }
      }
    }
    r1 = ereihe2[r1i];
    r2 = ereihe2[r2i];
    qDebug() << "r1=" << r1 << " r2=" << r2 << endl;
    qDebug() << "r1i=" << r1i << " r2i=" << r2i << endl;
  }

  if (reihe == 3)
  {
    double widWerte[108][108];
    double zwischenWert[108][108];

    // Verhältnis suchen
    for (int i = 0; i < 108; ++i)
    {
      for (int j = 0; j < 108; ++j)
      {
        widWerte[i][j] = ereihe3[j] / (ereihe3[j] + ereihe3[i]);
        zwischenWert[i][j] = prop - widWerte[i][j];

        if (zwischenWert[i][j] < 0)  // Betrag berechnen
        {
          zwischenWert[i][j] *= (-1);
        }

        if (zwischenWert[i][j] < zwischenWert[r2i][r1i])
        {
          r2i = i;  // y-achse
          r1i = j;  // x-achse
        }
      }
    }
    r1 = ereihe3[r1i];
    r2 = ereihe3[r2i];
    qDebug() << "r1=" << r1 << " r2=" << r2 << endl;
    qDebug() << "r1i=" << r1i << " r2i=" << r2i << endl;
  }

  if (reihe == 4)
  {
    double widWerte[216][216];
    double zwischenWert[216][216];

    // Verhältnis suchen
    for (int i = 0; i < 216; ++i)
    {
      for (int j = 0; j < 216; ++j)
      {
        widWerte[i][j] = ereihe4[j] / (ereihe4[j] + ereihe4[i]);
        zwischenWert[i][j] = prop - widWerte[i][j];

        if (zwischenWert[i][j] < 0)  // Betrag berechnen
        {
          zwischenWert[i][j] *= (-1);
        }

        if (zwischenWert[i][j] < zwischenWert[r2i][r1i])
        {
          r2i = i;  // y-achse
          r1i = j;  // x-achse
        }
      }
    }
    r1 = ereihe4[r1i];
    r2 = ereihe4[r2i];
    qDebug() << "r1=" << r1 << " r2=" << r2 << endl;
    qDebug() << "r1i=" << r1i << " r2i=" << r2i << endl;
  }
  if (prop == 0.5)
  {
    return 1;
  }
  else
  {
    return 0;
  }
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
