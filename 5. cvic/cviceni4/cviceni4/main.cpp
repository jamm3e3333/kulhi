#include <iostream>
#include <string>
#include <stdlib.h>
#include "Double.h"
#include "Number.h"
#include "LongReal.h"

using namespace std;

class zlomek{
private:
	int m_intCitatel;
	int m_intJmenovatel;

public:
	zlomek() {
		m_intCitatel = 0;
		m_intJmenovatel = 1;
	}

	zlomek(int citatel, int jmenovatel) {
		m_intCitatel = citatel;
		m_intJmenovatel = jmenovatel;
	}

	zlomek& secti(const zlomek& arg) {
		zlomek novy;
		novy.m_intCitatel = m_intJmenovatel * arg.m_intJmenovatel;
		novy.m_intJmenovatel = m_intCitatel * arg.m_intJmenovatel + m_intJmenovatel * arg.m_intCitatel;
		return novy;
	}

	zlomek& odecti(const zlomek& arg) const{ //zaklad objekt, nemeni ho, tak jako parametr
		zlomek novy;
		novy.m_intJmenovatel = m_intJmenovatel * arg.m_intJmenovatel;
		novy.m_intCitatel = arg.m_intJmenovatel * m_intCitatel - m_intJmenovatel * arg.m_intCitatel;
		return novy;
	}

	void tisk() const { //rozsirujeme moznost pouziti (i pro konstatni instance - funkce nemeni objekt)
		cout << m_intCitatel << "/" << m_intJmenovatel;
	}

	void nacti() {
		cout << "Nacti citatel: ";
		cin >> m_intCitatel;
		cout << "Nacti jmenovatel: ";
		cin >> m_intJmenovatel;
	}

	double hodnota() { // vypocte desetinnou hodnotu cisla
		return m_intCitatel /(double)m_intJmenovatel;
	}

	/*callback funkce pro qsort ma vypadat takto 
	int porovnej(void* A, void* B) 1 A > B, 0 A == B, -1 A < B	 
	*/

	//klicove slovo static nevola klicove slovo this a odrizne metodu od instanci (pri cb funkci)
	//int porovnej(zlomek* this, void* A, void* B)
	//static int porovnej(void* A, void* B) - ztraci clenske metody (ukazatel na clenske promenne)
	static int porovnej(const void* A,const void* B) { 
		zlomek& refA = *(zlomek*)A;
		zlomek& refB = *(zlomek*)B;
		if (refA.hodnota() < refB.hodnota()) return -1;
		if (refA.hodnota() > refB.hodnota()) return 1;
		return 0;
	}

	~zlomek() {
		cout << "Volan destruktor" << endl;
	}
};


int main() {
	LongReal LR;
	Double DBL;
	Number NMBR;
	LR.tisk();
	DBL.tisk();
	string tlacitko;
	double m_doubleHodnota;
	zlomek pole[10]; //volaji se implicitni konstruktory 10x
	for (int i = 0; i < 10; i++) {
		cout << "zadej zlomek c." << i+1 << ":" << endl;
		pole[i].nacti();
		pole[i].tisk();
		cout << endl;
	}
	//seradit pomoci qsort funkce 
	qsort(pole, sizeof(pole) / sizeof(zlomek), sizeof(zlomek), zlomek::porovnej);
	cout << "Porovnane pole:" << endl;
	for (int j = 0; j < 10 ;j++) {
		cout << "prvek c." << j + 1 << ":";
		pole[j].tisk();
		cout << endl;
	}

	return 0;
}