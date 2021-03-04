#ifndef __ITERATOR_TEST_HPP__
#define __ITERATOR_TEST_HPP__
#include "gtest/gtest.h"
#include "iterator.hpp"
#include "op.hpp"
#include "div.hpp"
#include "mult.hpp"
#include "pow.hpp"
#include "sub.hpp"
#include "base.hpp"
#include "add.hpp"
#include <iostream>
TEST(iteratorTest, traversals)
{
    Base* three = new Op(3);
    Base* seven = new Op(7);
    Base* four = new Op(4);
    Base* two = new Op(2);
    Base* add = new Add(three, seven);
    Base* mult = new Mult(add, four);
    Iterator* it = new Iterator(mult);
    int traversals = 0;
    while(!it->is_done())
    {
        //std::cout<<it->current_node()->stringify()<<std::endl;
        it->next();
        traversals++;
    }
    EXPECT_EQ(traversals, 9);
}

TEST(iteratorTest, op)
{
    Base* four = new Op(4);
    Iterator* it = new Iterator(four);
    EXPECT_EQ(it->current_node()->stringify(), "4");
    EXPECT_EQ(it->current_index(), 0);
    EXPECT_EQ(it->current_node()->number_of_children(), 0);
}


TEST(iteratorTest, correctValues)
{
    Base* three = new Op(3);
    Base* seven = new Op(7);
    Base* four = new Op(4);
    Base* two = new Op(2);
    Base* add = new Add(three, seven);
    Base* mult = new Mult(add, four);
    Iterator* it = new Iterator(mult);

    EXPECT_EQ(it->current_node()->stringify(), mult->stringify());
    it->next();
    
    EXPECT_EQ(it->current_node()->stringify(), add->stringify());
    it->next();

    EXPECT_EQ(it->current_node()->stringify(), three->stringify());
    it->next();

    EXPECT_EQ(it->current_node()->stringify(), add->stringify());
    it->next();

    EXPECT_EQ(it->current_node()->stringify(), seven->stringify());
    it->next();

    EXPECT_EQ(it->current_node()->stringify(), add->stringify());
    it->next();

    EXPECT_EQ(it->current_node()->stringify(), mult->stringify());
    it->next();

    EXPECT_EQ(it->current_node()->stringify(), four->stringify());
    it->next();


    EXPECT_EQ(it->current_node()->stringify(), mult->stringify());
    it->next();

}


TEST(iteratorTest, index)
{
    Base* three = new Op(3);
    Base* seven = new Op(7);
    Base* four = new Op(4);
    Base* two = new Op(2);
    Base* add = new Add(three, seven);
    Base* mult = new Mult(add, four);
    Iterator* it = new Iterator(mult);

    EXPECT_EQ(it->current_index(), 0);
    it->next();
    
    EXPECT_EQ(it->current_index(), 0);
    it->next();

    EXPECT_EQ(it->current_index(), 0);
    it->next();

    EXPECT_EQ(it->current_index(), 1);
    it->next();

    EXPECT_EQ(it->current_index(), 0);
    it->next();

    EXPECT_EQ(it->current_index(), 2);
    it->next();

    EXPECT_EQ(it->current_index(), 1);
    it->next();

    EXPECT_EQ(it->current_index(), 0);
    it->next();


    EXPECT_EQ(it->current_index(), 2);
    it->next();





}



#endif //__ITERATOR_TEST_HPP__
