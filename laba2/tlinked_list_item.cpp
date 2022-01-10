#include <iostream>
#include "tlinked_list_item.h"

HListItem::HListItem(const Octagon &octagon) {
  this->octagon = octagon;
  this->next = nullptr;
}
std::ostream& operator<<(std::ostream& os,HListItem& obj) {
  os << "[" << obj.octagon << "]" << std::endl;
  return os;
}
HListItem::~HListItem() {
}

