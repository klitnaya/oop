#include "triangle.h"
#include "point.h"
#include <cmath>


Triangle::Triangle(std::istream &InputStream){
  InputStream >> a;
  InputStream >> b;
  InputStream >> c;
  std::cout << "Triangle created" << std::endl;
}



size_t VertexesNumber(){
  size_t num = 3;
  return num;
}

void Triangle::Print(std::osteam& os) {
    os << a << ", ";
    os << b << ", ";
    os << c << std::endl;
}

double Triangle::Area() {
    double p = 0.5*abc((b.X()-a.X())*(c.Y()-a.Y())-(c.X()-a.X()*(b.Y()-a.Y())));
    return p;
}


Triangle::~Triangle() {
    std::cout << "Triangle deleted" << std::endl;
}
