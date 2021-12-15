#include <iostream>
#include "Modulo.h"
#include <cmath>

Money::Money(){
    rub = 1;
    cop = 1;
}

Money::Money(std::istream &is){
    is >> rub;
    is >> cop;
}

Money::Money(int first, int second){
    rub = first;
    cop = second;
}

int Money::operator +(Money& a){
    return this->rub%this->cop + a.rub%a.cop;
}

int Money::operator -(Money& a){
    return this->rub%this->cop - a.rub%a.cop;
}

int Money::operator *(Money& a){
    return (this->rub%this->cop) * (a.rub%a.cop);
}

int Money::operator /(Money& a){
    return (this->rub%this->cop) / (a.rub%a.cop);
}

Money Money::operator ++(){
    this->cop++;
    this->rub++;
    return *this;
}

Modulo Modulo::operator --(){
    this->cop--;
    this->rub--;
    return *this;
}

std::ostream& operator<<(std::ostream& os,const Money& a){
    os << a.rub << " " << a.cop << std::endl;
    return os;
}

bool Modulo::operator==(const Money& other){
    return this->cop == other.cop && this->rub == other.rub;
}

Money::~Money(){
    std::cout << "Money has deleted" << std::endl;
}
