#include "octagon.h"
#include <cmath>

    Octagon::Octagon() {
        a.X() == 0.0; a.Y() == 0.0;
        b.X() == 0.0; b.Y() == 0.0;
        c.X() == 0.0; c.Y() == 0.0;
        d.X() == 0.0; d.Y() == 0.0;
        e.X() == 0.0; e.Y() == 0.0;
        f.X() == 0.0; f.Y() == 0.0;
        g.X() == 0.0; g.Y() == 0.0;
        h.X() == 0.0; h.Y() == 0.0;
    }

    Octagon::Octagon(std::istream &InputStream) 
  {
      InputStream >> a;
      InputStream >> b;
      InputStream >> c;
      InputStream >> d;
      InputStream >> e;
      InputStream >> f;
      InputStream >> g;
      InputStream >> h;
      std:: cout << "Octagon that you wanted to create has been created" << std:: endl;
  }

  void Octagon::Print(std::ostream &OutputStream) {
      OutputStream << "Octagon: ";
      OutputStream << a << " " << b << " " << c << " " << d << " " << e <<" " << f <<" " << g <<" " << h << std:: endl;
      
  }

   size_t Octagon::VertexesNumber() {
       size_t number = 8;
       return number;
   }
 double Octagon:: Area() {
  double q = abs(point_a.X() * point_b.Y() + point_b.X() * point_c.Y() + poiny_c.X() * point_d.Y() + point_d.X() * point_e.Y() + point_e.X() * point_f.Y() + point_f.X() * point_g.Y() + point_g.X() * point_h.Y() + point_h.X() * point_a.Y() - point_b.X() * point_a.Y() - point_c.X() * point_b.Y() - point_d.X() * point_c.Y() - point_e.X() * point_d.Y() - point_f.X() * point_e.Y() - point_g.X() * point_f.Y() - point_h.X() * point_g.Y() - point_a.X() * point_h.Y());
   double s = q / 2;
   return s;
   }

   double Octagon:: GetArea() {
       return area;
   }

    Octagon::~Octagon() {
          std:: cout << "My friend, your pentagon has been deleted" << std:: endl;
      }

    bool operator == (Octagon& p1, Octagon& p2){
        if(p1.a == p2.a && p1.b == p2.b && p1.c == p2.c && p1.d == p2.d && p1.e == p2.e && p1.f == p2.f && p1.g == p2.g && p1.h == p2.h) {
            return true;
        }
        return false;
    }
    
    std::ostream& operator << (std::ostream& os, Octagon& p){
    os << "Octagon: ";
    os << p.a << p.b << p.c << p.d << p.e << p.f << p.g << p.h;
    os << std::endl;
    return os;
}
