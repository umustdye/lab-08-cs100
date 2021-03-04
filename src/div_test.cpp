#ifndef __DIV_TEST_HPP__
#define __DIV_TEST_HPP__

#include "gtest/gtest.h"

#include "div.hpp"
#include "zero_op_mock.hpp"
#include "positive_op_mock.hpp"
#include "negative_op_mock.hpp"

TEST(DivTest, DivZero)
{
	Div* test = new Div(new ZeroOpMock(), new ZeroOpMock());
	EXPECT_EQ(test->evaluate(), 0);
}

TEST(DivTest, DivPos)
{
	Div* test = new Div(new PositiveOpMock(), new PositiveOpMock());
	EXPECT_NEAR(test->evaluate(),1, .00000001);
}

TEST(DivTest, DivNeg)
{
	Div* test = new Div(new NegativeOpMock(), new NegativeOpMock());
	EXPECT_NEAR(test->evaluate(), 1, .00000001);
}

TEST(DivTest, DivZeroStr)
{
	Div* test = new Div(new ZeroOpMock(), new ZeroOpMock());
	EXPECT_EQ(test->stringify(), "Invalid Operation");
}

TEST(DivTest, DivPosStr)
{
	Div* test = new Div(new PositiveOpMock(), new PositiveOpMock());
	EXPECT_EQ(test->stringify(), "(6.9/6.9)");
}

TEST(DivTest, DivNegStr)
{
	Div* test = new Div(new NegativeOpMock(), new NegativeOpMock());
	EXPECT_EQ(test->stringify(), "(-12.5/-12.5)");
}


#endif //__DIV_TEST_HPP__
