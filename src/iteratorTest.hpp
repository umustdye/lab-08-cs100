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
TEST(iteratorTest, constructor)
{
    Base* three = new Op(3);
    Base* seven = new Op(7);
    Base* four = new Op(4);
    Base* two = new Op(2);
    Base* add = new Add(three, seven);
    Base* add2 = new Add(add, four);
    //Base* mult = new Mult(seven, four);
    //Base* add = new Add(mult, two);
    //std::cout<<add2->number_of_children()<<std::endl;
    Iterator* it = new Iterator(add2);
    std::cout<<it->current_node()->stringify()<<std::endl;
    it->next();
    std::cout<<it->current_node()->stringify()<<std::endl;
    it->next();
    std::cout<<it->current_node()->stringify()<<std::endl;
    it->next();
    std::cout<<it->current_node()->stringify()<<std::endl;
    it->next();
std::cout<<it->current_node()->stringify()<<std::endl;
    it->next();
    std::cout<<"num child: "<<it->current_node()->number_of_children()<<std::endl;
std::cout<<it->current_node()->stringify()<<std::endl;
    it->next();
std::cout<<it->current_node()->stringify()<<std::endl;
    it->next();

std::cout<<it->current_node()->stringify()<<std::endl;
    it->next();

 std::cout<<it->current_node()->stringify()<<std::endl;
    it->next();

    //Base* currentNode = it->current_node();
    //std::cout<<currentNode->stringify()<<std::endl;
//    std::cout<<it->current_index()<<std::endl;
    //std::cout<<it->current_node.stringify()<<std::endl;
}

#endif //__ITERATOR_TEST_HPP__
