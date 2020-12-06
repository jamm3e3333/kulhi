#include "double_cis.h"

double_cis::double_cis(){
	m_dblHodnota = 0;
}

double_cis::~double_cis(){
}

void double_cis::nacti(){
	cout << "Nacti hodnotu: ";
	cin >> m_dblHodnota;
}

void double_cis::tisk() const{
	cout << m_dblHodnota << endl;
}

double double_cis::hodnota()const{
	return m_dblHodnota;
}

