#include <iostream>
#include <list>
#include <array> 

using namespace std;

double delit(double arg1, double arg2){
	if (arg2 == 0) throw (char*)"deleni nulou";
	return arg1/arg2;
}

double vypocet(int a, int b, int c){
	return a + delit(b, c);
}

int main(){
	try{
		cout << "5/2 = " << vypocet(1, 2, 0) << endl;
		cout << "3/0 = " << delit(3,0) << endl;
	}
	catch(char* err){
		cout << "Chyba : " << err << endl;
	}
	catch(...){
		cout << "Neznama chyba." << endl;
	}

	list<int> lin_seznam;

	lin_seznam.push_back(1);
	lin_seznam.push_back(15);
	lin_seznam.push_back(-8);
	lin_seznam.push_back(3);
	list<int>::iterator i;
	for(i = lin_seznam.begin(); i != lin_seznam.end(); i++){
		cout << *i << endl;
	}

	array<int,3> pole;
	pole[0] = 1;
	pole[1] = 15;
	pole[2] = -8;
	int j;
	for(j = 0; j < 3; j++)
		cout << pole[j] << endl;
	{//zavorky zajistuji omezenou zivotnost promennych
		shared_ptr<int> ukazatel2;
		throw "chyba";
		{
			shared_ptr<int> ukazatel1(new int(10));
			ukazatel2 = ukazatel1;
			cout << "pocet odkazu: " << ukazatel2.use_count();
			//zanika ukazatel1 ale data  10 ziji dale v ukazatel2
		}
		cout << "pocet odkazu: " << ukazatel2.use_count();
		cout << *ukazatel2 << endl;
	}//zanika ukazatel2 i alokovana pamet 10
}
