#ifndef _LONGREAL_
#define _LONGREAL_
#include <iostream>
#include <string>
#include "Number.h"

using namespace std;

class LongReal:
	public Number{
public:
	LongReal();
	~LongReal();

private:
	string m_strNumber;

public:
	void nacti();
	void tisk() const;
};
#endif