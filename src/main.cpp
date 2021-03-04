#include <iostream>
#include "base.hpp"
#include "op.hpp"
#include "rand.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "pow.hpp"
#include "visitor_latex.hpp"

using std::cout;
using std::endl;

int main() {
    VisitorLatex *visit = new VisitorLatex;
    Base *base = new Pow(new Op(5), new Op(2));

    cout<<visit->printLatex(base)<<endl;

    delete visit;
    delete base;

    return 0;
}
