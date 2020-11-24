#ifndef _NUMBER_
#define _NUMBER_
#include <iostream>
using namespace std;

class Number
{
public:
	Number();
	~Number();
	virtual void nacti();
	virtual void tisk() const;
	//scitani dvou objektu
	double operator+(const Number& arg) const;
	//scitani objektu + double 
	double operator+(const double& arg) const;
	//prevod hodnoty objektu na double - prazdna metoda 
	virtual double Hodnota() const = 0;
};
#endif