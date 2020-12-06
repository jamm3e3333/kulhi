#include "long.h"

long_no::long_no(){
	m_strHodnota = "0.00";
}

long_no::~long_no(){
}

void long_no::nacti(){
	cout << "Nact velke cislo: ";

	cin >> m_strHodnota;

	int rozdil;
	char* konec;

	strtod(m_strHodnota.c_str(), &konec);

	rozdil = konec- m_strHodnota.c_str();

	if(m_strHodnota.length() != rozdil)
		throw (char*) "Zadana spatna hodnota!";
}

void long_no::tisk()const{
	cout << m_strHodnota << endl;
}

double long_no::hodnota() const{
	stod(m_strHodnota);
}
