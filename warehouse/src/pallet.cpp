#include <iostream>
#include <string>
#include "include/pallet.hpp"

Pallet::Pallet(std::string itemName, int itemCapacity, int itemCount): itemName(itemName), itemCapacity(itemCapacity), itemCount(itemCount){};
Pallet::Pallet(){
    itemCount = 0;
    itemName = "";
    itemCapacity = -1;
}
std::string Pallet::getItemName(){
    return itemName;
}
int Pallet::getItemCount(){
    return itemCount;
}
int Pallet::getRemainingSpace(){
    return itemCapacity-itemCount;
}
bool Pallet::reallocateEmptyPallet(std::string itemName, int itemCapacity){
    if(itemCount == 0){
        this->itemName = itemName;
        this->itemCapacity = itemCapacity;
        return true;
    }else{
        return false;
    }
}
bool Pallet::setItemCapacity(int itemCapacity){
    if(this->itemCapacity == -1){
        this->itemCapacity = itemCapacity;
        return true;
    }else{
        return false;
    }
}
bool Pallet::setItemName(std::string itemName){
    if(this->itemName == ""){
        this->itemName = itemName;
        return true;
    }else{
        return false;
    }
}
bool Pallet::takeOne(){
    if(itemCount > 0){
        itemCount--;
        return true;
    }else{
        return false;
    }
}
bool Pallet::putOne(){
    if(itemCount < itemCapacity){
        itemCount++;
        return true;
    }else{
        return false;
    }
}
bool Pallet::isEmpty(){
    return(itemCount == 0);
}
bool Pallet::isFull(){
    return(itemCount == itemCapacity);
}