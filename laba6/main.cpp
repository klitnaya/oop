#include <iostream>
#include "octagon.h"
#include "TLinkedList.h"
#include "TLinkedListItem.h"
#include "TAllocatorBlock.h"

int main () {
    //lab1
    Octagon a (std::cin);
    std:: cout << "The area of your figure is : " << a.Area() << std:: endl;

    Octagon b (std::cin);
    std:: cout << "The area of your figure is : " << b.Area() << std:: endl;

    Octagon c (std::cin);
    std:: cout << "The area of your figure is : " << c.Area() << std:: endl;

 
    //lab8
    TLinkedList list;
    std:: cout << "Is list empty? " << list.Empty() << std:: endl;
    list.InsertFirst(a);
    std:: cout << "And now, is list empty? " << list.Empty() << std:: endl;
    list.InsertLast(b);
    list.InsertLast(c);
    std:: cout << "The length of your list is: " << list.Length() << std:: endl;
    std:: cout << list;
    return 0;
}
