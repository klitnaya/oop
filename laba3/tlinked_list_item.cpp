#include "tlinked_list_item.h"
#include "octagon.h"
#include <iostream>

HListItem::HListItem(const std::shared_ptr<Octagon> &octagon) {
  this->octagon = octagon;
  this->next = nullptr;
}
std::ostream& operator<<(std::ostream& os,std::shared_ptr<HListItem>& obj) {
  os << "[" << obj->octagon << "]" << std::endl;
  return os;
}
HListItem::~HListItem() {
}


