#include<iostream>
#include "octagon.h"
#include<memery>

class  HListItem {
public:
     HListItem(const std::shared_ptr<Octagon>& oc);
    friend std::ostream& operator<<(std::ostream& os,  std::shared_ptr<HListItem>& obj);
    ~ HListItem();
    std::shared_ptr<HListItem>* next;
    std::shared_ptr<Octagon> octagon;
    
};

