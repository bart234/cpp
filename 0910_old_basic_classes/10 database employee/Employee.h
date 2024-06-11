#pragma once
#include <string>
namespace Records {
	const int cDefaultStartingSalary = 30000;

	class Employee
	{
		//constructor
	public:
		Employee() = default;
		Employee(const std::string & FirstName, const std::string & LastName);

		//class data
	private:
		std::string mFirstName;
		std::string mLastName;
		int mEmployeeNumber = -1;
		int mSalary = cDefaultStartingSalary;
		bool mHired = false;

		//functions
	public:
		void promote(int raiseAmount = 1000);
		void demote(int demeritAmount = 1000);
		void hire(); //hires employee
		void fire(); //fire employee
		void display() const; //print employee info in console

		//functions
		void setEmpNumber(int empNumber_in);
		const int& getEmpNumber() const;

		void setFirstName(const std::string & firstName_in);
		const std::string& getFirstName() const;

		void setLastName(const std::string & lastName_in);
		const std::string& getLastName() const;

		void setSalary(int newSalary);
		int getSalary() const;

		bool isHired() const;

	};

}