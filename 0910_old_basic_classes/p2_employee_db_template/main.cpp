#include <iostream>
#include "Database.h"

using namespace std;



int DisplayMenu();
void doHire(Database& db);
void doFire(Database& db);
void doPromote(Database& db);

int main()
{
    Database db;
    bool done{false};

    while (!done)
    {
        int selection {DisplayMenu()};
        switch (selection)
        {
            case 0:
                done=true;
                break;
            case 1:
                //doHire(db);
                break;
            case 2:
                //doFire(db);
                break;
            case 3: 
                //doPromote(db);
                break;
            case 4:
                db.displayAll();break;
            case 5:
                db.displayCurrent();break;
            case 6:
                db.displayFormer();break;
            default:
                std::cout<<"Unknown command"<<std::endl;
        }
    }
}

int displayMenu()
{
    int selection;
    std::cout << std::endl;
    std::cout << "Employee Database" << std::endl;
    std::cout << "-----------------" << std::endl;
    std::cout << "1) Hire a new employee" << std::endl;
    std::cout << "2) Fire an employee" << std::endl;
    std::cout << "3) Promote an employee" << std::endl;
    std::cout << "4) List all employees" << std::endl;
    std::cout << "5) List all current employees" << std::endl;
    std::cout << "6) List all former employees" << std::endl;
    std::cout << "0) Quit" << std::endl;
    std::cout << std::endl;
    std::cout << "---> ";
    std::cin>> selection;
    return selection;
}
/*
void doHire(Database& db)
{
    std::string firstName;
    std::string lastName;
    std::cout<<"First name"<<std::endl;
    std::cin>>firstName;
    cout<<"Last Name"<<endl;
    cin>>lastName;

    auto& emp {db.addEmployee(firstName,lastName)};
    cout<<"Hired employee ";
    emp.display();
}

void doFire(Database&db)
{
    int emp_number;
    cout<<"Employee number? :"<<endl;
    cin>>emp_number;

    try{
        auto &emp{db.getEmployee(emp_number)};
        emp.fire();
        cout<<"Employee" << emp_number<<" fired."<<endl;
    }catch(const std::logic_error& exception){
        cout<<"Employee with number: " << emp_number<<endl;
        cout<<"Does not exist"<< exception.what()<<endl;
    }   
}

void doPromote(Database&db)
{
    int emp_number;
    cout<<"Employee number? :"<<endl;
    cin>>emp_number;

    int rise_ammount;
    cout<<"Raise ammount? :"<<endl;
    cin>>rise_ammount;

    try{
        auto &emp{db.getEmployee(emp_number)};
        emp.promote(rise_ammount);
        cout<<"Employee" << emp_number<<" fired."<<endl;
    }catch(const std::logic_error& exception){
        cout<<"Unable to promote that employee: " << emp_number<<endl;
        cout<<exception.what()<<endl;
    }  
}

*/






















/*
int main()
{
    Database myDB;
    
    Employee& emp1 { myDB.addEmployee("Greg", "Wallis") };
    emp1.fire();
 
    Employee& emp2 { myDB.addEmployee("Marc", "White") };
    emp2.setSalary(100'000);
 
    Employee& emp3 { myDB.addEmployee("John", "Doe") };
    emp3.setSalary(10'000);
    emp3.promote();
 
    std::cout << "all employees: " << std::endl << std::endl;
    myDB.displayAll();
 
    std::cout << std::endl << "current employees: " << std::endl << std::endl;
    myDB.displayCurrent();
 
    std::cout << std::endl << "former employees: " << std::endl << std::endl;
    myDB.displayFormer();
    
}
*/

/*
int main()
{
    Employee e{"Jane","Roberts"};
    e.setSalary(100000);
    e.setFirstName("Bob");
    e.setLastName("Garmege");
    e.promote();
    e.promote(12);
    e.hire();
    e.display();
    return 0;
}
*/