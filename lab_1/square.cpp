#include "square.h"

Square::Square(std::istream& is) {
    std::cout << "Enter the square's vertexes:" << std::endl;
    is >> point_a;
    is >> point_b;
    is >> point_c;
    is >> point_d;
    std::cout << "The square is created" << std::endl;
}

void Square::Print(std::ostream& os) {
    std::cout << "Square: ";
    std::cout << point_a << ", ";
    std::cout << point_b << ", ";
    std::cout << point_c << ", ";
    std::cout << point_d << std::endl;
}

size_t Square::VertexesNumber() {
    size_t number = 4;
    return number;
}

double Square::Area() {
    try {
        double len_a = point_b.dist(point_a);
        if (len_a < 0) {
            throw "The length of the side is < 0";
        }
        return pow(len_a, 2);
    }
    catch (const char* exception) {
        std::cerr << "Error: " << exception << std::endl;
    }
}

Square::~Square() {
    std::cout << "The square is deleted" << std::endl;
}