#pragma once

#include <string>

class Company
{
private:
	//	list of employees
public:
	std::string Name;
	Company(std::string name);
	void AddEmployee();
};

