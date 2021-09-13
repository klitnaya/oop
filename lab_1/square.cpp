#include "square.h"
#include "point.h"
#include <cmath>

Square::Square() {
  cords_.assign(4, Point());
  std::cout << "Default square created" << std::endl;
}

Square::Square(double a, double b, double c, double d){
  cords_.reserve(4);
  cords_.push_back(a);
  cords_.push_back(b);
  cords_.push_back(c);
  cords_.push_back(d);
  std::cout << "Squere created" << std::endl;
}

Square::Square(std::istream &is) {
  std::cout << "Enter data:" <<  std::endl;
  is >> cords_[0] >> cords_[1] >> cords_[2] >> cords_[3];
  std::cout << "Square created via istream" << std::endl;
}

Square::Square(const Square& other) {
  cords_ = oter.cords_;
  std::cout << "Made copy of square" << std::endl;

}

size_t VertexesNumber(){
  return 4;
}


void Square::Print(std::osteam& os) {
    os << cords_[0] << ", ";
    os << cords_[1] << ", ";
    os << cords_[2]<< ", ";
    os << cords_[3] << std::endl;
}

double Square::Area2() {
    double len_a = cords_[1].dist(cords_[0]);
    double len_b = cords_[2].dist(cords_[1]);
    double p = len_a * len_b;
    return p;
}

/*double Square::Area() {
    return std::sqrt(Area2());
}*/

Square::~Square() {
    std::cout << "Square deleted" << std::endl;
}
