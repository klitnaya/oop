#include<iostream>
#include "octagon.h"

class  HListItem {
public:
     HListItem(const Octagon& octagon);
    friend std::ostream& operator<<(std::ostream& os,  HListItem& obj);
    ~HListItem();
    HListItem* next;
    Octagon octagon;
    
};

