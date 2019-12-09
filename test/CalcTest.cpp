#include <gtest/gtest.h>
#include "../MainWindow.h"

TEST(CalcTest, testcalculation)
{
  // Fran ergänzt
  ASSERT_EQ(MainWindow::calulate(2, 1, E3), 1);
  ASSERT_EQ(MainWindow::calulate(2, 1, E6), 1);
  ASSERT_EQ(MainWindow::calulate(2, 1, E12), 1);
  ASSERT_EQ(MainWindow::calulate(2, 1, E24), 1);

  // Normal
  ASSERT_EQ(MainWindow::calulate(13, 3, E3), 0);
  ASSERT_EQ(MainWindow::calulate(13, 3, E6), 0);
  ASSERT_EQ(MainWindow::calulate(13, 3, E12), 0);
  ASSERT_EQ(MainWindow::calulate(13, 3, E24), 0);
}
