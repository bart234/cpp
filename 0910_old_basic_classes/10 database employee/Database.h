#pragma once
#include <iostream>
#include <vector>
#include "Employee.h"

namespace Records {
	const int cFirstEmployeeNumber = 1000;


class Database
{
private:
	//varible
	std::vector<Employee> mEmployee_vector;
	int mNextEmployeeNumber = cFirstEmployeeNumber;

public: 
	//counstructors
	//zwraca referencje do stworzonego obiektu jaki zostal wstawiony do vektora
	Employee& addEmployee(const std::string& firstName, const std::string& lastName);
	Employee& getEmployee(int employeeNUmber);
	Employee& getEmployee(const std::string& firstName, const std::string& lastName);
	
	//fuctions
	void displayAll() const;
	void displayCurrent() const ;
	void displayFormer() const;




};




}

