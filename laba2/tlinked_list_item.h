#include<iostream>
#include "octagon.h"

class  HListItem {
public:
     HListItem(const Octagon& oc);
    friend std::ostream& operator<<(std::ostream& os,  HListItem& obj);
    ~ HListItem();
    HListItem* next;
    Octagon octagon;
    
};

