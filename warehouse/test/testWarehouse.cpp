#include "include/catch.hpp"

#include "../src/include/warehouse.hpp"
#include "../src/include/pallet.hpp"
#include <iostream>

///////////////////////////////////////////////////////////////
//             Warehouse::pickItems test cases               //
///////////////////////////////////////////////////////////////
TEST_CASE("No forklift employee", "Warehouse::pickItems"){
    // Construct empty warehouse and add a shelf with 2 types of items and an employee
    Warehouse warehouse = Warehouse();
    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Pencils", 100, 2),
        Pallet("Books", 100, 30),
        Pallet("Books", 100, 20),
        Pallet("Pencils", 100, 20)
    };
    warehouse.addShelf(shelf1);
    Employee employee = Employee("Henk", false);
    warehouse.addEmployee(employee);


    // Check if there are no items taken yet
    REQUIRE(warehouse.shelves[0].pallets[0].getItemCount() == 2);
    REQUIRE(warehouse.shelves[0].pallets[1].getItemCount() == 30);
    REQUIRE(warehouse.shelves[0].pallets[2].getItemCount() == 20);
    REQUIRE(warehouse.shelves[0].pallets[3].getItemCount() == 20);

    // Try to pick items
    bool succesful = warehouse.pickItems("Pencils", 20);

    // Check if succeeded
    REQUIRE(succesful);

    // Check if items were taken
    REQUIRE(warehouse.shelves[0].pallets[0].getItemCount() == 0);
    REQUIRE(warehouse.shelves[0].pallets[1].getItemCount() == 30);
    REQUIRE(warehouse.shelves[0].pallets[2].getItemCount() == 20);
    REQUIRE(warehouse.shelves[0].pallets[3].getItemCount() == 2);
}

TEST_CASE("Busy employee", "Warehouse::pickItems"){
    // Construct empty warehouse and add a shelf with 2 types of items and an employee
    Warehouse warehouse = Warehouse();
    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Pencils", 100, 2),
        Pallet("Books", 100, 30),
        Pallet("Books", 100, 20),
        Pallet("Pencils", 100, 20)
    };
    warehouse.addShelf(shelf1);
    Employee employee = Employee("Henk", true);
    employee.setBusy(true);
    warehouse.addEmployee(employee);


    // Check if there are no items taken yet
    REQUIRE(warehouse.shelves[0].pallets[0].getItemCount() == 2);
    REQUIRE(warehouse.shelves[0].pallets[1].getItemCount() == 30);
    REQUIRE(warehouse.shelves[0].pallets[2].getItemCount() == 20);
    REQUIRE(warehouse.shelves[0].pallets[3].getItemCount() == 20);

    // Try to pick items
    bool succesful = warehouse.pickItems("Pencils", 20);

    // Check if succeeded
    REQUIRE_FALSE(succesful);

    // Check if items were taken
    REQUIRE(warehouse.shelves[0].pallets[0].getItemCount() == 2);
    REQUIRE(warehouse.shelves[0].pallets[1].getItemCount() == 30);
    REQUIRE(warehouse.shelves[0].pallets[2].getItemCount() == 20);
    REQUIRE(warehouse.shelves[0].pallets[3].getItemCount() == 20);
}

