#ifndef OCTAGON_H
#define OCTAGON_H

#include "figure.h"

class Octagon : public Figure{
public:
    Octagon(std::istream& is);

    size_t VertexesNumber();
    double Area();
    void Print(std::ostream& os);
    virtual ~Octagon();

private:
    Point point_a, point_b, point_c, point_d, point_e, point_f, point_g, point_h, ;
};

#endif // OCTAGON_H