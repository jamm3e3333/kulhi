#include "LongReal.h"

LongReal::LongReal(){
	m_strNumber = "Halo, je tam nekdo?";
}

LongReal::~LongReal(){
}

void LongReal::nacti(){
	string hodnota;
	cout << "Nacti cislo long real: ";
	cin >> hodnota;
	char* ukazatelNaKonecCisla;
	strtod(hodnota.c_str(), &ukazatelNaKonecCisla);
	int pocetPrevedZnaku = (ukazatelNaKonecCisla - hodnota.c_str());

	if(hodnota.length() != pocetPrevedZnaku) 
		throw (char*) "Zadana neciselna hodnota!";
	cin >> m_strNumber;
}

void LongReal::tisk() const{
	cout << m_strNumber << endl;
}

double LongReal::Hodnota() const{
	return stod(m_strNumber);
}
