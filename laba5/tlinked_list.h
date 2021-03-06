#ifndef HLIST_H
#define HLIST_H
#include <iostream>
#include "hlist_item.h"
#include "octagon.h"
#include <memory>
#include "titerator.h"

template <class T> class TLinkedList {
public:
  TLinkedList();
  int size_of_list;
  size_t Length();
  std::shared_ptr<T>& First();
  std::shared_ptr<Octagon>& Last();
  std::shared_ptr<Octagon>& GetItem(size_t idx);
  bool Empty();
  TLinkedList(const std::shared_ptr<TLinkedList> &other);
  void InsertFirst(const std::shared_ptr<Octagon> &&octagon);
  void InsertLast(const std::shared_ptr<Octagon> &&octagon);
  void RemoveLast();
  void RemoveFirst();
  void Insert(const std::shared_ptr<Octagon> &&octagon, size_t position);
  void Remove(size_t position);
  void Clear();
  template <class A> friend std::ostream& operator<<(std::ostream& os, TLinkedList<A>& list);
  ~TLinkedList();
  Titerator<HListItem<T>, T> begin();
  Titerator<HListItem<T>, T> end();  
private:
  std::shared_ptr<HListItem<T>> front;
  std::shared_ptr<HListItem<T>> back;
};
#include "tlinkedlist.inl"
#endif //HList_H