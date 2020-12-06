#include "number.h"
#include "double_cis.h"
#include <iostream>
#include <string>
#include <list>

using namespace std;

class zlomek: public number{

private:
	int m_intCitatel;
	int m_intJmenovatel;

public:
	zlomek(){
		m_intCitatel = 0;
		m_intJmenovatel = 1;
	}

	zlomek(int j, int c){
		if(j == 0)
			throw (char*) "Jmenovatel musi byt nenulovy.";
		m_intCitatel = c;
		m_intJmenovatel = j;
	}

	

	zlomek& secti(const zlomek& arg) const{
		zlomek novy;

		novy.m_intCitatel = novy.m_intCitatel*arg.m_intJmenovatel + novy.m_intJmenovatel*arg.m_intJmenovatel;
		novy.m_intJmenovatel = novy.m_intJmenovatel*arg.m_intJmenovatel;

		return novy;
	}

	void tisk() const{
		cout << m_intCitatel << "/" << m_intJmenovatel << endl;
	}

	void nacti(){
		cout << "Nacti citatel: ";
		cin >> m_intCitatel;

		cout << "Nacti jmenovatel: ";
		cin >> m_intJmenovatel;
	}

	double hodnota() const{
		return m_intCitatel/(double)m_intJmenovatel;
	}

	~zlomek(){

	}

};

int main(){
	zlomek z, z2(2,5);
	double_cis d;

	d.nacti();
	d.tisk();

	z.nacti();
	z.tisk();
	z2.tisk();


	number& n1 = z;
	number& n2 = d;

	string odpoved;
	list <number*> seznam;

	do{
		cout << "Zaloz zlomek (1), nebo double cislo (2): ";
		cin >> odpoved;
		number* ukazatelPredek;

		if(odpoved.compare("1") == 0){
			ukazatelPredek = new zlomek();
		}
		else if(odpoved.compare("2") == 0){
			ukazatelPredek = new double_cis();
		}
		else
			cout << "Nactel jsi spatne cislo. " << endl;

		try{
			ukazatelPredek->nacti();
			seznam.push_back(ukazatelPredek);
		}
		catch(char* err){
			cerr << "Spatna inicializace objektu.:" << err << endl;
			delete ukazatelPredek;
		}
		

		cout << "Pokracovat? -> (A/N)";
		cin >> odpoved;

	}
	while(odpoved.compare("A") == 0);

	list<number*>::iterator i;

	try{
		for(i = seznam.begin(); i != seznam.end(); i++){
			(*i)->tisk();
		}

	}
	catch(exception &err){
		cout << "Nelze vytisknou hodnoty objektu.";
		cout << err.what() << endl;
	}

	double soucet = 0;

	try{
		for(i = seznam.begin(); i!=seznam.end(); i++){
			soucet = *(*i)+soucet;
			cout << "Soucet objektu: " << soucet << endl;
		}
	}
	catch(exception &err){
		cout << "Nelze secist objekty.";
		cout << err.what() << endl;
	}

	for(i = seznam.begin(); i != seznam.end(); i++){
		delete(*i);
	}

}