#pragma once
#include <vector>
#include <string>
#include "Employee.h"

namespace DatabaseRecords
{
    const int FirstEmployeeNumber{1'000};
}

class Database
{
    private:
        std::vector<Employee> in_viki_employees;
        int in_nextEmplyeeNUmber{DatabaseRecords::FirstEmployeeNumber};
    public:
        Employee& addEmployee(const std::string &firstName,
                              const std::string &lastName);
        Employee& getEmployee(int employeeNUmber);
        Employee& getEmployee(const std::string &firstName,
                              const std::string &lastName);

        void displayAll();
        void displayCurrent();
        void displayFormer();

};

