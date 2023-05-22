#pragma once

#include <iostream>
#include <vector>
#include "pallet.hpp"
#include "icontainer.hpp"

class Shelf: public IContainer{
    public:
        std::vector<Pallet> pallets;//max len of 4
        Shelf();
        bool swapPallet(int slot, int slot2);
        bool isEmpty() override;
        bool isFull() override;
};