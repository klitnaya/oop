#include <iostream>
#include "triangle.h"
#include "octagon.h"
#include "square.h"

int main(){
  TLinkedList tlinkedlist;
  tlinkedlist.Empty();
  tlinkedlist.InsertLast(Octagon(Point(1,2),Point(2,3),Point(3,4),Point(5,6),Point(7,8),Point(9,10), Point(11,12), Point(12,13)));
  tlinkedlist.InsertLast(Octagon(Point(13,14),Point(14,15),Point(15,16),Point(16,17),Point(17,18),Point(18,19),Point(19,20),Point(20,21)));
  tlinkedlist.InsertLast(Hexagon(Point(17,18),Point(18,19),Point(19,20),Point(20,21),Point(21,22),Point(23,24), Point(25,26),Point(27,28)));
  tlinkedlist.InsertLast(Hexagon(Point(17,18),Point(18,19),Point(19,20),Point(20,21),Point(21,22),Point(23,24), Point(25,26),Point(27,28)));
  std::cout << tlinkedlist;
  tlinkedlist.RemoveLast();
  tlinkedlist.Insert(Octagon(Point(1,1),Point(2,3),Point(3,4),Point(5,6),Point(7,8),Point(9,10), Point(11,12),Point(13,18)),2);
  tlinkedlist.Empty();
  tlinkedlist.Remove(2);
  std::cout << tlinkedlist;
  tlinkedlist.Clear();
  return 0;
}