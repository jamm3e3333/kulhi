#include <iostream>

using namespace std;

class zlomek{
	friend ostream& operator <<(ostream& arg1, const zlomek& arg2);
private:
	int m_intCitatel;
	int m_intJmenovatel;
	
public:
	zlomek(int cit, int jmen): m_intCitatel(cit), m_intJmenovatel(jmen){
	}

	zlomek(){
	}

	zlomek(int arg): m_intCitatel(arg), m_intJmenovatel(1){

	}

	zlomek operator +(const zlomek& arg) const{
		zlomek pomocny;
		pomocny.m_intJmenovatel = m_intJmenovatel * arg.m_intJmenovatel;
		pomocny.m_intCitatel = m_intCitatel * arg.m_intJmenovatel + arg.m_intCitatel * m_intJmenovatel;
		return pomocny;
	}

	zlomek operator +(int arg) const{

		return this->operator+(zlomek(arg)); //volam operator +(const zlomek&)
	}

	const zlomek& operator =(int arg){
		//*this = zlomek(arg);
		m_intJmenovatel = 1;
		m_intCitatel = arg;
		return *this;
	}

	void tisk(){
		cout << m_intCitatel << "/" << m_intJmenovatel << endl;
	}
};

//globalni operator
zlomek operator +(int arg1, const zlomek& arg2){
	return zlomek(arg1) + arg2;
}

//globalni operator
ostream& operator <<(ostream& arg1, const zlomek& arg2){
	arg1 << arg2.m_intCitatel << "/" << arg2.m_intJmenovatel;
	return arg1;
}

int main(){
	zlomek A(1, 3);
	zlomek B(1, 2);
	zlomek C = A + 5;
	zlomek D = 1 + B;
	cout << C << " = " << A << " + 5 " << endl;
	cout << D << " = 1 + " << B << endl;
	return 0;
}
