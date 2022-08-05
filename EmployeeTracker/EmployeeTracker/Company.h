#pragma once

#include <string>
#include "EmployeeNode.h"

class Company
{
private:
	EmployeeNode* _employeeList;
    EmployeeNode* ReverseList();

public:
	std::string Name;
	Company(std::string name);
	void AddEmployee();
    void DisplayEmployee();
    void DeleteEmployee();
    void EditEmployee();
    void DisplayEmployees();
};

