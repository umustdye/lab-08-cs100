#ifndef POW_HPP
#define POW_HPP

#include "base.hpp"
#include <cmath>
#include "visitor.hpp"

class Pow : public Base {
    public:
        Base *left;
        Base *right;

        Pow(Base *l, Base *r) : Base(), left(l), right(r) {}
        ~Pow() {
            delete left;
            delete right;
        }

        virtual double evaluate() {
            return std::pow(left->evaluate(), right->evaluate());
        }
        virtual std::string stringify() {
            return "(" + left->stringify() + "**" + right->stringify() + ")";
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
                case 0: visitor.visit_pow_begin(this); break;
                case 1: visitor.visit_pow_middle(this); break;
                case 2: visitor.visit_pow_end(this); break;
            }
        }
};

#endif
