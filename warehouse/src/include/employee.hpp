#pragma once

#include <iostream>
#include <string>

class Employee{
    private:
        const std::string name;
        bool busy = false;
        bool forkliftCertificate;
    public:
        /**
         * @brief Constructor
         * 
         * @param name 
         * @param forkliftCertificate 
         */
        Employee(std::string name, bool forkliftCertificate);

        /**
         * @brief Get the Name of an employee
         * 
         * @return std::string 
         */
        std::string getName();

        /**
         * @brief Check if an employee is busy
         * 
         * @return true when busy
         * @return false when not busy
         */
        bool getBusy();

        /**
         * @brief Change if an employee is busy
         * 
         * @param busy true if busy, false if not busy
         */
        void setBusy(bool busy);

        /**
         * @brief Check if an employee is forkliftcertified
         * 
         * @return true
         * @return false 
         */
        bool getForkliftCertificate();

        /**
         * @brief Set if an employee is forkliftcertified
         * 
         * @param forkliftCertificate true when forkliftcertified, false when not so
         */
        void setForkliftCertificate(bool forkliftCertificate);
};