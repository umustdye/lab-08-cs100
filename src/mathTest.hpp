#ifndef __MATH_TEST_HPP__
#define __MATH_TEST_HPP__

#include "gtest/gtest.h"

#include "base.hpp"
#include "op.hpp"
#include "rand.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "pow.hpp"
#include "visitor_mathml.hpp"

TEST(MathTest, op)
{
    VisitorMathML *visit = new VisitorMathML;
    Base* base = new Op(4);

    EXPECT_EQ(visit->printMathML(base), "<math>\n  <cn>4</cn>\n</math>");

    delete visit;
    delete base;
}

TEST(MathTest, labEx1)
{
    VisitorMathML *visit = new VisitorMathML;
    //1+(5-0)
    Base* sub = new Sub(new Op(5), new Op(0));
    Base* add = new Add(new Op(1), sub);
    EXPECT_EQ(visit->printMathML(add), "<math>\n  <apply>\n    <plus/>\n    <cn>1</cn>\n    <apply>\n      <minus/>\n      <cn>5</cn>\n      <cn>0</cn>\n    </apply>\n  </apply>\n</math>");

    delete visit;
    delete add;
}

TEST(MathTest, labEx2)
{
    VisitorMathML *visit = new VisitorMathML;
    //5^2
    Base* pow = new Pow(new Op(5), new Op(2));
    EXPECT_EQ(visit->printMathML(pow), "<math>\n  <apply>\n    <power/>\n    <cn>5</cn>\n    <cn>2</cn>\n  </apply>\n</math>");
    delete visit;
    delete pow;
}

TEST(MathTest, labEx3)
{
    VisitorMathML *visit = new VisitorMathML;
    //2*5
    Base* mult = new Mult(new Op(2), new Op(5));
    EXPECT_EQ(visit->printMathML(mult), "<math>\n  <apply>\n    <times/>\n    <cn>2</cn>\n    <cn>5</cn>\n  </apply>\n</math>");
    delete visit;
    delete mult;
}

TEST(MathTest, labEx4)
{
    VisitorMathML *visit = new VisitorMathML;
    //2/3
    Base* div = new Div(new Op(2), new Op(3));
    EXPECT_EQ(visit->printMathML(div), "<math>\n  <apply>\n    <divide/>\n    <cn>2</cn>\n    <cn>3</cn>\n  </apply>\n</math>");
    delete visit;
    delete div;
}

TEST(MathTest, labEx5)
{
    VisitorMathML *visit = new VisitorMathML;
    //(2*5)/(5^2)
    Base* pow = new Pow(new Op(5), new Op(2));
    Base* mult = new Mult(new Op(2), new Op(5));
    Base* div = new Div(mult, pow);
    EXPECT_EQ(visit->printMathML(div), "<math>\n  <apply>\n    <divide/>\n    <apply>\n      <times/>\n      <cn>2</cn>\n      <cn>5</cn>\n    </apply>\n    <apply>\n      <power/>\n      <cn>5</cn>\n      <cn>2</cn>\n    </apply>\n  </apply>\n</math>");

    delete visit;
    delete div;
}


#endif //__MATH_TEST_HPP__
