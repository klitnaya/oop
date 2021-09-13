#include "Octagon.h"
#include "point.h"
#include <cmath>

Octagon::Octagon()

 {
  cords_.assign(8, Point());
  std::cout << "Default Octagon created" << std::endl;
}

Octagon::Octagon(const Point& a, const Point& b, const Point& c){
  cords_.reserve(8);
  cords_.push_back(a);
  cords_.push_back(b);
  cords_.push_back(c);  
  std::cout << "Octagon created" << std::endl;
}

Octagon::Octagon(std::istream &is) {
  std::cout << "Enter data:" <<  std::endl;
  cords_.assign(8, Point());
  is >> cords_[0] >> cords_[1] >> cords_[2];
  std::cout << "Octagon created via istream" << std::endl;
}

Octagon::Octagon(const Octagon& other){
  cords_ = oter.cords_;
  std::cout << "Made copy of Octagon" << std::endl;

}

size_t VertexesNumber(){
  return 8;
}

void Octagon::Print(std::osteam& os) {
    os << cords_[0] << ", ";
    os << cords_[1] << ", ";
    os << cords_[2] << ", ";
    os << cords_[3] << ", ";
    os << cords_[4] << ", ";
    os << cords_[5] << ", ";
    os << cords_[6] << ", ";
    os << cords_[7] << std::endl;
}

double Octagon::Area2() {
    double len_a = cords_[1].dist(cords_[0]);
    double len_b = cords_[2].dist(cords_[1]);
    double len_c = cords_[3].dist(cords_[2]);
    double len_d = cords_[4].dist(cords_[3]);
    double len_e = cords_[5].dist(cords_[4]);
    double len_f = cords_[6].dist(cords_[5]);
    double len_g = cords_[7].dist(cords_[6]);
    double len_h = cords_[0].dist(cords_[7]);

    double len_a1 = cords_[0].dist(cords_[2]);
    double len_a2 = cords_[0].dist(cords_[3]);
    double len_a3 = cords_[0].dist(cords_[4]);
    double len_a4 = cords_[0].dist(cords_[5]);
    double len_a5 = cords_[0].dist(cords_[6]);

    double p;
    double p1 = (len_a + len_b + len_a1) / 2.0;
    p1 = p1 * (p1 - len_a) * (p1 - len_b) * (p1 - len_a1);
    p1 = sqrt(p1); 
    p = p + p1;
    p1 = (len_a1 + len_a2 + len_c) / 2.0;
    p1 = p1 * (p1 - len_a1) * (p1 - len_a2) * (p1 - len_c);
    p1 = sqrt(p1); p =  p + p1;
    p1 = (len_a3 + len_a2 + len_d) / 2.0;
    p1 = p1 * (p1 - len_a3) * (p1 - len_a2) * (p1 - len_d);
    p1 = qrt(p1);  p =  p + p1;
    p1 = (len_a3 + len_a4 + len_e) / 2.0;
    p1 = p1 * (p1 - len_a3) * (p1 - len_a4) * (p1 - len_e);
    p =  p + sqrt(p1);
    p1 = (len_a4 + len_a5 + len_f) / 2.0;
    p1 = p1 * (p1 - len_a4) * (p1 - len_a5) * (p1 - len_f);
    p =  p + sqrt(p1);
    p1 = (len_a5 + len_g + len_h) / 2.0;
    p1 = p1 * (p1 - len_a5) * (p1 - len_g) * (p1 - len_h);
    p =  p + sqrt(p1);

    return p ;
}

double Octagon::Area() {
    return std::sqrt(Area2());
}

Octagon::~Octagon() {
    std::cout << "Octagon deleted" << std::endl;
}
