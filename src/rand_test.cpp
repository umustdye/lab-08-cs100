#ifndef __RAND_TEST_HPP__
#define __RAND_TEST_HPP__

#include "gtest/gtest.h"

#include "rand.hpp"

TEST(RandTestEval, RandLessThan)
{
	Rand* test = new Rand();
	EXPECT_LE(test->evaluate(), 100);
}

TEST(RandTestEval, RandGreaterThan)
{
	Rand* test = new Rand();
	EXPECT_GE(test->evaluate(), 1);
}

TEST(RandTestStr, RandNoneEmptyStr)
{
	Rand* test = new Rand();
	EXPECT_NE(test->stringify(), "");
}

TEST(RandTestStr, RandSpaceStr)
{
	Rand* test = new Rand();
	EXPECT_NE(test->stringify(), " ");
}

#endif //__RAND_TEST_HPP__
