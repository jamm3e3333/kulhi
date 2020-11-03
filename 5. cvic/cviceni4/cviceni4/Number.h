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
};
#endif