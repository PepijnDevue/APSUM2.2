#include <iostream>
#include <vector>
#include <string>
#include "include/warehouse.hpp"
#include "include/employee.hpp"
#include "include/shelf.hpp"
#include "include/pallet.hpp"

Warehouse::Warehouse(){
    // shelves.push_back(Shelf());
}

void Warehouse::addEmployee(Employee employee){
    employees.push_back(employee);
}

void Warehouse::addShelf(Shelf shelf){
    shelves.push_back(shelf);
}

bool Warehouse::rearrangeShelf(Shelf &shelf){
    for (unsigned int employeeIndex = 0; employeeIndex < employees.size(); employeeIndex++){
        if (!employees[employeeIndex].getBusy() && employees[employeeIndex].getForkliftCertificate()){
            employees[employeeIndex].setBusy(true);
            while(true){
                bool sorted_check = true;
                for (unsigned int palletIndex = 0; palletIndex < 3; palletIndex++){
                    if (shelf.pallets[palletIndex].getItemCount() > shelf.pallets[palletIndex + 1].getItemCount()){
                        shelf.swapPallet(palletIndex, palletIndex+1);
                        sorted_check = false;
                        break;
                    }
                }
                if (sorted_check){
                    employees[employeeIndex].setBusy(false);
                    return true;
                }
            }
        }
    }
    return false;
}

bool Warehouse::pickItems(std::string itemName, int itemCount){
    for (unsigned int employeeIndex = 0; employeeIndex < employees.size(); employeeIndex++){
        if (!employees[employeeIndex].getBusy()){
            employees[employeeIndex].setBusy(true);
            for (unsigned int shelfIndex = 0; shelfIndex < shelves.size(); shelfIndex++){
                for (unsigned int palletIndex = 0; palletIndex < 4; palletIndex++){
                    Pallet currentPallet = shelves[shelfIndex].pallets[palletIndex];
                    if (currentPallet.getItemName() == itemName){
                        while(currentPallet.takeOne() && itemCount > 0){
                            itemCount--;
                        }
                    }
                    if (itemCount == 0){
                        return true;
                    }
                }
            }
            employees[employeeIndex].setBusy(false);
            break;
        }
    }
    return false;
}