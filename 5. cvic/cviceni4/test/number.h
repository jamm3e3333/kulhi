#ifndef _NUMBERNUM_
#define _NUMBERNUM_

#include <iostream>

using namespace std;

class number{
	public:
		number();
		~number();

		virtual void tisk() const;
		virtual void nacti();

		double operator+(const number& arg) const;
		double operator+(const double& arg) const;

		virtual double hodnota() const =0;
};

#endif