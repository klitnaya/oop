#ifndef OCTAGON_H
#define OCTAGON_H

#include "figure.h"
#include "point.h"
#include <iostream>


class Octagon : public Figure {
  public:
    Octagon(std::istream &InputStream);
 
    virtual ~Octagon();

    void Print(std::ostream &OutputStream);
    double Area();

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

#endif // OCTAGON_H
