#ifndef SQUARE_H
#define SQUARE_H

#include <figure.h>
#include <point.h>
#include <iostream>


class Square : public Figure {
public:
    Square();
    Square (const Point& a, const Point& b, const Point& c, const Point& d);
    Square(std::istream &is);
    Square(const Square& other);

    virtual ~Square();

    void Print();
    double Area2();

private:
    std::vector<Point> cords_;
};

#endif // SQUARE_H
