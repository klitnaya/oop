#include <iostream>
#include "triangle.h"//"square.h"
#include "octagon.h"//"rectangle.h"
#include "square.h"//"trapezoid.h"

int main()
{
    Octagon octagon(std::cin);
    std::cout << "The number of octagon's vertexes: " << octagon.VertexesNumber() << std::endl;
    octagon.Print(std::cout);
    std::cout << "The area of the octagon: " << octagon.Area() << std::endl;
    std::cout << std::endl;

    Triangle tr(std::cin);
    std::cout << "The number of triangle's vertexes: " << tr.VertexesNumber() << std::endl;
    tr.Print(std::cout);
    std::cout << "The area of the triangle: " << tr.Area() << std::endl;
    std::cout << std::endl;

    Square s(std::cin);
    std::cout << "The number of square's vertexes: " << s.VertexesNumber() << std::endl;
    s.Print(std::cout);
    std::cout << "The area of the square: " << s.Area() << std::endl;
    std::cout << std::endl;

    return 0;
}