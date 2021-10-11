#ifndef TLINKED_LIST_ITEM_H
#defline TLINKED_LIST_ITEM_H
#include "octagon.h"

class TLinkedList {
public:
    TLinkedList(const Octagon& oc);
    friend std::ostream& operator<<(std::ostream& os, TLinkedList& obj);
    ~TLinkedList();
    //TLinkedList* prev;
    TLinkedList* next;
    Octagon octagon;
    
};

#endif //TLINKED_LIST_ITEM_H