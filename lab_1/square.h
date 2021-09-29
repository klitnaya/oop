#ifndef SQUARE_H
#define SQUARE_H

#include <figure.h>
#include <point.h>
#include <iostream>


class Square : public Figure {
public:
    Square(std::istream &InputStream);

    virtual ~Square();

    void Print(std::ostream &os);
    double Area();

private:
    Point a;
    Point b;
    Point c;
    Point d;
};

#endif // SQUARE_H
