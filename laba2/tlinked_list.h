#define HLIST_H
#ifdef HLIST_H

#include <iostream>
#include "tlinked_list_item.h"
#include "octagon.h"

class TLinkedList {
public:
  TLinkedList();
  int size_of_list;
  size_t Length();
  bool Empty();
  Octagon& First();
  Octagon& Last();
  TLinkedList(const TLinkedList& other);
  Octagon& GetItem(size_t idx);
  void InsertFirst(const Octagon &&octagon);
  void InsertLast(const Octagon &&octagon);
  void RemoveLast();
  void RemoveFirst();
  void Insert(const Octagon &&octagon, size_t position);
  void Remove(size_t position);
  void Clear();
  friend std::ostream& operator<<(std::ostream& os, TLinkedList& list);
  ~TLinkedList(); 
private:
  HListItem *front;
  HListItem *back;
};

#endif //HList_H