#include <iostream>
#include <string>
#include "include/employee.hpp"

Employee::Employee(std::string name, bool forkliftCertificate): name(name), forkliftCertificate(forkliftCertificate){};

std::string Employee::getName() const{
    return name;
}

bool Employee::getBusy() const{
    return busy;
}

void Employee::setBusy(bool busy){
    this->busy = busy;
}

bool Employee::getForkliftCertificate() const{
    return forkliftCertificate;
}

void Employee::setForkliftCertificate(bool forkliftCertificate){
    this->forkliftCertificate = forkliftCertificate;
}

std::ostream& operator<<(std::ostream& out, const Employee &employee){
    out << employee.getName() << "(ForkliftCertified: " << (employee.getForkliftCertificate() ? "true" : "false") << ", Busy: " << (employee.getBusy() ? "true" : "false") << ")";
    return out;
}