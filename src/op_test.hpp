#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"

TEST(OpTest, OpEvaluatePositive) {
    Op* test = new Op(8);
    EXPECT_EQ(test->evaluate(), 8);
}

TEST(OpTest, OpEvaluateZero) {
    Op* test = new Op(0.00000);
    EXPECT_EQ(test->evaluate(), 0);
}

TEST(OpTest, OpEvaluateNegative) {
    Op* test = new Op(-56.12344321);
    EXPECT_NEAR(test->evaluate(), -56.12344321, 1e-9);
}

TEST(OpTest, OpStringifyPositive) {
    Op test(123.456);
    EXPECT_EQ(test.stringify(), "123.456");
}

TEST(OpTest, OpStringifyZero) {
    Op test(0);
    EXPECT_EQ(test.stringify(), "0");
}

TEST(OpTest, OpStringifyNegative) {
    Op test(-4);
    EXPECT_EQ(test.stringify(), "-4");
}

#endif //__OP_TEST_HPP__
