#ifdef TLINKED_LIST_H
#define TLINKED_LIST_H
#include "tlinked_list_item.h"
#include"octagon.h"

class TLinkedList {
public:
 TLinkedList();
 int size_of_list;
 void Lenght();
 void empty();
 std::shared_ptr<TLinkedList>& First();
 std::shared_ptr<TLinkedList>& Last();
 std::shared_ptr<Octagon>& GetItem(size_t idx);
 void Empty();
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
 std::shared_ptr<TLinkedList> front;
 std::shared_ptr<TLinkedList> back;
};
#endif //TLINKED_LIST_H
