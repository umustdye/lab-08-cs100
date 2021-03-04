#ifndef POSITIVE_OP_MOCK_HPP
#define POSITIVE_OP_MOCK_HPP

#include "base.hpp"

class PositiveOpMock : public Base {
    public:
        PositiveOpMock() {}

        virtual double evaluate() { return 6.9; }
        virtual std::string stringify() { return "6.9"; }
};

#endif
