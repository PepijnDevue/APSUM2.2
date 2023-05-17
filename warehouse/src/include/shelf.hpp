#include <iostream>
#include <vector>
#include "pallet.hpp"

class Shelf{
    private:
        std::vector<Pallet> pallets;
    public:
        Shelf();
        bool swapPallet(int slot, int slot2);
};