#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <figure.h>

#include <iostream>
#include <point.h>
#include <vector>

class Triangle : public Figure {
public:
    Triangle();
    Triangle(const Point& a, const Point& b, const Point& c);
    Triangle(std::istream &is);
    Triangle(const Triangle& other);

    virtual ~Triangle();

    size_t VertexesNumber();
    void Print();
    double Area();
    double Area2();

private:
    std::vector<Point> cords_;
};

#endif // TRIANGLE_H
