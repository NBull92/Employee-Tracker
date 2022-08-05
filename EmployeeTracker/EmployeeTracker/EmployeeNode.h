#pragma once
#include "Employee.h"

class EmployeeNode
{
public:	
	EmployeeNode(Employee* employee);
	EmployeeNode(Employee* employee, EmployeeNode* next);
	~EmployeeNode();

	Employee* EmployeeData;
	EmployeeNode* Next;
	void Display();
	void Edit();
};

