#include "octagon.h"
#include "point.h"
#include <cmath>

Octagon::Octagon(std:: isream &InputStream)

 {
  //cords_.assign(8, Point());
  InputStream >> a;
  InputStream >> b;
  InputStream >> c;
  InputStream >> d;
  InputStream >> e;
  InputStream >> f;
  InputStream >> g;
  InputStream >> h;
  std::cout << " Octagon was created" << std::endl;
}

size_t VertexesNumber(){
  size_t num = 8;
  return num;
}

void Octagon::Print(std::ostream& os) {
    os << a << ", ";
    os << b << ", ";
    os << c << ", ";
    os << d << ", ";
    os << e << ", ";
    os << f << ", ";
    os << g << ", ";
    os << h << std::endl;
}


double Octagon::Area() {
   double q = abs(a.X() * b.Y() + b.X() * c.Y() + c.X() * d.Y() + d.X() * e.Y() + e.X() * f.Y() + f.X() * g.Y() + g.X() * h.Y() + h.X() * a.Y() - b.X() * a.Y() - c.X() * b.Y() - d.X() * c.Y() - e.X() * d.Y() - f.X() * e.Y() - g.X() * f.Y() - h.X() * g.Y() - a.X() * h.Y());
   double s = q / 2;
   return s;
   }


Octagon::~Octagon() {
    std::cout << "Octagon deleted" << std::endl;
}
