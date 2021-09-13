#ifndef OCTAGON_H
#define OCTAGON_H

#include <figure.h>
#include <point.h>
#include <iostream>


class Octagon : public Figure {
public:
    Octagon();
    Octagon (const Point& a, const Point& b, const Point& c, const Point& d, const Point& e, const Point& f, const Point& g, const Point& h);
    Octagon(std::istream &is);
    Octagon(const Octagon& other);

    virtual ~Octagon();

    void Print();
    double Area();
    double Area2();

private:
    std::vector<Pont> cords_;
};

#endif // OCTAGON_H
