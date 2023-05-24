#include <iostream>
#include <vector>
#include "include/pallet.hpp"
#include "include/shelf.hpp"

Shelf::Shelf(){

    for(int i = 0; i<4; i++){
        pallets.push_back(Pallet());
    }
}

bool Shelf::swapPallet(int slot, int slot2){

    if(-1<slot && slot<4 && -1<slot2 && slot2<4 && slot != slot2){
        Pallet temp = pallets[slot];
        pallets[slot] = pallets[slot2];
        pallets[slot2] = temp;
        return true;

    }else{
        return false;
    }
}

bool Shelf::isEmpty(){
    for(int i = 0; i<4; i++){
        if(!pallets[i].isEmpty()){
            return false;
        }
    }
    return true;
}

bool Shelf::isFull(){
    for(int i = 0; i<4; i++){
        if(!pallets[i].isFull()){
            return false;
        }
    }
    return true;
}

std::ostream& operator<<(std::ostream& out, const Shelf &shelf){
    out << "pallet1: " << shelf.pallets[0] << "\npallet2: " << shelf.pallets[1] << "\npallet3: " << shelf.pallets[2] << "\npallet4: " << shelf.pallets[3];
    return out;
}