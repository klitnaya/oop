#include "tlinked_list_item.h"
#include "octagon.h"
#include <iostream>

 HListItem:: HListItem(Octagon& octagon) {
    this->octagon = octagon;
    this->next = nullptr;
  
} 
std::ostream& operator<<(std::ostream& os,  HListItem& obj){
  os << "["<<obj.octagon << "]"<<std::endl;
  return os;
}
 HListItem::~ HListItem(){
}


