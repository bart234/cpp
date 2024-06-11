#include "Database.h"
#include <stdexcept>


Employee& Database::addEmployee(const std::string &firstName,const std::string &lastName)
        {
            Employee e {firstName,lastName};
            e.setEmployeeNumber(this->in_nextEmplyeeNUmber++); //add number, and then incrmenet it
            e.hire();
            this->in_viki_employees.push_back(e);
            return this->in_viki_employees.back();  //return ref to last element
        }
Employee& Database::getEmployee(int employeeNUmber)
        {
            for(auto &el:this->in_viki_employees)
            {
                if(el.getEmployeeNumber()==employeeNUmber)
                    return el;
            }
            throw std::logic_error {"no employee found"};
        }
Employee& Database::getEmployee(const std::string &firstName,
                              const std::string &lastName)
        {
            for(auto &el:this->in_viki_employees)
            {
                if(el.getFirstName()==firstName && el.getLastName()==lastName)
                    return el;
            }
            throw std::logic_error {"no employee found"};
        }

void Database::displayAll()
    {for(auto &el:this->in_viki_employees){el.display();}}
void Database::displayCurrent()
    {
        for(auto &el:this->in_viki_employees)
            {
                if (el.isHired())
                    el.display();
            }
    }
void Database::displayFormer()
    {
        for(auto &el:this->in_viki_employees)
            {
                if (!el.isHired())
                    el.display();
            }
    }