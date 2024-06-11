#pragma once
#include <string>

namespace Records
{
    const int DefaultStartingSalary{30'000};
    const int DefaultRaiseAndDemeritSalary{1'000};    
}

class Employee
{
    private:
        std::string in_firstName;
        std::string in_lastName;
        int in_employeeNumber{-1};
        int in_salary{Records::DefaultStartingSalary};
        bool in_isHired{false};

    public:
        Employee(const std::string &firstName,
                 const std::string &lastName);
        void promote(int raiseAmmount = Records::DefaultRaiseAndDemeritSalary);
        void demote(int demeritAmmount = Records::DefaultRaiseAndDemeritSalary);
        void hire();
        void fire();
        void display()const;

    //getters setters
    void setFirstName(const std::string& firstName);
    const std::string & getFirstName() const;

    void setLastName(const std::string& lastName);
    const std::string& getLastName() const;

    void setEmployeeNumber(int employeeNumber);
    int getEmployeeNumber() const;

    void setSalary(int newSalary);
    int getSalary() const;

    bool isHired();

};

