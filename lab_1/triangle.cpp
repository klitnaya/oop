#include "triangle.h"
#include "point.h"
#include <cmath>

Triangle::Triangle(){
  cords_.assign(3, Point());
  std::cout << "Default triangle created" << std::endl;
}

Triangle::Triangle(const Point& a, const Point& b, const Point& c){
  cords_.reserve(3);
  cords_.push_back(a);
  cords_.push_back(b);
  cords_.push_back(c);  
  std::cout << "Triangle created" << std::endl;
}

Triangle::Triangle(std::istream &is) {
  std::cout << "Enter data:" <<  std::endl;
  cords_.assign(3, Point());
  is >> cords_[0] >> cords_[1] >> cords_[2];
  std::cout << "Triangle created via istream" << std::endl;
}

Triangle::Triangle(const Triangle& other){
  cords_ = oter.cords_;
  std::cout << "Made copy of triangle" << std::endl;

}

size_t VertexesNumber(){
  return 3;
}

void Triangle::Print(std::osteam& os) {
    os << cords_[0] << ", ";
    os << cords_[1] << ", ";
    os << cords_[2] << std::endl;
}

double Triangle::Area2() {
    double len_a = cords_[1].dist(cords_[0]);
    double len_b = cords_[2].dist(cords_[1]);
    double len_c = cords_[0].dist(cords_[2]);
    double p = (len_a + len_b + len_c) / 2.0;
    return p * (p - len_a) * (p - len_b) * (p - len_c);
}

double Triangle::Area() {
    return std::sqrt(Area2());
}

Triangle::~Triangle() {
    std::cout << "Triangle deleted" << std::endl;
}
