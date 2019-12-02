#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#define E3 1
#define E6 2
#define E12 3
#define E24 4

extern double r1;
extern double r2;
namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

 public:
  explicit MainWindow(QWidget* parent = nullptr);
  ~MainWindow();
  void startCalculation();  // Berechnung starten
  int readU1();
  int readU2();
  int readReihe();
  void outputValues(double r1, double r2, int fail);  // Ausgabe
  bool calculate(int u1, int u2, int reihe);          // Widerstandsberechnung

 private:
  Ui::MainWindow* ui;
};

#endif  // MAINWINDOW_H
