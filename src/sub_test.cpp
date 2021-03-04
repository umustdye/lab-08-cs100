#ifndef __SUB_TEST_HPP__
#define __SUB_TEST_HPP__

#include "gtest/gtest.h"

#include "sub.hpp"
#include "zero_op_mock.hpp"
#include "positive_op_mock.hpp"
#include "negative_op_mock.hpp"

TEST(SubTest, SubZero)
{
	Sub* test = new Sub(new ZeroOpMock(), new ZeroOpMock());
	EXPECT_EQ(test->evaluate(), 0);
}

TEST(SubTest, SubPos)
{
	Sub* test = new Sub(new PositiveOpMock(), new PositiveOpMock());
	EXPECT_NEAR(test->evaluate(),0, .00000001);
}

TEST(SubTest, SubNeg)
{
	Sub* test = new Sub(new NegativeOpMock(), new NegativeOpMock());
	EXPECT_NEAR(test->evaluate(), 0, .00000001);
}

TEST(SubTest, SubZeroNeg)
{
	Sub* test = new Sub(new ZeroOpMock(), new NegativeOpMock());
	EXPECT_NEAR(test->evaluate(), 12.5, .000000001);
}

TEST(SubTest, SubNegZero)
{
	Sub* test = new Sub(new NegativeOpMock(), new ZeroOpMock());
	EXPECT_NEAR(test->evaluate(), -12.5, .0000000001);
}

TEST(SubTest, SubZeroPos)
{
	Sub* test = new Sub(new ZeroOpMock(), new PositiveOpMock());
	EXPECT_NEAR(test->evaluate(), -6.9, .00000001);
}

TEST(SubTest, SubPosZero)
{
	Sub* test = new Sub(new PositiveOpMock(), new ZeroOpMock());
	EXPECT_NEAR(test->evaluate(), 6.9, .0000001);
}

TEST(SubTest, SubPosNeg)
{
	Sub* test = new Sub(new PositiveOpMock(), new NegativeOpMock());
	EXPECT_NEAR(test->evaluate(), 19.4, .0000001);
}

TEST(SubTest, SubNegPos)
{
	Sub* test = new Sub(new NegativeOpMock(), new PositiveOpMock());
	EXPECT_NEAR(test->evaluate(), -19.4, .0000001);
}

TEST(SubTestStr, SubZeroPos)
{
	Sub* test = new Sub(new ZeroOpMock(), new PositiveOpMock());
	EXPECT_EQ(test->stringify(), "(0-6.9)");
}

TEST(SubTestStr, SubPosNeg)
{
	Sub* test = new Sub(new PositiveOpMock(), new NegativeOpMock());
	EXPECT_EQ(test->stringify(), "(6.9--12.5)");
}

#endif //__SUB_TEST_HPP__
