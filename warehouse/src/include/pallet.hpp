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
         * @brief Get the name of items on a pallet
         * 
         * @return std::string the name
         */
        std::string getItemName() const;

        /**
         * @brief Get the amount of items on a pallet
         * 
         * @return int the amount
         */
        int getItemCount() const;

        /**
         * @brief Get the capacity of the pallet
         * 
         * @return int 
         */
        int getItemCapacity() const;

        /**
         * @brief Get the amount of items that can still be added to the pallet
         * 
         * @return int (itemCapacity - itemCount)
         */
        int getRemainingSpace() const;

        /**
         * @brief Allocate an empty pallet to a new item type
         * 
         * @param itemName the new item type
         * @param itemCapacity the new capacity
         * 
         * @details Only succeeds when the pallet is empty
         * 
         * @return true when succeeded
         * @return false when unable to succeed
         */
        bool reallocateEmptyPallet(std::string itemName, int itemCapacity);

        /**
         * @brief Set the Item Capacity for a pallet
         * 
         * @param itemCapacity the new item capacity
         * 
         * @details Only succeeds when the old item capacity was unset (-1)
         * 
         * @return true when succeeded
         * @return false when unable to succeed
         */
        bool setItemCapacity(int itemCapacity);

        /**
         * @brief Set the Item Name for a pallet
         * 
         * @param itemName the new item name
         * 
         * @details Only succeeds when the old item name was unset/empty ("")
         * 
         * @return true when succeeded
         * @return false when unable to succeed
         */
        bool setItemName(std::string itemName);

        /**
         * @brief Reduce the itemCount by 1
         * 
         * @details Only succeeds when the item count was not 0
         * 
         * @return true when succeeded
         * @return false when unable to succeed
         */
        bool takeOne();

        /**
         * @brief Add 1 to the itemCount
         * 
         * @details Only succeeds when the item count was not equal to the item capacity
         * 
         * @return true when succeeded
         * @return false when unable to succeed
         */
        bool putOne();

        /**
         * @brief Check if itemCount is 0
         * 
         * @return true
         * @return false 
         */
        bool isEmpty() override;

        /**
         * @brief Check if itemCount is equal to itemCapacity
         * 
         * @return true 
         * @return false 
         */
        bool isFull() override;

        /**
         * @brief Print the info of a pallet
         * 
         * @param out 
         * @param pallet 
         * @return std::ostream& 
         */
        friend std::ostream& operator<<(std::ostream& out, const Pallet &pallet);
};