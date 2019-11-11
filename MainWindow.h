#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
  int readU1();
  int readU2();
  void startCalculation();

 private:
  Ui::MainWindow* ui;
};

#endif  // MAINWINDOW_H
