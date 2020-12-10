#include <iostream>
#include <list>
#include <string>

using namespace std;

class nabytek{
	public:
		nabytek(){
			m_dblCena = 0.00;
			m_dblVaha = 0.00;
			m_strNazev = "NABYTEK 1";
		}
		~nabytek(){
		}

	private:
		double m_dblCena;
		double m_dblVaha;
		string m_strNazev;

	public:
		virtual double cena_vrat() const = 0{
				return m_dblCena;
			}

		virtual void cena_tisk() const{
		}

		virtual double vaha_vrat() const = 0{
				return m_dblVaha;
		}
		virtual void vaha_tisk() const{
		}

		virtual void nazev_tisk() const{
		}
};


class zidle: public nabytek{
public:
	zidle(){
		m_dblCena = 0.00;
		m_dblVaha = 0.00;
		m_strNazev = "Zidle z00";
		m_strOperatko = "NE";
	}

	zidle(double c, double v, string n, string op):m_dblCena(c), m_dblVaha(v), m_strNazev(n), m_strOperatko(op){
	}

	~zidle(){
	}

private:
	double m_dblCena;
	double m_dblVaha;

	string m_strNazev;
	string m_strOperatko;

public:
	double cena_vrat()const{
		return m_dblCena;
	}

	double vaha_vrat()const{
		return m_dblVaha;	
	}

	void cena_tisk() const{
		cout << "Cena zidle: " << m_dblCena << endl;
	}

	void vaha_tisk() const{
		cout << "Vaha zidle: " << m_dblVaha << endl;	
	}

	void nazev_tisk() const{
		cout << "Nazev zidle: " << m_strNazev << endl;
		cout << "Operatko: " << m_strOperatko << endl;	
	}
};

class stul: public nabytek{
public:
	stul(){
		m_dblCena = 0.00;
		m_dblVaha = 0.00;
		m_strNazev = "stul s 00";
		m_strSkl = "NE";

	}

	stul(double c, double v, string n, string skl):m_dblCena(c), m_dblVaha(v), m_strNazev(n), m_strSkl(skl){
	}

private: 
	double m_dblCena;
	double m_dblVaha;
	string m_strNazev;
	string m_strSkl;

public:
	double cena_vrat() const{
		return m_dblCena;
	}

	double vaha_vrat() const{
		return m_dblVaha;
	}

	void cena_tisk()const{
		cout << "Cena stolu: " << m_dblCena << endl;
	}

	void vaha_tisk()const{
		cout << "Vaha stolu: " << m_dblVaha << endl;
	}


	void nazev_tisk() const{
		cout << "Nazev stolu: " << m_strNazev << endl;
		cout << "Sklenena deska: " << m_strSkl << endl;
	}

};

class skrin: public nabytek{
public:
	skrin(){
		m_dblCena = 0.00;
		m_dblVaha = 0.00;
		m_strNazev = "skrin skr 00";
		m_intSirka = 0;
		m_intHloubka = 0;
		m_intDelka = 0;		
	}

	skrin(double c, double v, string n, int s, int h, int d):m_dblCena(c), m_dblVaha(v), m_strNazev(n), m_intSirka(s), m_intHloubka(h), m_intDelka(d){
	}

private: 
	int m_intSirka;
	int m_intHloubka;
	int m_intDelka;

	double m_dblCena;
	double m_dblVaha;

	string m_strNazev;
	

public:
	double cena_vrat() const{
		return m_dblCena;
	}

	double vaha_vrat() const{
		return m_dblVaha;
	}

	void cena_tisk()const{
		cout << "Cena skrine: " << m_dblCena << endl;
	}

	void vaha_tisk()const{
		cout << "Vaha skrine: " << m_dblVaha << endl;
	}


	void nazev_tisk() const{
		cout << "Nazev skrine: " << m_strNazev << endl;
		cout << "Sirka: " << m_intSirka << "\tHloubka: " << m_intHloubka << "\tDelka: " << m_intDelka << endl;
	}

};


int main(){
	int j = 0;
	double soucetCena = 0;
	double soucetVaha = 0;
	
	nabytek* ptrPredek;

	list<nabytek*> seznam;
	list<nabytek*>::iterator i;


	ptrPredek = new zidle(500.3,3023.3,"zidle 1","ANO");
	seznam.push_back(ptrPredek);

	ptrPredek = new zidle(200.1,3235.4,"zidle 2","NE");
	seznam.push_back(ptrPredek);

	ptrPredek = new stul(400.5, 5435.5,"stul 1","NE");
	seznam.push_back(ptrPredek);

	ptrPredek = new stul(4324.4, 54.5,"stul 2","ANO");
	seznam.push_back(ptrPredek);

	ptrPredek = new skrin(904.4, 3234.3,"skrin 1",50,200,100);
	seznam.push_back(ptrPredek);

	for(i = seznam.begin(); i != seznam.end(); i++){
		(*i)->cena_tisk();
		(*i)->vaha_tisk();
		(*i)->nazev_tisk();

		cout << endl;

		soucetCena = (*i)->cena_vrat() + soucetCena;
		soucetVaha = (*i)->vaha_vrat() + soucetVaha;
	}
	cout << "Vaha nabytku : " << soucetVaha << endl;
	cout << "Cena nabytkku : " << soucetCena << endl;

	for(i = seznam.begin(); i != seznam.end(); i++){
		delete(*i);
	}

	return 0;
}