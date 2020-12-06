#ifndef _DOUBLECIS_
#define _DOUBLECIS_
#include "number.h"

using namespace std;

class double_cis: public number{

private:
	double m_dblHodnota;

public:
	double_cis();
	~double_cis();

	void tisk()const;
	void nacti();

	double hodnota()const;
	
};

#endif