TEST_CASE("Second shelf", "Warehouse::pickItems"){
    // Construct empty warehouse and add 2 shelves with 2 types of items and an employee
    Warehouse warehouse = Warehouse();
    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Pencils", 100, 2),
        Pallet("Books", 100, 30),
        Pallet("Books", 100, 20),
        Pallet("Pencils", 100, 20)
    };
    Shelf shelf2 = Shelf();
    shelf2.pallets = {
        Pallet("Books", 100, 30),
        Pallet("Books", 100, 20),
        Pallet("Pencils", 100, 10),
        Pallet("Books", 100, 40)
    };
    warehouse.addShelf(shelf1);
    warehouse.addShelf(shelf2);
    warehouse.addEmployee(Employee("Henk", true));

    // Check if there are no items taken yet
    REQUIRE(warehouse.shelves[0].pallets[0].getItemCount() == 2);
    REQUIRE(warehouse.shelves[0].pallets[1].getItemCount() == 30);
    REQUIRE(warehouse.shelves[0].pallets[2].getItemCount() == 20);
    REQUIRE(warehouse.shelves[0].pallets[3].getItemCount() == 20);
    REQUIRE(warehouse.shelves[1].pallets[0].getItemCount() == 30);
    REQUIRE(warehouse.shelves[1].pallets[1].getItemCount() == 20);
    REQUIRE(warehouse.shelves[1].pallets[2].getItemCount() == 10);
    REQUIRE(warehouse.shelves[1].pallets[3].getItemCount() == 40);

    // Try to pick items
    bool succesful = warehouse.pickItems("Pencils", 25);

    // Check if it succeeded
    REQUIRE(succesful);

    // Check if items were taken
    REQUIRE(warehouse.shelves[0].pallets[0].getItemCount() == 0);
    REQUIRE(warehouse.shelves[0].pallets[1].getItemCount() == 30);
    REQUIRE(warehouse.shelves[0].pallets[2].getItemCount() == 20);
    REQUIRE(warehouse.shelves[0].pallets[3].getItemCount() == 0);
    REQUIRE(warehouse.shelves[1].pallets[0].getItemCount() == 30);
    REQUIRE(warehouse.shelves[1].pallets[1].getItemCount() == 20);
    REQUIRE(warehouse.shelves[1].pallets[2].getItemCount() == 7);
    REQUIRE(warehouse.shelves[1].pallets[3].getItemCount() == 40);
}

TEST_CASE("Enough items", "Warehouse::pickItems"){
    // Construct empty warehouse and add a shelf with 2 types of items and an employee
    Warehouse warehouse = Warehouse();
    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Pencils", 100, 2),
        Pallet("Books", 100, 30),
        Pallet("Books", 100, 20),
        Pallet("Pencils", 100, 20)
    };
    warehouse.addShelf(shelf1);
    warehouse.addEmployee(Employee("Henk", true));

    // Check if there are no items taken yet
    REQUIRE(warehouse.shelves[0].pallets[0].getItemCount() == 2);
    REQUIRE(warehouse.shelves[0].pallets[1].getItemCount() == 30);
    REQUIRE(warehouse.shelves[0].pallets[2].getItemCount() == 20);
    REQUIRE(warehouse.shelves[0].pallets[3].getItemCount() == 20);

    // Try to pick items
    bool succesful = warehouse.pickItems("Pencils", 20);

    // Check if succeeded
    REQUIRE(succesful);

    // Check if items were taken
    REQUIRE(warehouse.shelves[0].pallets[0].getItemCount() == 0);
    REQUIRE(warehouse.shelves[0].pallets[1].getItemCount() == 30);
    REQUIRE(warehouse.shelves[0].pallets[2].getItemCount() == 20);
    REQUIRE(warehouse.shelves[0].pallets[3].getItemCount() == 2);
}

TEST_CASE("Not enough items", "Warehouse::pickItems"){
    // Construct empty warehouse and add a shelf with 2 types of items and an employee
    Warehouse warehouse = Warehouse();
    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Pencils", 100, 2),
        Pallet("Books", 100, 30),
        Pallet("Books", 100, 20),
        Pallet("Pencils", 100, 20)
    };
    warehouse.addShelf(shelf1);
    warehouse.addEmployee(Employee("Henk", true));

    // Check if there are no items taken yet
    REQUIRE(warehouse.shelves[0].pallets[0].getItemCount() == 2);
    REQUIRE(warehouse.shelves[0].pallets[1].getItemCount() == 30);
    REQUIRE(warehouse.shelves[0].pallets[2].getItemCount() == 20);
    REQUIRE(warehouse.shelves[0].pallets[3].getItemCount() == 20);

    // Try to pick items
    bool succesful = warehouse.pickItems("Pencils", 25);

    // Check if succeeded
    REQUIRE_FALSE(succesful);

    // Check if items were taken
    REQUIRE(warehouse.shelves[0].pallets[0].getItemCount() == 2);
    REQUIRE(warehouse.shelves[0].pallets[1].getItemCount() == 30);
    REQUIRE(warehouse.shelves[0].pallets[2].getItemCount() == 20);
    REQUIRE(warehouse.shelves[0].pallets[3].getItemCount() == 20);
}

