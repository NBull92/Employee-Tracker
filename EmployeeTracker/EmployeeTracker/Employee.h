#pragma once

#include <string>

class Employee
{
private:
	int _id;
public:
		Employee(int id, std::string name, int age, int salary, int bonusPercentage = 0);
		std::string Name;
};

