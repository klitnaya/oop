#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "figure.h"

class Triangle : public Figure{
public:
    Triangle(std::istream& is);

    size_t VertexesNumber();
    double Area();
    void Print(std::ostream& os);
    virtual ~Triangle();

private:
    Point point_a, point_b, point_c;
};

#endif // TRIANGLE_H