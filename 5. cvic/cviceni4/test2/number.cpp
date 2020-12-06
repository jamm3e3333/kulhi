#include "number.h"

number::number(){
}

number::~number(){

}

void number::nacti(){
}

void number::tisk()const{
}

double number::operator+(const number& arg)const{
	return hodnota() + arg.hodnota();
}

double number::operator+(const double& arg1)const{
	return hodnota() + arg1;
}

