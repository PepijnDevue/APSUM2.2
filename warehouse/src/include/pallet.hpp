#include <iostream>
#include <string>
#include "icontainer.hpp"

class Pallet: public IContainer{
    private:
        int itemCount; //only mutable through taking and putting
        std::string itemName; //only mutable when empty
        int itemCapacity; // only mutable when empty
    public:
        Pallet(std::string itemName, int itemCapacity, int itemCount);
        Pallet();
        std::string getItemName();
        int getItemCount();
        int getRemainingSpace();
        bool reallocateEmptyPallet(std::string itemName, int itemCapacity);
        bool setItemCapacity(int itemCapacity);
        bool setItemName(std::string itemName);
        bool takeOne();
        bool putOne();
        bool isEmpty() override;
        bool isFull() override;
};