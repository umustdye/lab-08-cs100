#include "gtest/gtest.h"
#include "add.hpp"
#include "positive_op_mock.hpp"
#include "negative_op_mock.hpp"
#include "zero_op_mock.hpp"

TEST(AddEvaluate, AddPositiveTest) {
    Add add(new PositiveOpMock(), new PositiveOpMock());
    EXPECT_NEAR(add.evaluate(), 13.8, 0.000001);
}

TEST(AddEvaluate, AddNegativeTest) {
    Add add(new NegativeOpMock(), new NegativeOpMock());
    EXPECT_NEAR(add.evaluate(), -25.0, 0.000001);
}

TEST(AddEvaluate, AddZeroTest) {
    Add add(new ZeroOpMock(), new ZeroOpMock());
    EXPECT_EQ(add.evaluate(), 0.0);
}

TEST(AddStringify, AddPositiveTest) {
    Add add(new PositiveOpMock(), new PositiveOpMock());
    EXPECT_EQ(add.stringify(), "(6.9+6.9)");
}

TEST(AddStringify, AddNegativeTest) {
    Add add(new NegativeOpMock(), new NegativeOpMock());
    EXPECT_EQ(add.stringify(), "(-12.5+-12.5)");
}

TEST(AddStringify, AddZeroTest) {
    Add add(new ZeroOpMock(), new ZeroOpMock());
    EXPECT_EQ(add.stringify(), "(0+0)");
}
