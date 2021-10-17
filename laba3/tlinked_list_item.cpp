#include "tlinked_list_item.h"
#include "octagon.h"
#include <iostream>

 HListItem:: HListItem(std::shared_ptr<Octagon>& oc) {
    this->octagon = oc;
    this->next = nullptr;
  
} 
std::ostream& operator<<(std::ostream& os, std::shared_ptr<HListItem> obj){
  os << "["<<obj->octagon << "]"<<std::endl;
  return os;
}
 HListItem::~ HListItem(){
}


