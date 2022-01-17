#include <iostream>
#include "Money.h"
#include <cmath>

Money::Money(){
    rub = 1;
    cop = 1;
}

Money::Money(std::istream &is){
    is >> rub;
    is >> cop;
}

Money::Money(unsigned long long first, unsigned long long second){
    rub = first;
    cop = second;
}

Money Money::operator +(Money& a){
    this->rub = this->rub + a.rub;
    this->cop += a.cop;
    return *this;//->rub%this->cop + a.rub%a.cop;
}

Money Money::operator -(Money& a){
    this->rub = this->rub - a.rub;
    this->cop -= a.cop;
    return *this;//->rub%this->cop - a.rub%a.cop;
}

Money Money::operator *(Money& a){
    this->rub = this->rub * a.rub;
    this->cop *= a.cop;
    return *this;//(this->rub%this->cop) * (a.rub%a.cop);
}

Money Money::operator /(Money& a){
    this->rub = this->rub / a.rub;
    this->cop /= a.cop;
    return *this;//(this->rub%this->cop) / (a.rub%a.cop);
}

Money Money::operator ++(){
    this->cop++;
    this->rub++;
    return *this;
}

Money Money::operator --(){
    this->cop--;
    this->rub--;
    return *this;
}

std::ostream& operator<<(std::ostream& os,const Money& a){
    os << a.rub << "," << a.cop << std::endl;
    return os;
}

bool Money::operator==(const Money& other){
    return this->cop == other.cop && this->rub == other.rub;
}

Money::~Money(){
    std::cout << "Money has deleted" << std::endl;
}