#include "Employee.h"
#include <iostream>

namespace Records {
	Employee::Employee(const std::string& FirstName, const std::string& LastName)
		:mFirstName(FirstName), mLastName(LastName)
	{
	}

	void Employee::promote(int raiseAmount)
	{
		mSalary = getSalary() + raiseAmount;
	}

	void Employee::demote(int demeritAmount)
	{
		mSalary = getSalary() - demeritAmount;
	}

	void Employee::hire()
	{
		mHired = true;
	}

	void Employee::fire()
	{
		mHired = false;
	}

	void Employee::display() const
	{
		std::cout << "Employee: " << getLastName() << ", " << getFirstName() << std::endl;
		std::cout << "-------------------------" << std::endl;
		std::cout << (isHired() ? "Current Employee" : "Former Employee") << std::endl;
		
		std::cout << "Employee Number: " << getEmpNumber()<< std::endl;
		std::cout << "Salary: $" << getSalary() << std::endl;
		std::cout << std::endl;
	}

	void Employee::setEmpNumber(int empNumber_in) 
	{
		mEmployeeNumber = empNumber_in;
	}

	const int& Employee::getEmpNumber() const
	{
		return mEmployeeNumber;
	}

	void Employee::setFirstName(const std::string& firstName_in)
	{
		mFirstName = firstName_in;
	}

	const std::string& Employee::getFirstName() const
	{
		return mFirstName;
	}

	void Employee::setLastName(const std::string& lastName_in)
	{
		mLastName = lastName_in;
	}

	const std::string& Employee::getLastName() const
	{
		return mLastName;
	}

	void Employee::setSalary(int newSalary)
	{
		mSalary = newSalary;
	}

	int Employee::getSalary() const
	{
		return mSalary;
	}

	bool Employee::isHired() const
	{
		return mHired;
	}

}