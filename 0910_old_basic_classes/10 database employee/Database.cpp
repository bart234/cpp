#include <vector>
#include <stdexcept>

#include "Database.h"
#include "Employee.h"

namespace Records{

    Employee& Database::addEmployee(const std::string& firstName, const std::string& lastName)
    {   
        Employee new_empl(firstName, lastName);
        new_empl.setEmpNumber(mNextEmployeeNumber++);
        new_empl.hire();
        mEmployee_vector.push_back(new_empl);
        //zwraca referencje do pracowanika jaka jest w vektorze
        return mEmployee_vector[mEmployee_vector.size()-1];
    }

    Employee& Database::getEmployee(int employeeNUmber)
    {
        for (auto& emp : mEmployee_vector) {
            if (emp.getEmpNumber() == employeeNUmber) {
                return emp;
            }
        }
        //throw logic_error("No employee found.");
    }

    Employee& Database::getEmployee(const std::string& firstName, const std::string& lastName)
    {
        for (auto& emp : mEmployee_vector) {
            if (emp.getFirstName() == firstName && emp.getLastName() == lastName) {
                return emp;
            }
        }
        //throw logic_error("No employee found.");
    }

    void Database::displayAll() const
    {
        for (auto& emp : mEmployee_vector) {
            emp.display();
            
        }

    }

    void Database::displayCurrent() const
    {
        for (const auto& emp : mEmployee_vector) {
            if (emp.isHired()) {
                emp.display();
            }
        }
    }

    void Database::displayFormer() const
    {
        for (const auto& emp : mEmployee_vector) {
            if (!emp.isHired()) {
                emp.display();
            }
        }
    }
}