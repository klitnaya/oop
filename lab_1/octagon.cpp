#include "octagon.h"
#include <cmath>

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
    std::cout << "The octagon is created" << std::endl;
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

double Octagon::Area() {
   double q = abs(point_a.X() * point_b.Y() + point_b.X() * point_c.Y() + poiny_c.X() * point_d.Y() + point_d.X() * point_e.Y() + point_e.X() * point_f.Y() + point_f.X() * point_g.Y() + point_g.X() * point_h.Y() + point_h.X() * point_a.Y() - point_b.X() * point_a.Y() - point_c.X() * point_b.Y() - point_d.X() * point_c.Y() - point_e.X() * point_d.Y() - point_f.X() * point_e.Y() - point_g.X() * point_f.Y() - point_h.X() * point_g.Y() - point_a.X() * point_h.Y());
   double s = q / 2;
   return s;

}

Octagon::~Octagon() {
    std::cout << "The octagon is deleted" << std::endl;
}