#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

enum eReihe
{
  E3,
  E6,
  E12,
  E24
};

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

  ///
  /// \brief Wird aufgerufen wenn der berechnen Button angeklickt wird.
  ///     Damit wird der ganze Ablauf für eine Widerstandsberchnung gestartet.
  ///
  void startCalculation();  // Berechnung starten
  ///
  /// \brief Liest die Spannung U1 vom Eingabefeld.
  /// \return Gibt die Spannung in uV zurück.
  ///
  int readU1();
  ///
  /// \brief Liest die Spannung U2 vom Eingabefeld.
  /// \return Gibt die Spannung in uV zurück.
  ///
  int readU2();
  ///
  /// \brief Schaut welche E-Reihe im GUI ausgewählt wurde.
  /// \return Gibt die ausgewählte E-Reihe zurück. (enum: E3, E6, E12, E24)
  ///
  int readReihe();
  void outputValues(double r1, double r2, int fail);  // Ausgabe
  ///
  /// \brief calculate
  /// \param u1
  /// \param u2
  /// \param reihe
  /// \return
  ///
  int calculate(
      int u1, int u2,
      int reihe);  ///\brief Berechnung der optimalen Werte von R1 und R2.
  /// Alle Verhältnisse aus R1 und R2 werden in einem generierten Array
  /// abgespeichert.
  /// Aus diesem Array wird das best mögliche Verhältnis ausgegeben.

 private:
  Ui::MainWindow* ui;
};

#endif  // MAINWINDOW_H
