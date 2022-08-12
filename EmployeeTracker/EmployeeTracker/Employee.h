#pragma once

#include <string>

class Employee
{
private:
	std::string IntToString(int value);
public:
		Employee(int id, std::string name, int age, int salary, int bonusPercentage = 0);
		~Employee();
		std::string Name;
		int Id;
		int Age;
		int Salary;
		int Bonus;
		void Display();
		void Edit();
		std::string Print();
};