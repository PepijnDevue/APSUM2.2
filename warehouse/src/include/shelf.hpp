#pragma once

#include <iostream>
#include <vector>
#include "pallet.hpp"
#include "icontainer.hpp"

class Shelf: public IContainer{
    public:
        /**
         * @brief Every shelf has 4 pallets
         */
        std::vector<Pallet> pallets;

        /**
         * @brief Empty constructor
         * 
         * @details Defaults with 4 empty pallets
         */
        Shelf();

        /**
         * @brief Swap two pallets on the same shelf
         * 
         * @param slot the slot of the first pallet
         * @param slot2 the slot of the second pallet
         * 
         * @details Only succeeds when the slots exist and when they are not the same slots
         * 
         * @return true when succeeded
         * @return false when unable to succeed
         */
        bool swapPallet(int slot, int slot2);

        /**
         * @brief Check if all pallets on the shelf are empty
         * 
         * @return true when they are all empty
         * @return false when they are not all empty
         */
        bool isEmpty() override;

        /**
         * @brief Check if all pallets on the shelf are full
         * 
         * @return true when all pallets are full
         * @return false when not all pallets are full
         */
        bool isFull() override;
};