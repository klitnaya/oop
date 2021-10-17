#include "octagon.h"
#include <cmath>

Octagon::Octagon(): point_a(0,0), point_b(0,0), point_c(0,0), point_d(0,0), point_e(0,0), point_f(0,0), point_g(0,0), point_h(0,0){
}

Octagon::Octagon(std::istream& is) {
    std::cout << "Enter the octagon's vertexes:" << std::endl;
    is >> point_a;
    is >> point_b;
    is >> point_c;
    is >> point_d;
    is >> point_e;
    is >> point_f;
    is >> point_g;
    is >> point_h;
 //   std::cout << "The octagon is created" << std::endl;
}

void Octagon::Print(std::ostream& os) {
    std::cout << "Octagon: ";
    std::cout << point_a << ", ";
    std::cout << point_b << ", ";
    std::cout << point_c << ", ";
    std::cout << point_d << ", ";
    std::cout << point_e << ", ";
    std::cout << point_f << ", ";
    std::cout << point_g << ", ";
    std::cout << point_h << std::endl;
}

size_t Octagon::VertexesNumber() {
    size_t number = 8;
    return number;
}

Octagon& Octagon::operator = (const Octagon& other) {
  if (this == &other) return *this;
  point_a = other.point_a;
  point_b = other.point_b;
  point_c = other.point_c;
  point_d = other.point_d;
  point_e = other.point_e;
  point_f = other.point_f;
  point_g = other.point_g;
  point_h = other.point_h;
  return *this;
} 

Octagon& Octagon::operator == (const Octagon& other) {
  if (this == &other){
    std::cout << "Octagons are equal" << std::endl;
  } else {
    std::cout << "Octagons are not equal" << std::endl;
  } 
} 

Octagon::Octagon(std::shared_ptr<Octagon>&other ):Octagon(other->point_a, other->point_b,  other->point_c, other->point_d,  other->point_e, other->point_f, other->point_g, other->point_h){
}



double Octagon::Area() {
   double q = abs(point_a.X() * point_b.Y() + point_b.X() * point_c.Y() + poiny_c.X() * point_d.Y() + point_d.X() * point_e.Y() + point_e.X() * point_f.Y() + point_f.X() * point_g.Y() + point_g.X() * point_h.Y() + point_h.X() * point_a.Y() - point_b.X() * point_a.Y() - point_c.X() * point_b.Y() - point_d.X() * point_c.Y() - point_e.X() * point_d.Y() - point_f.X() * point_e.Y() - point_g.X() * point_f.Y() - point_h.X() * point_g.Y() - point_a.X() * point_h.Y());
   double s = q / 2;
   return s;

}

Octagon::Octagon(Point point_a1, Point point_b1,Point point_c1, Point point_d1, Point point_e1, Point point_f1, Point point_g1, point_h1): point_a(point_a1),point_b(point_b1),point_c(point_c1),point_d(point_d1),point_e(point_e1),point_f(point_f1),point_g(point_g1), point_h(point_h1) {
}

Octagon::~Octagon() {
}

std::ostream& operator<<(std::ostream& os,std::shared_ptr<Octagon>& p) {
  os << p->point_a << p->point_b << p->point_c << p->point_d << p->point_e << p->point_f<<p->point_g<<p->point_h;
  return os;
}
