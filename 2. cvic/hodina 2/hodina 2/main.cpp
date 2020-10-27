#include <iostream>
#include <string>

using namespace std;
class zlomek {

private:
	int m_intJmenovatel;
	int m_intCitatel;

public:
	//konstruktor
	zlomek(){ //default konstruktor
		m_intJmenovatel = 1;
		m_intCitatel = 0;
	}

	zlomek(int citatel, int jmenovatel){ //konstruktor s parametry
		m_intJmenovatel = jmenovatel;
		m_intCitatel = citatel;
	}

	void vlozJmenovatel(int jmenovatel){ //pristupova metoda
		//muzeme doplnit kontrolu 
		m_intJmenovatel = jmenovatel;
	}

	void vlozCitatel(int citatel){ //pristupova metoda
		m_intCitatel = citatel;
	}

	void tisk(){
		cout << m_intCitatel << "/" << m_intJmenovatel << endl;
	}

	void nacti(){
		cout << "Nacti citatel: ";
		cin >> m_intCitatel;
		cout << "Nacti jmenovatel: ";
		cin >> m_intJmenovatel;
	}

	zlomek secti(const zlomek& arg){ //objekt jako argument metody 
		zlomek novy;
		novy.m_intJmenovatel = m_intJmenovatel * arg.m_intJmenovatel;
		novy.m_intCitatel = m_intCitatel * arg.m_intJmenovatel + m_intJmenovatel * arg.m_intCitatel;

		return novy;
	}

	~zlomek(){
		cout << "Volani destruktoru" << endl;
	}
};

int main(){
	zlomek a, b, c;
	a.nacti(); //z klavesnice
	b.nacti(); //z klavesnice
	c = a.secti(b);
	
	c.tisk();

	//naplneni hodnot objektu
	//1. pomoci konstruktoru s parametry
	//2. pomoci pristupovych metod
	//	-clenske metody nejsou doporucene, protoze se prepisujou promene

	zlomek d(1,2), e(1,5), f;
	f = d.secti(e);
	d.tisk();
	e.tisk();
	f.tisk();

	d = zlomek(1,5);
	f = d.secti(e);
	d.tisk();
	e.tisk();
	f.tisk();

	d.vlozCitatel(10);
	d.tisk();


	return 0;
}