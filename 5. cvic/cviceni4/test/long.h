#ifndef _LONGNUM_
#define _LONGNUM_

#include <iostream>
#include <string.h>
#include <string>
#include "number.h"

using namespace std;

class long_no: public number{
public:
	long_no();
	~long_no();

private:
	string m_strHodnota;

public:
	void tisk()const;
	void nacti();

	double hodnota() const;

}

#endif