TEST_CASE("No items", "Warehouse::pickItems"){
    // Construct empty warehouse and add a shelf with the wrong items
    Warehouse warehouse = Warehouse();
    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Books", 100, 10),
        Pallet("Books", 100, 30),
        Pallet("Books", 100, 40),
        Pallet("Books", 100, 20)
    };
    warehouse.addShelf(shelf1);

    // Add an employee that is not busy
    warehouse.addEmployee(Employee("Henk", true));

    // Check if there are no items taken yet
    REQUIRE(warehouse.shelves[0].pallets[0].getItemCount() == 10);
    REQUIRE(warehouse.shelves[0].pallets[1].getItemCount() == 30);
    REQUIRE(warehouse.shelves[0].pallets[2].getItemCount() == 40);
    REQUIRE(warehouse.shelves[0].pallets[3].getItemCount() == 20);

    // Try to pick items that are not in the warehouse
    bool succesful = warehouse.pickItems("Pencils", 2);

    // Should not have succeeded
    REQUIRE_FALSE(succesful);

    // Check if no items were taken
    REQUIRE(warehouse.shelves[0].pallets[0].getItemCount() == 10);
    REQUIRE(warehouse.shelves[0].pallets[1].getItemCount() == 30);
    REQUIRE(warehouse.shelves[0].pallets[2].getItemCount() == 40);
    REQUIRE(warehouse.shelves[0].pallets[3].getItemCount() == 20);
}

///////////////////////////////////////////////////////////////
//           Warehouse::rearrangeShelf test cases            //
///////////////////////////////////////////////////////////////

TEST_CASE("Rearrange empty shelf", "Warehouse::rearrangeShelf"){
    // Construct empty warehouse and add empty shelf and forklift certified Employee.
    Warehouse warehouse = Warehouse();
    warehouse.addShelf(Shelf());
    warehouse.addEmployee(Employee("Bob", true));

    // Check if shelf is already arranged.
    // Empty shelf should already be arranged.
    REQUIRE(warehouse.shelves[0].pallets[0].getItemCount() == 0);
    REQUIRE(warehouse.shelves[0].pallets[1].getItemCount() == 0);
    REQUIRE(warehouse.shelves[0].pallets[2].getItemCount() == 0);
    REQUIRE(warehouse.shelves[0].pallets[3].getItemCount() == 0);

    // Rearrange the first and only shelf of the warehouse.
    bool successful = warehouse.rearrangeShelf(warehouse.shelves[0]);
    // Should be successful
    REQUIRE(successful);

    // Check if shelf is now correctly arranged.
    // Empty shelf should still be arranged.
    REQUIRE(warehouse.shelves[0].pallets[0].getItemCount() == 0);
    REQUIRE(warehouse.shelves[0].pallets[1].getItemCount() == 0);
    REQUIRE(warehouse.shelves[0].pallets[2].getItemCount() == 0);
    REQUIRE(warehouse.shelves[0].pallets[3].getItemCount() == 0);
}

TEST_CASE("Rearrange full shelf", "Warehouse::rearrangeShelf"){
    // Construct warehouse with unsorted shelf of books.
    Warehouse warehouse = Warehouse();
    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Books", 100, 20), 
        Pallet("Books", 100, 40), 
        Pallet("Books", 100, 30), 
        Pallet("Books", 100, 10)
    };

    warehouse.addEmployee(Employee("Bob", true));
    warehouse.addShelf(shelf1);

    // Check if shelf is already arranged.
    // This shelf should not already be arranged.
    REQUIRE(warehouse.shelves[0].pallets[0].getItemCount() == 20);
    REQUIRE(warehouse.shelves[0].pallets[1].getItemCount() == 40);
    REQUIRE(warehouse.shelves[0].pallets[2].getItemCount() == 30);
    REQUIRE(warehouse.shelves[0].pallets[3].getItemCount() == 10);

    // Rearrange the first and only shelf of the warehouse.
    bool successful = warehouse.rearrangeShelf(warehouse.shelves[0]);
    // Should be successful
    REQUIRE(successful);

    // Check if shelf is now correctly arranged.
    // Shelf should now be arranged.
    REQUIRE(warehouse.shelves[0].pallets[0].getItemCount() == 10);
    REQUIRE(warehouse.shelves[0].pallets[1].getItemCount() == 20);
    REQUIRE(warehouse.shelves[0].pallets[2].getItemCount() == 30);
    REQUIRE(warehouse.shelves[0].pallets[3].getItemCount() == 40);
}

