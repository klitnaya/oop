#ifndef OCTAGON_H
#define OCTAGON_H

#include "figure.h"
#include <iostream>


class Octagon : public Figure {
    public:
    Octagon(std::istream &InputStream);
    Octagon();
    double GetArea();
    size_t VertexesNumber();
    double Area();
    void Print(std::ostream &OutputStream);
    friend bool operator == (Octagon& p1, Octagon& p2);
    friend std::ostream& operator << (std::ostream& os, Octagon& p);
    virtual ~Octagon();
    double area;

    private:
    Point a;
    Point b;
    Point c;
    Point d;
    Point e;
    Point f;
    Point g;
    Point h;
};
#endif
