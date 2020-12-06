#include "real.h"

real_no::real_no(){
	m_dblHodnota = 0;
}

real_no::~real_no(){
}

void real_no::nacti(){
	cout << "Nacti hodnotu typu double: ";
	cin >> m_dblHodnota;
}

void real_no::tisk() const{
	cout << m_dblHodnota;
}

double real_no::hodnota() const{
	return m_dblHodnota;
}
