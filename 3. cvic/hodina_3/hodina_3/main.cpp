#include <iostream>
#include <string>

using namespace std;

class zlomek{
private:
	int m_intCitatel;
	int m_intJmenovatel;

public:
	zlomek() {
		cout << "Volan konstruktor" << endl;
		m_intCitatel = 0;
		m_intJmenovatel = 1;
	}

	zlomek(int citatel, int jmenovatel) {
		cout << "Volan konstruktor" << endl;
		m_intCitatel = citatel;
		m_intJmenovatel = jmenovatel;
	}

	zlomek& secti(const zlomek& arg) {
		zlomek novy;
		novy.m_intCitatel = m_intJmenovatel * arg.m_intJmenovatel;
		novy.m_intJmenovatel = m_intCitatel * arg.m_intJmenovatel + m_intJmenovatel * arg.m_intCitatel;
		return novy;
	}

	zlomek& odecti(const zlomek& arg) {
		zlomek novy;
		novy.m_intJmenovatel = m_intJmenovatel * arg.m_intJmenovatel;
		novy.m_intCitatel = arg.m_intJmenovatel * m_intCitatel - m_intJmenovatel * arg.m_intCitatel;
		return novy;
	}

	~zlomek() {
		cout << "Volan destruktor" << endl;
	}

	void tisk() {
		cout << m_intCitatel << "/" << m_intJmenovatel;
	}

	void nacti() {
		cout << "Nacti citatel: ";
		cin >> m_intCitatel;
		cout << "Nacti jmenovatel: ";
		cin >> m_intJmenovatel;
	}
};


int main() {
	zlomek a, b(2, 5), c;
	a.nacti();
	c = a.secti(b);
	a.tisk(); cout << " + "; b.tisk(); cout << " = "; c.tisk(); cout << endl;
	
	zlomek d(3, 56), e, f;
	e.nacti();
	f = d.odecti(e);
	d.tisk(); cout << " - "; e.tisk(); cout << " = "; f.tisk(); cout << endl;

	return 0;
}