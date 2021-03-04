#ifndef __RAND_HPP__
#define __RAND_HPP__

#include "base.hpp"

#include <sstream>
#include <ctime>
#include <cstdlib>

using namespace std;

class Rand : public Base
{
	public:
		double value;
		
		Rand()
		: Base()
		{
			//seed the random number generator
			srand(static_cast<unsigned int>(time(0)));
			this->value = rand() % 100;
		}
		virtual ~Rand(){}
		virtual double evaluate()
		override
		{
			return value;
		}

		virtual string stringify()
		override
		{
			stringstream strm;
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

#endif //__RAND_HPP__
