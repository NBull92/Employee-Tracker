#pragma once

#include <string>
#include "EmployeeNode.h"

class Company
{
private:
	EmployeeNode* _employeeList;
    EmployeeNode* ReverseList();
    std::string GetString(const std::string& prompt);
    int GetNumber(const std::string& prompt);
public:
	std::string Name;
	Company(std::string name);
	void AddEmployee();
    void DisplayEmployee();
    void DeleteEmployee();
    void EditEmployee();
    void DisplayEmployees();
    void Save();
};

