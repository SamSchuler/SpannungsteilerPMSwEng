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
///
/// \brief The MainWindow class
///
class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  ///
  /// \brief MainWindow Konstruktor
  /// \param parent
  ///
  explicit MainWindow(QWidget* parent = nullptr);

  ///
  /// \brief MainWindow Destruktor
  ///
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

  ///
  /// \brief outputValues für Widerstandswerte
  /// \param r1 für Widerstand R1
  /// \param r2 für Widerstand R2
  /// \param fail für Fehler
  ///
  void outputValues(double r1, double r2, int fail);  // Ausgabe

  ///
  /// \brief Berechnung der optimalen Werte von R1 und R2.
  /// Alle Verhältnisse aus R1 und R2 werden in einem generierten Array
  /// abgespeichert.
  /// Aus diesem Array wird das best mögliche Verhältnis ausgegeben.
  ///
  /// \param u1: Übergabe von Spannung u1
  /// \param u2: Übergabe von Spannung u2
  /// \param reihe: Übergabe der ausgewählten E-Reihe
  /// \return 1 wenn Widerstandsverhältnis 1 zu 1 ist. Das heisst, jeder Wert
  /// ist möglich. Sonst 0.

  int calculate(int u1, int u2, int reihe);

 private:
  Ui::MainWindow* ui;
};

#endif  // MAINWINDOW_H
