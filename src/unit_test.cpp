#include "gtest/gtest.h"

#include "iteratorTest.hpp"
#include "latexTest.hpp"
#include "mathTest.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
