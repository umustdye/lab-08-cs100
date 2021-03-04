#ifndef __SUB_HPP__
#define __SUB_HPP__

#include "base.hpp"
#include "visitor.hpp"

using namespace std;

class Sub: public Base
{
    public:
        Base* left;
        Base* right;
        Sub(Base* left, Base* right)
            : Base()
        {
            this->left = left;
            this->right = right;
        }

        ~Sub()
        {
            delete left;
            delete right;			
        }


        virtual double evaluate()
        {
            return left->evaluate() - right->evaluate();
        }

        virtual string stringify()
        {
            return "(" + left->stringify() + "-" + right->stringify() + ")";
        }
        virtual int number_of_children() override {
            int numChild = 0;
            if(left) ++numChild;
            if(right) ++numChild;
            return numChild;
        }
        virtual Base* get_child(int i) override {
            if(i) return right;
            else return left;
        }
        void accept(Visitor *visitor, int index) {
            switch(index) {
                case 0: visitor->visit_sub_begin(this); break;
                case 1: visitor->visit_sub_middle(this); break;
                case 2: visitor->visit_sub_end(this); break;
            }
        }
};

#endif //__SUBOPMOCK_HPP__

