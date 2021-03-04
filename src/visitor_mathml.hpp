#ifndef VISITOR_MATHML_HPP
#define VISITOR_MATHML_HPP

#include "visitor.hpp"
#include "iterator.hpp"
#include "base.hpp"
#include <string>
#include <sstream>
#include <iostream>

using std::string;
using std::cout;
using std::stringstream; 

class VisitorMathML : public Visitor {
    private:
        string str;
        int depth = 0;
        void addSpace() {
            str += string(2 * depth, ' ');
        }

    public:
        VisitorMathML(): str("") {}
        ~VisitorMathML() {}
        virtual void visit_op(Op* node) {
            stringstream strm;
            strm<<node->value;
            addSpace();
            str += "<cn>" + strm.str() + "</cn>\n";
        }
        virtual void visit_rand(Rand* node) {
            stringstream strm;
            strm<<node->value;
            addSpace();
            str += "<cn>" + strm.str() + "</cn>\n";
        }
        virtual void visit_add_begin(Add* node) {
            addSpace();
            str += "<apply>\n";
            ++depth;
            addSpace();
            str += "<plus/>\n";
        }
        virtual void visit_add_middle(Add* node) {
        }
        virtual void visit_add_end(Add* node) {
            --depth;
            addSpace();
            str += "</apply>\n";
        }
        virtual void visit_sub_begin(Sub* node) {
            addSpace();
            str += "<apply>\n";
            ++depth;
            addSpace();
            str += "<minus/>\n";
        }
        virtual void visit_sub_middle(Sub* node) {
        }
        virtual void visit_sub_end(Sub* node) {
            --depth;
            addSpace();
            str += "</apply>\n";
        }
        virtual void visit_mult_begin(Mult* node) {
            addSpace();
            str += "<apply>\n";
            ++depth;
            addSpace();
            str += "<times/>\n";
        }
        virtual void visit_mult_middle(Mult* node) {
        }
        virtual void visit_mult_end(Mult* node) {
            --depth;
            addSpace();
            str += "</apply>\n";
        }
        virtual void visit_div_begin(Div* node) {
            addSpace();
            str += "<apply>\n";
            ++depth;
            addSpace();
            str += "<divide/>\n";
        }
        virtual void visit_div_middle(Div* node) {

        }
        virtual void visit_div_end(Div* node) {
            --depth;
            addSpace();
            str += "</apply>\n";
        }
        virtual void visit_pow_begin(Pow* node) {
            addSpace();
            str += "<apply>\n";
            ++depth;
            addSpace();
            str += "<power/>\n";
        }
        virtual void visit_pow_middle(Pow* node) {
        }
        virtual void visit_pow_end(Pow* node) {
            --depth;
            addSpace();
            str += "</apply>\n";
        }
        string printMathML(Base *base) {
            str = "<math>\n";
            depth = 1;

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
            depth = 0;
            str += "</math>";
            return str;
        }
};

#endif
