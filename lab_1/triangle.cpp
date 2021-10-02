#include "triangle.h"

Triangle::Triangle(std::istream& is) {
    std::cout << "Enter the triangle's vertexes:" << std::endl;
    is >> point_a;
    is >> point_b;
    is >> point_c;
    std::cout << "The triangle is created" << std::endl;
}

void Triangle::Print(std::ostream& os) {
    std::cout << "Triangle: ";
    std::cout << point_a << ", ";
    std::cout << point_b << ", ";
    std::cout << point_c << std::endl;
}

size_t Triangle::VertexesNumber() {
    size_t number = 3;
    return number;
}

double Trapezoid::Area() {
    double p = 0.5*abs((point_b.X()-point_a.X())*(point_c.Y()-point_a.Y())-(point_c.X()-point_a.X()*(point_b.Y()-point_a.Y())));
    return p;

}

Triangle::~Triangle() {
    std::cout << "The triangle is deleted" << std::endl;
}