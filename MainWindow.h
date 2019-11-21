#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#define E3 1
#define E6 2
#define E12 3
#define E24 4

int r1 = 0;
int r2 = 0;

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget* parent = nullptr);
  ~MainWindow();
  void startCalculation();
  int readU1();
  int readU2();
  int readReihe();
  void outputValues();
  double calculate(int u1, int u2, int reihe);

 private:
  Ui::MainWindow* ui;
};

#endif  // MAINWINDOW_H
