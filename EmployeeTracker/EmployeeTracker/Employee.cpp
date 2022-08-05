#include <iostream>
#include "Employee.h"

Employee::Employee(int id, std::string name, int age, int salary, int bonusPercentage)
{
	Id = id;
	Name = name;
	Age = age;
	Salary = salary;
	Bonus = bonusPercentage;
}

Employee::~Employee()
{
	std::cout << "\n\Decpnstructor called for: " << Name << std::endl;
}

void Employee::Display()
{
	std::cout 
		<< "\n\tId: " << Id 
		<< "\n\tName: " << Name 
		<< "\n\tAge: " << Age 
		<< "\n\tSalary: " << Salary 
		<< "\n\tBonus Percentage: " << Bonus << "%" << std::endl;
}

void Employee::Edit()
{
	std::cout << "\n\tThe employee's Name is currently: " << Name << ". Would you like to edit Name? (y/n)" << std::endl;
	char answer;
	std::cin >> answer;	// TODO: validate this

	if (answer == 'y')
	{
		std::cout << "\tPlease provide the employee's name: ";
		std::string employeeName;
		std::cin >> employeeName;	// this doesn't allow for spaces	// TODO: validate this	
		//std::getline(std::cin, employeeName); // this jumps straight to asking for age.	// TODO: validate this

		Name = employeeName;
	}

	answer = NULL;
	std::cout << "\n\tThe Employee's Age is currently: " << Age << ". Would you like to edit Age? (y/n)" << std::endl;
	std::cin >> answer;	// TODO: validate this

	if (answer == 'y')
	{
		std::cout << "\tPlease provide the employee's age: ";
		int employeeAge;
		std::cin >> employeeAge;	// TODO: validate this

		Age = employeeAge;
	}

	answer = NULL;
	std::cout << "\n\tThe Employee's Salary is currently: " << Salary << ". Would you like to edit Salary? (y/n)" << std::endl;
	std::cin >> answer;	// TODO: validate this

	if (answer == 'y')
	{
		std::cout << "\tPlease provide the employee's salary: ";
		int employeeSalary;
		std::cin >> employeeSalary;	// TODO: validate this

		Salary = employeeSalary;
	}

	answer = NULL;
	std::cout << "\n\tThe Employee's Bonus Percentage is currently: " << Bonus << ". Would you like to edit Bonus Percentage? (y/n)" << std::endl;
	std::cin >> answer;	// TODO: validate this

	if (answer == 'y')
	{
		std::cout << "\tPlease provide the employee's bonus percentage: ";
		int employeeBonus;
		std::cin >> employeeBonus;	// TODO: validate this

		Bonus = employeeBonus;
	}

	std::cout << "\n\tThe updated Employe Values are: " << std::endl;

	Display();
}
