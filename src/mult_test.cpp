#include "gtest/gtest.h"
#include "mult.hpp"
#include "positive_op_mock.hpp"
#include "negative_op_mock.hpp"
#include "zero_op_mock.hpp"

TEST(MultEvaluate, MultPositiveTest) {
    Mult obj(new PositiveOpMock(), new PositiveOpMock());
    EXPECT_NEAR(obj.evaluate(), 47.61, 0.000001);
}

TEST(MultEvaluate, MultNegativeTest) {
    Mult obj(new NegativeOpMock(), new NegativeOpMock());
    EXPECT_NEAR(obj.evaluate(), 156.25, 0.000001);
}

TEST(MultEvaluate, MultZeroTest) {
    Mult obj(new ZeroOpMock(), new ZeroOpMock());
    EXPECT_EQ(obj.evaluate(), 0.0);
}

TEST(MultStringify, MultPositiveTest) {
    Mult obj(new PositiveOpMock(), new PositiveOpMock());
    EXPECT_EQ(obj.stringify(), "(6.9*6.9)");
}

TEST(MultStringify, MultNegativeTest) {
    Mult obj(new NegativeOpMock(), new NegativeOpMock());
    EXPECT_EQ(obj.stringify(), "(-12.5*-12.5)");
}

TEST(MultStringify, MultZeroTest) {
    Mult obj(new ZeroOpMock(), new ZeroOpMock());
    EXPECT_EQ(obj.stringify(), "(0*0)");
}
