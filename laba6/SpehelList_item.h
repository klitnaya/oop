#ifndef SPEHELLIST_ITEM_H
#define SPEHELLIST_ITEM_H

#include <memory>

template<typename T> 
class SpehelList_item {
    public:
        SpehelList_item(): data(0) {};
        SpehelList_item(T t): data(t){};
        std::shared_ptr<SpehelList_item<T>> Get_next(){
            return next;
        };
        void Set_next(std::shared_ptr<SpehelList_item<T>> next_){
            next = next_;
        };
        T Get_data(){
            return data;
        }
    private:
        std::shared_ptr<SpehelList_item<T>> next = nullptr;
        T data;
};

#endif