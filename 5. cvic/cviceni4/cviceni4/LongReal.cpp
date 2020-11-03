#include "LongReal.h"

LongReal::LongReal(){
	m_strNumber = "Halo, je tam nekdo?";
}

LongReal::~LongReal(){
	cout << "Volani destruktoru tridy \"LongReal\"" << endl;

}

void LongReal::nacti(){
	cout << "Nacti cislo: ";
	cin >> m_strNumber;
}

void LongReal::tisk() const{
	cout << m_strNumber << endl;
}
