#ifndef ZERO_OP_MOCK_HPP
#define ZERO_OP_MOCK_HPP

#include "base.hpp"

class ZeroOpMock : public Base {
    public:
        ZeroOpMock() {};

        virtual double evaluate() { return 0; }
        virtual std::string stringify() { return "0"; }
};

#endif
