#ifndef __LATEX_TEST_HPP__
#define __LATEX_TEST_HPP__

#include "gtest/gtest.h"

#include "base.hpp"
#include "op.hpp"
#include "rand.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "pow.hpp"
#include "visitor_latex.hpp"

TEST(LatexTest, op)
{
    VisitorLatex *visit = new VisitorLatex;
    Base* base = new Op(4);

    EXPECT_EQ(visit->printLatex(base), "${4}$");

    delete visit;
    delete base;
}

TEST(LatexTest, labEx1)
{
    VisitorLatex *visit = new VisitorLatex;
    //1+(5-0)
    Base* sub = new Sub(new Op(5), new Op(0));
    Base* add = new Add(new Op(1), sub);
    EXPECT_EQ(visit->printLatex(add), "${({1}+{({5}-{0})})}$");

    delete visit;
    delete add;
}

TEST(LatexTest, labEx2)
{
    VisitorLatex *visit = new VisitorLatex;
    //5^2
    Base* pow = new Pow(new Op(5), new Op(2));
    EXPECT_EQ(visit->printLatex(pow), "${({5}^{2})}$");
    delete visit;
    delete pow;
}

TEST(LatexTest, labEx3)
{
    VisitorLatex *visit = new VisitorLatex;
    //2*5
    Base* mult = new Mult(new Op(2), new Op(5));
    EXPECT_EQ(visit->printLatex(mult), "${({2}\\cdot{5})}$");
    delete visit;
    delete mult;
}

TEST(LatexTest, labEx4)
{
    VisitorLatex *visit = new VisitorLatex;
    //2/3
    Base* div = new Div(new Op(2), new Op(3));
    EXPECT_EQ(visit->printLatex(div), "${\\frac{2}{3}}$");
    delete visit;
    delete div;
}

TEST(LatexTest, labEx5)
{
    VisitorLatex *visit = new VisitorLatex;
    //(2*5)/(5^2)
    Base* pow = new Pow(new Op(5), new Op(2));
    Base* mult = new Mult(new Op(2), new Op(5));
    Base* div = new Div(mult, pow);
    EXPECT_EQ(visit->printLatex(div), "${\\frac{({2}\\cdot{5})}{({5}^{2})}}$");

    delete visit;
    delete div;
}


#endif //__LATEX_TEST_HPP__
