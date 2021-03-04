#include "gtest/gtest.h"
#include "pow.hpp"
#include "op.hpp"


TEST(PowTest, PositiveEvaluate) {
    Pow obj(new Op(2), new Op(5));
    EXPECT_EQ(obj.evaluate(), 32);
}

TEST(PowTest, NegativeEvaluate) {
    Pow obj(new Op(-3), new Op(3));
    EXPECT_EQ(obj.evaluate(), -27);
}

TEST(PowTest, ZeroExpEvaluate) {
    Pow obj(new Op(23), new Op(0));
    EXPECT_EQ(obj.evaluate(), 1);
}

TEST(PowTest, ZeroBaseEvaluate) {
    Pow obj(new Op(0), new Op(52));
    EXPECT_EQ(obj.evaluate(), 0);
}

TEST(PowTest, FractionalEvaluate) {
    Pow obj(new Op(4), new Op(1.5));
    EXPECT_EQ(obj.evaluate(), 8);
}

TEST(PowTestStr, ZeroBaseStr) {
    Pow obj(new Op(0), new Op(52));
    EXPECT_EQ(obj.stringify(), "(0**52)");
}

TEST(PowTestStr, FractionalStr) {
    Pow obj(new Op(4), new Op(1.5));
    EXPECT_EQ(obj.stringify(), "(4**1.5)");
}
