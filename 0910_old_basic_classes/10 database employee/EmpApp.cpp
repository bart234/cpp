#include <iostream>
#include <stdexcept>
#include <exception>
#include "Database.h"

using namespace std;
using namespace Records;

//fuunction prototype
int displayMenu();
void doHire(Database& db);
void doFire(Database& db);
void doPromote(Database& db);
void doDemote(Database& db);

int main()
{
    #pragma region test employee classes
  /*  std::cout << "Class testing" << std::endl;
    Employee emp_test;
    emp_test.setFirstName("Jan");
    emp_test.setLastName("Kowalczyk");
    emp_test.setSalary(80343);
    emp_test.setEmpNumber(23);
    emp_test.promote();
    emp_test.promote(22222);
    emp_test.demote(50000);
    emp_test.hire();
    emp_test.display();
    std::cout << (emp_test.isHired() ? "Hired" : "No nired") << std::endl;
    */
#pragma endregion

    #pragma region test employee db

    //Database myDB;
    //Employee& emp1 = myDB.addEmployee("Greg", "Wallis");
    //emp1.fire();

    //Employee &emp2 = myDB.addEmployee("Bart", "Bier");
    //emp2.promote();

    //Employee &emp3 = myDB.addEmployee("Olga", "Kowal");
    //emp3.setSalary(100000);
    //emp3.promote();
    //
    //myDB.displayCurrent();

    //myDB.displayAll();
    #pragma endregion

    Database employeeDB;
    bool done = false;
    while (!done)
    {
        int selection = displayMenu();
        switch (selection) {
            case 0: {
                done = true;
                break;
            }case 1: {
                doHire(employeeDB);
                break;
            }case 2: {
                doFire(employeeDB);
                break;
            }case 3: {
                doPromote(employeeDB);
                break;
            }case 4: {
                doDemote( employeeDB);
                break;
            }case 5: {
                employeeDB.displayAll();
                break;
            }case 6: {
                employeeDB.displayCurrent();
                break;
            }case  7: {
                employeeDB.displayFormer();
                break;
            }default: {
                cerr << "unknown command" << endl;
                break;
            }
        }
    }

    return 0;

}

int displayMenu() {
    int selection;
    cout << endl;
    cout << "Employee Database" << endl;
    cout << "-----------------" << endl;
    cout << "1)  Hire a new employee" << endl;
    cout << "2) Fire an employee" << endl;
    cout << "3) Promote an employee" << endl;
    cout << "4) Demote an employee" << endl;
    cout << "5) Display all employee" << endl;
    cout << "6) Display current employee" << endl;
    cout << "7) Display former employee" << endl;
    cout << "0) Quit" << endl;
    cout << endl;
    cout << "-->";
    cin >> selection;
    return selection;
}

void doHire(Database& db) {
    cout << "Please put first and second name of new user:" << endl;
    string firstN;
    string lastN;

    cout << "First name is:" << endl;
    cin >> firstN;

    cout << "Last name is:" << endl;
    cin >> lastN;

    db.addEmployee(firstN, lastN);

}

void doFire(Database& db) {
    int empNumber;
    cout<<"Employee number? ";
    cin >> empNumber;
    try {
        Employee &emp = db.getEmployee(empNumber);
        emp.fire();
        cout << "Employee " << empNumber << " terminated." << endl;
    }
    catch(const std::logic_error exception){
        cerr << "Unable to terminate employee:  " << exception.what() << endl;
    }
}

void doPromote(Database& db) {
    int empNumber;
    cout << "Employee number? ";
    cin >> empNumber;

    float riseAmount;
    cout << "How much of a rise? ";
    cin >> riseAmount;

    try {
        Employee &emp = db.getEmployee(empNumber);
        emp.promote(riseAmount);
    }
    catch (const std::logic_error exception) {
        cerr << "Unable to promote employee: " << exception.what() << endl;
    }
}

void doDemote(Database& db) {
    int empNumber;
    cout << "Employee number? ";
    cin >> empNumber;

    float riseAmount;
    cout << "How much of a demote? ";
    cin >> riseAmount;

    try {
        Employee &emp = db.getEmployee(empNumber);
        emp.demote(riseAmount);
    }
    catch (const std::logic_error exception) {
        cerr << "Unable to demote employee: " << exception.what() << endl;
    }
}