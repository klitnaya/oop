#include <iostream>
#include "triangle.h"
#include "octagon.h"
#include "square.h"

using namespace std;

int main()
{
    Octagon a(std::cin);
    std::cout<<"The area of your octagon is " << a.Area()<<endl;
    std::cout<<"The amount verices in your figure is "<< a.VertexesNumber()<<endl;
    a.Print();

    Triangle b(std::cin);
    std::cout<<"The area of your triangle is " << b.Area()<<endl;
    std::cout<<"The amount verices in your figure is "<< b.VertexesNumber()<<endl;
    b.Print();

    Square c(std::cin);
    std::cout<<"The area of your square is " << c.Area()<<endl;
    std::cout<<"The amount verices in your figure is "<< c.VertexesNumber()<<endl;
    c.Print();

    return 0;
}
