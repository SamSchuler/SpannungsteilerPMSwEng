#include <gtest/gtest.h>
#include "MainWindow.h"

TEST(CalcTest, testcalculation)
{
  MainWindow z;

  // testcalculation erfolgreich, bei dem unenedlich viele Werte möglich sind.
  ASSERT_EQ(z.calculate(2, 1, E3), 1);
  ASSERT_EQ(z.calculate(2, 1, E6), 1);
  ASSERT_EQ(z.calculate(2, 1, E12), 1);
  ASSERT_EQ(z.calculate(2, 1, E24), 1);

  // testcalculation erfolgreich, bei dem nur ein Wert möglich ist.
  ASSERT_EQ(z.calculate(13, 3, E3), 0);
  ASSERT_EQ(z.calculate(13, 3, E6), 0);
  ASSERT_EQ(z.calculate(13, 3, E12), 0);
  ASSERT_EQ(z.calculate(13, 3, E24), 0);
}
