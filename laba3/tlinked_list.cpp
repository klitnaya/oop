#include <iostream>
#include "tlinkedlist.h"
 
TLinkedList::TLinkedList() {
  size_of_list = 0;
  std::shared_ptr<HListItem> first;
  std::shared_ptr<HListItem> last;
  std::cout << "Octagon List created" << std::endl; 
}
size_t TLinkedList::Length() {
  return size_list;
}
void TLinkedList::Empty() {
  if (size_list == 0){
    std::cout << "Octagon List is empty" << std::endl;
  } else {
    std::cout << "Octagon List is not empty" << std::endl;
  }
}
std::shared_ptr<Octagon>& TLinkedList::GetItem(size_t idx){
  int k = 0;
  HListItem* obj = front;
  while (k != idx){
    k++;
    obj = obj->next;
  }
  return &obj->hexagon;
}
std::shared_ptr<HListItem>& TLinkedList::First() {
  return front;
}
std::shared_ptr<HListItem>& TLinkedList::Last() {
  return back;
}
void TLinkedList::InsertLast(const std::shared_ptr<Octagon> &&octagon) {
  std::shared_ptr<HListItem> obj (new HListItem(octagon));
  if(size_list == 0) {
    front = obj;
    back = obj;
    size_list++;
    return;
  }
  back->next = obj;
  back = obj;
  obj->next = nullptr;
  size_list++;
}
void TLinkedList::RemoveLast() {
  if (size_of_list == 0) {
    std::cout << "Octagon does not pop_back, because the Octagon List is empty" << std:: endl;
  } else {
    if (front == back) {
      RemoveFirst();
      size_of_list--;
      return;
    }
    std::shared_ptr<HListItem>* prev_del = front;
    while (prev_del->next != back) {
      prev_del = prev_del->next;
    }
    prev_del->next = nullptr;
    //delete back;
    back = prev_del;
    size_of_list--;
    } 
}
void TLinkedList::InsertFirst(const Octagon &&octagon) {
    std::shared_ptr<HListItem> obj ( new HListItem(octagon));
    if(size_of_list == 0) {
      front = obj;
      back = obj;
    } else {
      obj->next = front;
      front = obj;
    }
    size_of_list++;
}
void TLinkedList::RemoveFirst() {
    if (size_of_list == 0) {
      std::cout << "Octagon does not pop_front, because the Octagon List is empty" << std:: endl;
    } else {
    std::shared_ptr<HListItem> del = front;
    front = del->next;
    //delete del;
    size_of_list--;
    }
}
void TLinkedList::Insert(const std::shared_ptr<Octagon> &&octagon,size_t position) {
  if (position <0) {
    std::cout << "Position < zero" << std::endl;
  } else if (position > size_of_list) {
    std::cout << " Position > size_of_list" << std::endl;
  } else {
    std::shared_ptr<HListItem> obj ( new HListItem(octagon));
    if (position == 0) {
      front = obj;
      back = obj;
    } else {
      int k = 0;
      std::shared_ptr<HListItem> prev_insert = front;
      std::shared_ptr<HListItem> next_insert;
      while(k+1 != position) {
        k++;
        prev_insert = prev_insert->next;
      }
      next_insert = prev_insert->next;
      prev_insert->next = obj;
      obj->next = next_insert;
    }
    size_of_list++;
  }
}
void TLinkedList::Remove(size_t position) {
  if ( position > size_of_list ) {
    std:: cout << "Position " << position << " > " << "size " << size_of_list << " Not correct erase" << std::endl;
  } else if (position < 0) {
    std::cout << "Position < 0" << std::endl;
  } else {
    if (position == 0) {
      RemoveFirst();
    } else {
      int k = 0;
      std::shared_ptr<HListItem> prev_erase = front;
      std::shared_ptr<HListItem> next_erase;
      std::shared_ptr<HListItem> del;
      while( k+1 != position) {
        k++;
        prev_erase = prev_erase->next;
      }
      next_erase = prev_erase->next;
      del = prev_erase->next;
      next_erase = del->next;
      //delete del;
      prev_erase->next = next_erase;
    }
    size_of_list--;
  }
}
void TLinkedList::Clear() {
  std::shared_ptr<HListItem> del = front;
  std::shared_ptr<HListItem> prev_del;
  if(size_of_list !=0 ) {
    while(del->next != nullptr) {
      prev_del = del;
      del = del->next;
      //delete prev_del;
    }
    //delete del;
    size_of_list = 0;
  } 
  size_of_list = 0;
  std::shared_ptr<HListItem> front;
  std::shared_ptr<HListItem> back;
}
std::ostream& operator<<(std::ostream& os, TLinkedList& hl) {
  if (hl.size_of_list == 0) {
    os << "The octagon list is empty, so there is nothing to output" << std::endl;
  } else {
    os << "Print Octagon List" << std::endl;
    std::shared_ptr<HListItem> obj = hl.front;
    while(obj != nullptr) {
      if (obj->next != nullptr) {
        os << obj->octagon << " " << "," << " ";
        obj = obj->next;
      } else {
        os << obj->octagon;
        obj = obj->next;
      }
    }
    os << std::endl;
  }
  return os;
}
TLinkedList::~TLinkedList() {
  std::shared_ptr<HListItem> del = front;
  std::shared_ptr<HListItem> prev_del;
  if(size_of_list !=0 ) {
    while(del->next != nullptr) {
      prev_del = del;
      del = del->next;
      //delete prev_del;
    }
    //delete del;
    size_of_list = 0;
    std::cout << "Octagon List deleted" << std::endl;
  } 
}
