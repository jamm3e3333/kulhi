#include "Number.h"

Number::Number(){
}


Number::~Number(){
}


void Number::nacti(){
}

void Number::tisk() const{
}

double Number::operator+ (const Number& arg) const{
	return Hodnota() + arg.Hodnota(); // secteni hodnot dvou neznamych objektu 
}

double Number::operator+ (const double& arg) const{
	return Hodnota() + arg; //secteni hodoty objektu s argumentem typu double

}


