#include "Double.h"

Double::Double(){
	m_dblHodnota = 0;
}


Double::~Double(){
	cout << "Volani destruktoru tridy \"Double\"" << endl;

}


void Double::nacti(){

	cout << "Zadej hodnotu:";
	cin >> m_dblHodnota;
}


void Double::tisk() const{

	cout << m_dblHodnota << endl;
}

