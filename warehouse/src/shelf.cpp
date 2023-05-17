#include <iostream>
#include <vector>
#include "pallet.hpp"
#include "shelf.hpp"

Shelf::Shelf(){
    for(int i; i<4; i++){
        pallets[i] = Pallet();
    }
}
bool Shelf::swapPallet(int slot, int slot2){
    if(-1<slot<4 && -1<slot2<-4 && slot != slot2){
        Pallet temp = pallets[slot];
        pallets[slot] = pallets[slot2];
        pallets[slot2] = temp;
        return true;
    }else{
        return false;
    }
}
bool Shelf::isEmpty(){
    for(int i; i<4; i++){
        if(!pallets[i].isEmpty()){
            return false;
        }
    }
    return true;
}
bool Shelf::isFull(){
    for(int i; i<4; i++){
        if(!pallets[i].isFull()){
            return false;
        }
    }
    return true;
}