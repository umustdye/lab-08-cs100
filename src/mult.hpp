#ifndef MULT_HPP
#define MULT_HPP

#include "base.hpp"
#include "visitor.hpp"

class Mult : public Base {
    public:
        Base *left;
        Base *right;

        Mult(Base *l, Base *r) : Base(), left(l), right(r) {}
        virtual ~Mult() {
            delete left;
            delete right;
        }

        virtual double evaluate() override {
            return left->evaluate() * right->evaluate();
        }
        virtual std::string stringify() override {
            return "(" + left->stringify() + "*" + right->stringify() + ")";
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
                case 0: visitor->visit_mult_begin(this); break;
                case 1: visitor->visit_mult_middle(this); break;
                case 2: visitor->visit_mult_end(this); break;
            }
        }
};

#endif