TEST_CASE("Rearrange half filled shelf", "Warehouse::rearrangeShelf"){
    // Construct empty warehouse and unsorted shelf of books.
    Warehouse warehouse = Warehouse();
    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Books", 100, 40), 
        Pallet("Books", 100, 20), 
        Pallet(), 
        Pallet()
    };
    
    warehouse.addEmployee(Employee("Bob", true));
    warehouse.addShelf(shelf1);

    // Check if shelf is already arranged.
    // This shelf should not already be arranged.
    REQUIRE(warehouse.shelves[0].pallets[0].getItemCount() == 40);
    REQUIRE(warehouse.shelves[0].pallets[1].getItemCount() == 20);
    REQUIRE(warehouse.shelves[0].pallets[2].getItemCount() == 0);
    REQUIRE(warehouse.shelves[0].pallets[3].getItemCount() == 0);

    // Rearrange the first and only shelf of the warehouse.
    bool successful = warehouse.rearrangeShelf(warehouse.shelves[0]);
    // Should be successful
    REQUIRE(successful);

    // Check if shelf is now correctly arranged.
    // Shelf should now be arranged.
    REQUIRE(warehouse.shelves[0].pallets[0].getItemCount() == 0);
    REQUIRE(warehouse.shelves[0].pallets[1].getItemCount() == 0);
    REQUIRE(warehouse.shelves[0].pallets[2].getItemCount() == 20);
    REQUIRE(warehouse.shelves[0].pallets[3].getItemCount() == 40);
}

TEST_CASE("Rearrange shelf without qualified employee", "Warehouse::rearrangeShelf"){
    // Construct warehouse with unsorted shelf of books.
    Warehouse warehouse = Warehouse();
    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Books", 100, 20), 
        Pallet("Books", 100, 40), 
        Pallet("Books", 100, 30), 
        Pallet("Books", 100, 10)
    };
    
    warehouse.addEmployee(Employee("Bert", false));
    warehouse.addShelf(shelf1);

    // Check if shelf is already arranged.
    // This shelf should not already be arranged.
    REQUIRE(warehouse.shelves[0].pallets[0].getItemCount() == 20);
    REQUIRE(warehouse.shelves[0].pallets[1].getItemCount() == 40);
    REQUIRE(warehouse.shelves[0].pallets[2].getItemCount() == 30);
    REQUIRE(warehouse.shelves[0].pallets[3].getItemCount() == 10);

    // Rearrange the first and only shelf of the warehouse.
    bool successful = warehouse.rearrangeShelf(warehouse.shelves[0]);
    // Should fail
    REQUIRE(!successful);

    // Check if shelf is now correctly arranged.
    // Shelf should now still not be arranged.
    REQUIRE(warehouse.shelves[0].pallets[0].getItemCount() == 20);
    REQUIRE(warehouse.shelves[0].pallets[1].getItemCount() == 40);
    REQUIRE(warehouse.shelves[0].pallets[2].getItemCount() == 30);
    REQUIRE(warehouse.shelves[0].pallets[3].getItemCount() == 10);
}

TEST_CASE("Rearrange shelf with quallified, but busy, employee", "Warehouse::rearrangeShelf"){
    // Construct warehouse with unsorted shelf of books.
    Warehouse warehouse = Warehouse();
    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Books", 100, 20), 
        Pallet("Books", 100, 40), 
        Pallet("Books", 100, 30), 
        Pallet("Books", 100, 10)
    };
    
    Employee bert = Employee("Bert", true);
    bert.setBusy(true);

    warehouse.addEmployee(bert);
    warehouse.addShelf(shelf1);

    // Check if shelf is already arranged.
    // This shelf should not already be arranged.
    REQUIRE(warehouse.shelves[0].pallets[0].getItemCount() == 20);
    REQUIRE(warehouse.shelves[0].pallets[1].getItemCount() == 40);
    REQUIRE(warehouse.shelves[0].pallets[2].getItemCount() == 30);
    REQUIRE(warehouse.shelves[0].pallets[3].getItemCount() == 10);

    // Rearrange the first and only shelf of the warehouse.
    bool successful = warehouse.rearrangeShelf(warehouse.shelves[0]);
    // Should fail
    REQUIRE(!successful);

    // Check if shelf is now correctly arranged.
    // Shelf should now still not be arranged.
    REQUIRE(warehouse.shelves[0].pallets[0].getItemCount() == 20);
    REQUIRE(warehouse.shelves[0].pallets[1].getItemCount() == 40);
    REQUIRE(warehouse.shelves[0].pallets[2].getItemCount() == 30);
    REQUIRE(warehouse.shelves[0].pallets[3].getItemCount() == 10);
}
