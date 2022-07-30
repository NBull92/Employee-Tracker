#include <iostream>
#include "Company.h"
#include "Employee.h"

Company::Company(std::string name)
{
}

void Company::AddEmployee()
{
	//	Ask user for a name
	std::cout << "Please provide the employee's name: ";
	std::string employeeName;
	std::cin >> employeeName;
	
	//	Ask for age
	std::cout << "Please provide the employee's age: ";
	int employeeAge;
	std::cin >> employeeAge;	// TODO: validate this

	//	Ask for salary
	std::cout << "Please provide the employee's salary: ";
	int employeeSalary;
	std::cin >> employeeSalary;	// TODO: validate this

	//	Ask for bonus percentage
	std::cout << "Please provide the employee's bonus percentage: ";
	int employeeBonus;
	std::cin >> employeeBonus;	// TODO: validate this

	//	get last employee id.
	Employee newEmp = Employee(0, employeeName, employeeAge, employeeSalary, employeeBonus);

	//	Print out employee "Name (Id)" has been added.
	std::cout << "Employee: " << employeeName << " (" << 0 << ")" << "added successfully.";
}
