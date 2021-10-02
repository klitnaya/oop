#ifndef SQUARE_H
#define SQUARE_H

#include "figure.h"

class Square : public Figure {
public:
    Square(std::istream& is);

    size_t VertexesNumber();
    double Area();
    void Print(std::ostream& os);
    virtual ~Square();

private:
    Point point_a, point_b, point_c, point_d; //ïåðâàÿ âåðøèíà - ëåâàÿ íèæíÿÿ, äàëåå - ïî ÷àñîâîé ñòðåëêå
};

#endif // SQUARE_H