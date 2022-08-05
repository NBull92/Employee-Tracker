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
