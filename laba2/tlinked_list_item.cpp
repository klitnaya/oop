#include "tlinked_list_item.h"
#include "octagon.h"
#include <iostream>

TLinkedList::TLinkedList(Octagon& oc) {
    this->octagon = oc;
    //this->prev = nullptr;
    this->next = nullptr;
    //std::cout << "linked list created" << std::endl;
} 
std::ostream& operator<<(std::ostream& os, TLinkedList obj){
  os << "{"<<obj.octagon << "}"<<std::endl;
  return os;
}
TLinkedList::~TLinkedList(){
}


