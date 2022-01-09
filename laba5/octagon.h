#ifndef OCTAGON_H
#define OCTAGON_H

#include "figure.h"

class Octagon : public Figure {
public:
    Octagon();
    Octagon(std::istream &is);
    Octagon(Point a, Point b, Point c, Point d, Point e, Point f, Point g, Point h);
    Octagon(Octagon &other);
    double Area();
    size_t VertexesNumber();
    virtual ~Octagon();
    Octagon& operator=(const Octagon& other);
    Octagon& operator==(const Octagon& other);
    friend std::ostream& operator<<(std::ostream& os, Octagon& h);
private:
    Point a, b, c, d, e, f, g, h;
};
#endif // OCTAGON_H
