#ifndef OCTAGON_H
#define OCTAGON_H

#include "figure.h"

class Octagon : public Figure{
public:
    Octagon();
    Octagon(std::istream& is);
    Octagon(Point point_a, Point point_b, Point point_c, Point point_d, Point point_e, Point point_f, Point point_g, Point point_h );
    size_t VertexesNumber();
    Octagon(Octagon &other);
    double Area();
    void Print(std::ostream& os);
    virtual ~Octagon();
    Octagon& operator=(const Octagon& other);
    Octagon& operator==(const Octagon& other);
    friend std::ostream& operator<<(std::ostream& os, Octagon& p);

private:
    Point point_a, point_b, point_c, point_d, point_e, point_f, point_g, point_h, ;
};

#endif // OCTAGON_H
