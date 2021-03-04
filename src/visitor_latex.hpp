#ifndef VISITOR_LATEX_HPP
#define VISITOR_LATEX_HPP

#include "visitor.hpp"
#include "iterator.hpp"
#include "base.hpp"
#include <string>
#include <sstream>
#include <iostream>

using std::string;
using std::cout;
using std::stringstream; 

class VisitorLatex : public Visitor {
    private:
        string str;

    public:
        VisitorLatex(): str("") {}
        ~VisitorLatex() {}
        virtual void visit_op(Op* node) {
            stringstream strm;
            strm<<node->value;
            str += "{" + strm.str() + "}";
        }
        virtual void visit_rand(Rand* node) {
            stringstream strm;
            strm<<node->value;
            str += "{" + strm.str() + "}";
        }
        virtual void visit_add_begin(Add* node) {
            str += "(";
        }
        virtual void visit_add_middle(Add* node) {
            str += "+";
        }
        virtual void visit_add_end(Add* node) {
            str += ")";
        }
        virtual void visit_sub_begin(Sub* node) {
            str += "(";
        }
        virtual void visit_sub_middle(Sub* node) {
            str += "-";
        }
        virtual void visit_sub_end(Sub* node) {
            str += ")";
        }
        virtual void visit_mult_begin(Mult* node) {
            str += "(";
        }
        virtual void visit_mult_middle(Mult* node) {
            str += "\\cdot";
        }
        virtual void visit_mult_end(Mult* node) {
            str += ")";
        }
        virtual void visit_div_begin(Div* node) {
            str += "\\frac";
        }
        virtual void visit_div_middle(Div* node) {

        }
        virtual void visit_div_end(Div* node) {
            
        }
        virtual void visit_pow_begin(Pow* node) {
            str += "(";
        }
        virtual void visit_pow_middle(Pow* node) {
            str += "^";
        }
        virtual void visit_pow_end(Pow* node) {
            str += ")";
        }
        string printLatex(Base *base) {
            str = "${";

            //Create iterator
            Iterator *itr = new Iterator(base);

            //Iterate expression tree
            while(!itr->is_done()) {
                itr->current_node()->accept(this, itr->current_index());
                itr->next();
            }

            //Deallocate iterator
            delete itr;

            //Finish latex string and return
            str += "}$";
            return str;
        }
};

#endif
