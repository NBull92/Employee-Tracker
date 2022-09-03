#pragma once

#include <string>
#include "EmployeeNode.h"

class Company
{
private:
	EmployeeNode* _employeeList;
    EmployeeNode* ReverseList();
    EmployeeNode* TraverseList();
public:
	std::string Name;
	Company(std::string name);
    void AddEmployee();
    void AddEmployee(Employee* employee);
    void DisplayEmployee();
    void DeleteEmployee();
    void EditEmployee();
    void DisplayEmployees();
    void Save();
};

