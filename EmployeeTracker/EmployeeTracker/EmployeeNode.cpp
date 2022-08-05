#include <iostream>
#include "EmployeeNode.h"
#include "Employee.h"

EmployeeNode::EmployeeNode(Employee* employee) : EmployeeData(employee), Next(nullptr){ }

EmployeeNode::EmployeeNode(Employee* employee, EmployeeNode* next) : EmployeeData(employee), Next(next) { }

EmployeeNode::~EmployeeNode()
{
	Next = nullptr;
	delete EmployeeData;
}

void EmployeeNode::Display()
{
	EmployeeData->Display();
}