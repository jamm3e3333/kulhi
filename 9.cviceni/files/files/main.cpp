#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class zlomek{
	friend ostream& operator <<(ostream& arg, const zlomek& arg2);
private:
	int m_intCitatel, m_intJmenovatel;
public:
	zlomek(int c, int j){
		m_intCitatel = c;
		m_intJmenovatel = j;
	}
};

ostream& operator <<(ostream& arg, const zlomek& arg2){
	return arg << arg2.m_intCitatel << "/" << arg2.m_intJmenovatel;
}

int main(){
	ostream* vystup = &cout;
	zlomek z(1, 3);
	*vystup << "Tisknu na obrazovku. " << z << endl;

	fstream soubor;
	soubor.open("C:\\Users\\Uzivatel\\Documents\\soubor.txt", ios::out);
	vystup = &soubor;
	*vystup << "Tisknu do souboru. " << z << endl;

	vystup->put(1);
	vystup->put(65);

	stringstream pamet;
	vystup = &pamet;
	*vystup << "Tisknu do pameti." << z << endl;

	vystup = &cerr;
	*vystup << "Tisknu do cerr." << z << endl;

	int cislo;
	istream* vstup;
	vstup = &cin;
	cout << "Cteni z klavesnice";
	*vstup >> cislo;
	cout << "Nacteno: " << cislo << endl;
	soubor.close();

	soubor.open("C:\\Users\\Uzivatel\\Documents\\cisla.txt", ios::in && ios::binary); //v souboru je 1 2 3 4 5
	vstup = &soubor;
	cout << "Cteni ze souboru";
	*vstup >> cislo;
	cout << "Nacteno: " << cislo << endl;

	vstup->seekg(-2);
	cout << "Cteni ze souboru."; 
	*vstup >> cislo;
	cout << "Nacteno: " << cislo << endl;

	char c;
	soubor.get(c);
	cout << "Nacten byte: " << c << endl;

	stringstream pamet2;
	pamet2 << string("4 5 6");
	vstup = &pamet2;
	cout << "Cteni z pameti.";
	*vstup >> cislo;
	cout << "Nacteno: " << cislo << endl;

	vstup->seekg(-2);

	cout << "Cteni z pameti. ";
	*vstup >> cislo;
	cout << "Nacteno: " << cislo << endl;

	return 0;
}