#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "employee.hpp"
#include "shelf.hpp"

class Warehouse{
    public:
        /**
         * @brief a list of all employees
         */
        std::vector<Employee> employees;

        /**
         * @brief a list of all shelves
         */
        std::vector<Shelf> shelves;

        /**
         * @brief Empty constructor for warehouse
         * 
         * @details Does not generate shelves or employees
         */
        Warehouse();

        /**
         * @brief Add an employee to the warehouse staff
         * 
         * @param employee
         */
        void addEmployee(Employee employee);

        /**
         * @brief Add a shelf to the warehouse
         * 
         * @param shelf 
         */
        void addShelf(Shelf shelf);

        /**
         * @brief Sort a shelf so that the 4 pallets are in increasing order
         * 
         * @param shelf 
         * 
         * @details Only succeeds when there is an employee that is not busy and is forkliftcertified
         * 
         * @return true when succeeded
         * @return false when unable to rearrange
         */
        bool rearrangeShelf(Shelf &shelf);

        /**
         * @brief Pick an amount of certain items from the warehouse
         * 
         * @param itemName The item to pick
         * @param itemCount The amount needed
         * 
         * @details Only succeeds when there are enough items of the type or if all employees are busy
         * 
         * @return true when succeeded
         * @return false when unable to rearrange
         */
        bool pickItems(std::string itemName, int itemCount);
};