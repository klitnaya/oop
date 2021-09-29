#include "square.h"
#include "point.h"
#include <cmath>

Square::Square() {
  cords_.assign(4, Point());
  std::cout << "Default square created" << std::endl;
}


Square::Square(std::istream &InputStream) {
  InputStream >> a;
  InputStream >> b;
  InputStream >> c;
  InputStream >> d;
  std::cout << "Squere created" << std::endl;
}


size_t VertexesNumber(){
  size_t num = 4;
  return num;
}


void Square::Print(std::osteam& os) {
    os << a << ", ";
    os << b << ", ";
    os << c << ", ";
    os << d << std::endl;
}

double Square::Area() {
    double len_a = a.dish(b);
    double len_b = b.dish(c);
    double p = len_a * len_b;
    return p;
}



Square::~Square() {
    std::cout << "Square deleted" << std::endl;
}
