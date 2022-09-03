#include <iostream>
#include "Employee.h"
#include "ConsoleUtils.h"

std::string Employee::IntToString(int value)
{
	return std::to_string(value);
}

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
	std::cout << "\n\Deconstructor called for: " << Name << std::endl;
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
	std::cin >> answer;
	
	if (answer == 'y')
	{
		std::cout << "\tPlease provide the employee's name: ";
		std::string employeeName;
		std::cin >> employeeName;

		Name = employeeName;
	}

	answer = NULL;
	std::cout << "\n\tThe Employee's Age is currently: " << Age << ". Would you like to edit Age? (y/n)" << std::endl;
	std::cin >> answer;

	if (answer == 'y')
	{
		Age = ConsoleUtils::GetNumber("\tPlease provide the employee's age: ");
	}

	answer = NULL;
	std::cout << "\n\tThe Employee's Salary is currently: " << Salary << ". Would you like to edit Salary? (y/n)" << std::endl;
	std::cin >> answer;	

	if (answer == 'y')
	{
		Salary = ConsoleUtils::GetNumber("\tPlease provide the employee's salary: ");
	}

	answer = NULL;
	std::cout << "\n\tThe Employee's Bonus Percentage is currently: " << Bonus << ". Would you like to edit Bonus Percentage? (y/n)" << std::endl;
	std::cin >> answer;	

	if (answer == 'y')
	{
		Bonus = ConsoleUtils::GetNumber("\tPlease provide the employee's bonus percentage: ");
	}

	std::cout << "\n\tThe updated Employe Values are: " << std::endl;

	Display();
}

std::string Employee::Print()
{
	return IntToString(Id) + "," + Name + "," + IntToString(Age) + "," + IntToString(Salary) + "," + IntToString(Bonus);
}
