#ifndef MONEY_H
#define MONEY_H
#include <iostream>

class Money {
public:
    Money();
    Money(std::istream &is);
    Money(unsigned long long rub, unsigned char cop);
    int operator +(Money& a);
    int operator -(Money& a);
    int operator *(Money& a);
    int operator /(Money& a);
    Money operator ++();
    Money operator --();
    bool operator ==(const Money& other);
    friend std::ostream& operator<<(std::ostream& os,const Money& a);
    ~Money();
private:
    unsigned long long rub;
    unsigned char cop;
};

#endif // MONEY_H
