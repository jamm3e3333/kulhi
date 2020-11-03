#include <iostream>
#include <string>
#include <stdlib.h>
#include "Double.h"
#include "Number.h"
#include "LongReal.h"
#include <list>

using namespace std;

class zlomek : public Number{
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

	zlomek& secti(const zlomek& arg) const{
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
	list <Number*> seznam; //linearni seznam
	string odpoved;
		do{
			cout << "Zvol typ cisla (1 zlomek, 2 LongReal, 3 Double)" << endl;
			cin >> odpoved;
			Number* ukazatelPredek;
			if(odpoved.compare("1") == 0){
				ukazatelPredek = new zlomek();
			}
			else if(odpoved.compare("2") == 0){
				ukazatelPredek = new LongReal();

			}
			else if(odpoved.compare("3") == 0){
				ukazatelPredek = new Double();
			}
			else{
				cout << "Zadal jsi spatnou odpoved, ty demetere" << endl;
				return 0;
			}
			// nactem hodnotu cisla z klavesnice 
			cout << "Zadej hodnotu: ";
			ukazatelPredek->nacti(); // chceme volat cteni potomku

			seznam.push_back(ukazatelPredek); //ukladam do linearniho seznamu


			cout << "Pokracovat (A/N)?";
			cin >> odpoved;
		}while(odpoved.compare("A") == 0);

		//tisk na obrazovku
		cout << endl << "Zadana cisla jsou tyto: " << endl;
		list<Number*>::iterator i;

		for(i = seznam.begin(); i!=seznam.end(); i++){
			(*i)->tisk(); //volam ukazatelPredek->tisk()
			cout << endl;
		}

		for(i = seznam.begin(); i!=seznam.end(); i++){
			delete (*i); //dealokace ukazatelPredek
		}

	//LongReal LR;
	//Double DBL;
	//Number NMBR;
	//LR.tisk();
	//DBL.tisk();
	//string tlacitko;
	//double m_doubleHodnota;
	//zlomek pole[10]; //volaji se implicitni konstruktory 10x
	//for (int i = 0; i < 10; i++) {
	//	cout << "zadej zlomek c." << i+1 << ":" << endl;
	//	pole[i].nacti();
	//	pole[i].tisk();
	//	cout << endl;
	//}
	////seradit pomoci qsort funkce 
	//qsort(pole, sizeof(pole) / sizeof(zlomek), sizeof(zlomek), zlomek::porovnej);
	//cout << "Porovnane pole:" << endl;
	//for (int j = 0; j < 10 ;j++) {
	//	cout << "prvek c." << j + 1 << ":";
	//	pole[j].tisk();
	//	cout << endl;
	//}

	return 0;
}