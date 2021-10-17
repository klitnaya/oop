#include "tlinked_list_item.h"
#include "octagon.h"
#include <iostream>

 HListItem:: HListItem(Octagon& oc) {
    this->octagon = oc;
    this->next = nullptr;
  
} 
std::ostream& operator<<(std::ostream& os,  HListItem obj){
  os << "["<<obj.octagon << "]"<<std::endl;
  return os;
}
 HListItem::~ HListItem(){
}


