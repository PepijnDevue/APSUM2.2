#pragma once

#include <iostream>
#include <string>
#include "icontainer.hpp"

class Pallet: public IContainer{
    private:
        std::string itemName;
        int itemCapacity;
        int itemCount;
    public:
        /**
         * @brief Constructor
         * 
         * @param itemName 
         * @param itemCapacity 
         * @param itemCount 
         */
        Pallet(std::string itemName, int itemCapacity, int itemCount);

        /**
         * @brief Empty constructor
         * 
         * @details default values: itemName = "", itemCapacity = -1, itemCount = 0
         */
        Pallet();

        /**
         * @brief Get the Item Name object
         * 
         * @return std::string 
         */
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