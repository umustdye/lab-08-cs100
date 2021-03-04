#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"
#include <sstream>//Since std::to_string doesn't allow precision other than 6 digits for doubles

class Op : public Base {
    public:
        double value;
        Op(double value) : Base(), value(value) { }
        virtual ~Op() {}
        virtual double evaluate() override { return value; }
        virtual std::string stringify() override {
            std::stringstream strm;
            strm<<value;
            return strm.str();
        }
        virtual int number_of_children() override {
            return 0;
        }
        virtual Base* get_child(int i) override {
            return nullptr;
        }
};

#endif //__OP_HPP__
