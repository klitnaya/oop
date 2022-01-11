#ifndef HLISTITEM_H
#define HLISTITEM_H
#include <iostream>
#include "octagon.h"
#include <memory>

template <class T> class HListItem {
public:
  HListItem(const std::shared_ptr<Octagon> &octagon);
  template <class A> friend std::ostream& operator<<(std::ostream& os, HListItem<A> &obj);
  ~HListItem();
  std::shared_ptr<T> octagon;
  std::shared_ptr<HListItem<T>> next;
};
#include "hlist_item.inl"
#endif //HLISTITEM_H