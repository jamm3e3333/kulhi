#ifndef _DOUBLE_
#define _DOUBLE_
#include <iostream>
#include "Number.h"

using namespace std;

class Double :
	public Number{

public:
	Double();
	~Double();

private:
	double m_dblHodnota;

public:
	void nacti();
	void tisk() const;
	double Hodnota() const;
};
#endif