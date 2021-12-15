#include <iostream>
#include "Money.h"

int main(){
    Money c(std::cin);
    Money a(10, 6);
    Money b(12, 5);
    std::cout << "Money objects"<< a << b << c << std::endl;
    std::cout << "Sum: " << a+b << std::endl;
    std::cout << "Division of residues " << a/b << std::endl;
    std::cout << "Multiplication of residuals " << a*b << std::endl;
    std::cout << "Sum " << c+b << std::endl;
    std::cout << "Operator -- : " << --a;
    std::cout << "Operator ++ : " << ++a;
}
