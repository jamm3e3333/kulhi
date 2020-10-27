#include <iostream>
#include <stdlib.h>

using namespace std;

class zlomek{
private:
	int m_intCitatel;
	int m_intJmenovatel;
public:
	zlomek(){

	}
	zlomek(int c, int j){
		m_intCitatel = c;
		m_intJmenovatel = j;
	}
	void tisk(){
		cout << m_intCitatel << "/" << m_intJmenovatel << endl;
	}
};

int main(){
	zlomek a;
	zlomek * p1 = (zlomek*)malloc(sizeof(zlomek)*1);
	zlomek *p2 = new zlomek();

	p1->tisk();
	p2->tisk();

	zlomek& b = *p1;

	b.tisk();

	free((void*)p1);

	delete p2;
	
	return 0;
}