#include "Double.h"

Double::Double(){
	m_dblHodnota = 0;
}


Double::~Double(){
}


void Double::nacti(){

	cout << "Zadej hodnotu:";
	cin >> m_dblHodnota;
}


void Double::tisk() const{

	cout << m_dblHodnota << endl;
}

double Double::Hodnota() const{
	return m_dblHodnota;
}

