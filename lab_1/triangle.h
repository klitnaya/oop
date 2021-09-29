#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <figure.h>

#include <iostream>
#include <point.h>
#include <vector>
//#include "figure.h"

class Triangle : public Figure {
public:
    Triangle(std::istream &InputStream);
    Triangle(const Triangle& other);

    virtual ~Triangle();

    size_t VertexesNumber();
    void Print();
    double Area();
   
private:
    Point a;
    Point b;
    Point c;
};

#endif // TRIANGLE_H
