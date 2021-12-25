#ifndef MONEY_H
#define MONEY_H
#include <iostream>

class Money {
public:
    Money();
    Money(std::istream &is);
    Money(unsigned long long rub, unsigned long long cop);
    Money operator +(Money& a);
    Money operator -(Money& a);
    Money operator *(Money& a);
    Money operator /(Money& a);
    Money operator ++();
    Money operator --();
    bool operator ==(const Money& other);
    friend std::ostream& operator<<(std::ostream& os,const Money& a);
    ~Money();
private:
    unsigned long long rub;
    unsigned long long cop;
};

#endif // MONEY_H
