#ifdef TLINKED_LIST_H
#define TLINKED_LIST_H
#include <iostream>
#include "tlinked_list_item.h"
#include"octagon.h"

class TLinkedList {
public:
  TLinkedList();
  int size_of_list;
  size_t Length();
  std::shared_ptr<Octagon>& First();
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
  friend std::ostream& operator<<(std::ostream& os, TLinkedList& list);
  ~TLinkedList(); 
private:
  std::shared_ptr<HListItem> front;
  std::shared_ptr<HListItem> back;
};
#endif //TLINKED_LIST_H
