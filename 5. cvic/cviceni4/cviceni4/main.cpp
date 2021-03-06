#include <iostream>
#include <string>
#include <stdlib.h>
#include "Double.h"
#include "Number.h"
#include "LongReal.h"
#include <list>
#include <fstream>

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
		//detekovat nulovy jmenovatel
		if(jmenovatel == 0) throw (char*)"Nulovy jmenovatel v konstruktoru zlomku";
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
		int citatel, jmenovatel;
		cout << "Nacti citatel: ";
		cin >> citatel;
		cout << "Nacti jmenovatel: ";
		cin >> jmenovatel;
		if(jmenovatel == 0) throw (char*)"Nulovy jmenovatel pri cteni z klavesnice!";
		m_intCitatel = citatel;
		m_intJmenovatel = jmenovatel;
	}

	double Hodnota() const{ // vypocte desetinnou hodnotu cisla
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
		if (refA.Hodnota() < refB.Hodnota()) return -1;
		if (refA.Hodnota() > refB.Hodnota()) return 1;
		return 0;
	}

	~zlomek() {
		cout << "Volan destruktor" << endl;
	}
};

ostream& operator<<(ostream& arg1, const Number& arg2){
	return arg1 << arg2.Hodnota();
}


int main() {
	zlomek z(1, 3);
	Double d;
	d.nacti();
	LongReal l;
	l.nacti();

	cout << "z = " << z.Hodnota() << ", d = " << d.Hodnota() << ", l = " << l.Hodnota() << endl;

	Number& n1 = z;
	Number& n2 = d;
	Number& n3 = l;

	cout << "soucet = " << n1 + (n2 + n3) << endl;
	//cout << "soucet =" << n1.operator+(n2.operator+(n3)) << endl;

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

			try{
			ukazatelPredek->nacti(); // chceme volat cteni potomku
			seznam.push_back(ukazatelPredek); //ukladam do linearniho seznamu
			}
			catch(char* err){
				cout << "Pozor! Nastala chyba! Zadejte znovu. " << err << endl;
				delete ukazatelPredek;
			}
			cout << "Pokracovat (A/N)?";
			cin >> odpoved;
		}while(odpoved.compare("A") == 0);

		//tisk na obrazovku
		cout << endl << "Zadana cisla jsou tyto: " << endl;
		list<Number*>::iterator i;

		try{
			for(i = seznam.begin(); i!=seznam.end(); i++){
				(*i)->tisk(); //volam ukazatelPredek->tisk()
				cout << *(*i); // cout << Number(???)

				cout << endl;
			}
		}
		catch(exception &err){
			cerr << "Nelze vytisknout obsah objektu chyba!!! " << endl;
			cerr << err.what() << endl;
		}

		double soucet = 0;
		try{
			for(i = seznam.begin(); i!=seznam.end(); i++){
			
				soucet = *(*i)+soucet;
				//soucet = UkazatelPredek->operator+(soucet); //opearator+(double arg);
				(*i)->tisk(); //volam ukazatelPredek->tisk()
				cout << endl;
			}
			cout << "soucet = " << soucet << endl;
		}
		catch(exception &err){
			cout << "Nelze vypocist soucet, chyba !!!" << endl;
			cout << err.what() << endl;
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