#include "octagon.h"
#include <iostream>
#include <memory>
#include <cmath>

Octagon::Octagon(): a(0,0),b(0,0),c(0,0),d(0,0),e(0,0),f(0,0), g(0,0), h(0,0) {
} 
Octagon::Octagon(std::istream &is) {
    is >> a; 
    is >> b;
    is >> c;
    is >> d;
    is >> e;
    is >> f;
}
Octagon::Octagon(Point a1, Point b1,Point c1, Point d1, Point e1, Point f1, Point g1, Point h1): a(a1),b(b1),c(c1),d(d1),e(e1),f(f1), g(g1),h(h1) {
}
double Octagon::Area() {
    return 0.5*abs(a.x() * b.y() + b.x() * c.y() + c.x() *d.y() + d.x() * e.y() +e.x() * f.y() + f.x() * g.y() + g.x() * h.y() + h.x() * a.y() - b.x() * a.y() -c.x() * b.y() - d.x() * c.y() - e.x() * d.y() - f.x() * e.y() - g.x() * f.y() - h.x() * g.y() - a.x() * h.y());
}
Octagon::~Octagon() {
}
size_t Octagon::VertexesNumber() {
    return 8;
}
Octagon::Octagon(Octagon& other):Octagon(other.a,other.b,other.c,other.d,other.e,other.f, other.g, other.h) {
} 
Octagon& Octagon::operator = (const Octagon& other) {
  if (this == &other) return *this;
  a = other.a;
  b = other.b;
  c = other.c;
  d = other.d;
  e = other.e;
  f = other.f;
  g = other.g;
  h = other.h;
 
  return *this;
} 
Octagon& Octagon::operator == (const Octagon& other) {
  if (this == &other){
    std::cout << "Octagons are equal" << std::endl;
  } else {
    std::cout << "Octagons are not equal" << std::endl;
  } 
} 
std::ostream& operator<<(std::ostream& os, std::shared_ptr<Octagon>& h) {
  os << h->a << h->b << h->c << h->d << h->e << h->f << h->g << h->h;
  return os;
}