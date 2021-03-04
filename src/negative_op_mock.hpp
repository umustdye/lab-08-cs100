#ifndef NEGATIVE_OP_MOCK_HPP
#define NEGATIVE_OP_MOCK_HPP

#include "base.hpp"

class NegativeOpMock : public Base {
    public:
        NegativeOpMock() {}

        virtual double evaluate() { return -12.5; }
        virtual std::string stringify() { return "-12.5"; }
};

#endif
