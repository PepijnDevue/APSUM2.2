#include <iostream>
#include <vector>
#include <string>
#include "include/warehouse.hpp"
#include "include/employee.hpp"
#include "include/shelf.hpp"
#include "include/pallet.hpp"

Warehouse::Warehouse(){
    shelves[0] = Shelf();
}

void Warehouse::addEmployee(Employee employee){
    employees.push_back(employee);
}

void Warehouse::addShelf(Shelf shelf){
    shelves.push_back(shelf);
}

bool Warehouse::rearrangeShelf(Shelf &shelf){
    for (unsigned int employeeIndex = 0; employeeIndex < employees.size(); employeeIndex++){
        if (!employees[employeeIndex].getBusy()){
            employees[employeeIndex].setBusy(true);
            bool sorted = false;
            while(!sorted){}
                for (unsigned int palletIndex = 0; palletIndex < 3; palletIndex++){
                    if (shelf.pallets[palletIndex].getItemCount() > shelf.pallets[palletIndex + 1].getItemCount()){
                        shelf.swapPallet(palletIndex, palletIndex+1);
                        break;
                    }
                    sorted = true;
                }
            employees[employeeIndex].setBusy(false);
            break;
        }
    }
}

bool Warehouse::pickItems(std::string itemName, int itemCount){
    for (unsigned int employeeIndex = 0; employeeIndex < employees.size(); employeeIndex++){
        if (!employees[employeeIndex].getBusy()){
            employees[employeeIndex].setBusy(true);
            for ()
            employees[employeeIndex].setBusy(false);
            break;
        }
    }
}