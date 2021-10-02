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

    
/*    Square square(std::cin);
    std::cout << "The number of square's vertexes: " << square.VertexesNumber() << std::endl;
    square.Print(std::cout);
    std::cout << "The area of the square: " << square.Area() << std::endl;
    std::cout << std::endl;

    Rectangle rectangle(std::cin);
    std::cout << "The number of rectangle's vertexes: " << rectangle.VertexesNumber() << std::endl;
    rectangle.Print(std::cout);
    std::cout << "The area of the rectangle: " << rectangle.Area() << std::endl;
    std::cout << std::endl;

    Trapezoid trapezoid(std::cin);
    std::cout << "The number of trapezoid's vertexes: " << trapezoid.VertexesNumber() << std::endl;
    trapezoid.Print(std::cout);
    std::cout << "The area of the trapezoid: " << trapezoid.Area() << std::endl;
*/
    return 0;
}