#include "Employee.h"
#include <iostream>


Employee::Employee(const std::string &firstName,const std::string &lastName):
                    in_firstName{firstName},in_lastName{lastName}
                    {}

//getters setters
void Employee::setFirstName(const std::string& firstName)
                    {this->in_firstName=firstName;}
const std::string & Employee::getFirstName() const
                    {return this->in_firstName;}

void Employee::setLastName(const std::string& lastName)
                    {this->in_lastName=lastName;}
const std::string& Employee::getLastName() const
                    {return this->in_lastName;}

void Employee::setEmployeeNumber(int employeeNumber)
                    {this->in_employeeNumber=employeeNumber;}
int Employee::getEmployeeNumber() const
                    {return in_employeeNumber;}

void Employee::setSalary(int newSalary)
                    {this->in_salary=newSalary;}
int Employee::getSalary() const
                    {return in_salary;}

bool Employee::isHired(){return in_isHired;}

//others
void Employee::promote(int raiseAmmount)
                    {this->setSalary(this->getSalary()+raiseAmmount);};

void Employee::demote(int demeritAmmount)
                    {this->setSalary(this->getSalary()-demeritAmmount);};
void Employee::hire(){this->in_isHired = true;};
void Employee::fire(){this->in_isHired = false;};
void Employee::display()const
                    {
        std::cout << "Employee: "<<this->getLastName()<< ", "<<this->getFirstName()<< std::endl;
        std::cout << "-------------------------" << std::endl;
        std::cout << (this->in_isHired? "Current Employee" : "Former Employee") << std::endl;
        std::cout << "Employee Number:"<< this->getEmployeeNumber() << std::endl;
        std::cout << "Salary: $"<< this->getSalary() << std::endl;
        std::cout << std::endl;
                    }
