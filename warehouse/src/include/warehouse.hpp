#include <iostream>
#include <vector>
#include <string>
#include "employee.hpp"
#include "shelf.hpp"

class Warehouse{
    private:
        std::vector<Employee> employees;
        std::vector<Shelf> shelves;
    public:
        Warehouse();
        void addEmployee(Employee employee);
        void addShelf(Shelf shelf);
        bool rearrangeShelf(Shelf &shelf);
        bool pickItems(std::string itemName, int itemCount);
};