#include <iostream>
#include "point.h"
#include "octagon.h"
#include "triangle.h"
#include "square.h"

using namespace std;

int main()
{
    
    Point 
    Octagon a;
    std::cout<<"The area of your octagon is " << a.Area()<<endl;
    std::cout<<"The amount verices in your figure is "<< a.VertexesNumber()<<endl;
    a.Print();

    Triangle b;
    std::cout<<"The area of your triangle is " << b.Area()<<endl;
    std::cout<<"The amount verices in your figure is "<< b.VertexesNumber()<<endl;
    b.Print();

    Square c;
    std::cout<<"The area of your square is " << c.Area()<<endl;
    std::cout<<"The amount verices in your figure is "<< c.VertexesNumber()<<endl;
    c.Print();

    return 0;
}
