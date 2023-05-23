#include <iostream>
#include "src/include/warehouse.hpp"
#include "src/include/pallet.hpp"
#include <vector>

int main(void){
    Warehouse warehouse = Warehouse();
    
    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Books", 100, 40), 
        Pallet("Boxes", 100, 10), 
        Pallet("Books", 100, 20), 
        Pallet("Books", 100, 20)
    };

    Shelf shelf2 = Shelf();
    shelf2.pallets = {
        Pallet("Books", 100, 15), 
        Pallet("Boxes", 100, 20), 
        Pallet("Books", 100, 5), 
        Pallet("Boxes", 100, 30)
    };

    Shelf shelf3 = Shelf();
    shelf3.pallets = {
        Pallet("Toy Bears", 100, 20), 
        Pallet("Toy Bears", 100, 10), 
        Pallet(), 
        Pallet("Toy Bears", 100, 30)
    };
        
    warehouse.addShelf(shelf1);
    warehouse.addShelf(shelf2);
    warehouse.addShelf(shelf3);

    warehouse.addEmployee(Employee("Bob", true));
    warehouse.employees[0].setBusy(true);

    warehouse.addEmployee(Employee("Henk", false));

    warehouse.addEmployee(Employee("Sjon", true));

    std::cout << warehouse.rearrangeShelf(warehouse.shelves[2]) << std::endl;

    std::cout << warehouse.pickItems("Boxes", 35) << std::endl;
}