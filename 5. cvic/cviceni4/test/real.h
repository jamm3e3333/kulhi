#ifndef _REALNUM_
#define _REALNUM_
#include <iostream>
#include "number.h"

using namespace std;

class real_no: public number{

public:
	real_no();
	~real_no();
private:
	double m_dblHodnota;
public:
	void tisk() const;
	void nacti();

	double hodnota() const;

};

#endif