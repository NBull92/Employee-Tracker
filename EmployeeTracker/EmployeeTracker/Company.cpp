#include <iostream>
#include <string>
#include "Company.h"
#include "Employee.h"
#include "FileWriter.h"
#include "ConsoleUtils.h"

EmployeeNode* Company::ReverseList()
{
	EmployeeNode* previous = nullptr;
	auto current = _employeeList;

	while (current != nullptr)
	{
		auto next = current->Next;
		current->Next = previous;
		previous = current;
		current = next;
	}

	return previous;
}

EmployeeNode* Company::TraverseList()
{
	EmployeeNode* previous = nullptr;
	auto current = _employeeList;

	while (current != nullptr)
	{
		auto next = current->Next;
		previous = current;
		current = next;
	}

	return previous;
}

Company::Company(std::string name) : Name(name), _employeeList(nullptr) { }

void Company::AddEmployee()
{
	auto employeeName = ConsoleUtils::GetString("\tPlease provide the employee's name: ", true);
	auto employeeAge = ConsoleUtils::GetNumber("\tPlease provide the employee's age: ");
	auto employeeSalary = ConsoleUtils::GetNumber("\tPlease provide the employee's salary: ");
	auto employeeBonus = ConsoleUtils::GetNumber("\tPlease provide the employee's bonus percentage: ");

	Employee* newEmp = nullptr;
	if (_employeeList != nullptr)
	{
		auto lastEmployee = TraverseList();
		auto lastId = lastEmployee->EmployeeData->Id;
		newEmp = new Employee(lastId+1, employeeName, employeeAge, employeeSalary, employeeBonus);
		auto node = new EmployeeNode(newEmp);
		lastEmployee->Next = node;
	}
	else
	{
		newEmp = new Employee(1, employeeName, employeeAge, employeeSalary, employeeBonus);
		auto node = new EmployeeNode(newEmp);
		_employeeList = node;
	}

	std::cout << "\tEmployee: " << " (" << newEmp->Id << ") " << newEmp->Name << " added successfully." << std::endl;
}

void Company::AddEmployee(Employee* employee)
{
	auto lastEmployee = TraverseList();
	if (lastEmployee == nullptr)
	{
		_employeeList = new EmployeeNode(employee);
	}
	else
	{
		lastEmployee->Next =  new EmployeeNode(employee);	
	}
}

void Company::DisplayEmployee()
{
	if (_employeeList == nullptr)
	{
		std::cout << "\tThere is no employee data to display." << std::endl;
		return;
	}

	auto id = ConsoleUtils::GetNumber("\tPlease provide the Id of the employee you wish to display: ");

	auto node = _employeeList;
	while (node != nullptr)
	{
		if (node->EmployeeData->Id == id)
		{
			node->Display();
			return;
		}
		else
		{
			node = node->Next;
		}
	}

	std::cout << "\tThere is no employee data with that Id." << std::endl;
}

void Company::DeleteEmployee()
{
	if (_employeeList == nullptr)
	{
		std::cout << "\tThere is no employee data to delete." << std::endl;
		return;
	}

	auto id = ConsoleUtils::GetNumber("\tPlease provide the Id of the employee you wish to delete: ");

	EmployeeNode* previous = nullptr;
	auto node = _employeeList;
	while (node != nullptr)
	{
		if (node->EmployeeData->Id == id)
		{
			if (previous == nullptr)
			{
				_employeeList = node->Next;
			}
			else
			{
				previous->Next = node->Next;
			}
			
			delete node;
			return;
		}
		else
		{
			previous = node;
			node = node->Next;
		}
	}

	std::cout << "\tThere is no employee data with that Id." << std::endl;
}

void Company::EditEmployee()
{
	if (_employeeList == nullptr)
	{
		std::cout << "\tThere is no employee data to edit." << std::endl;
		return;
	}

	auto id = ConsoleUtils::GetNumber("\tPlease provide the Id of the employee you wish to edit: ");

	auto node = _employeeList;
	while (node != nullptr)
	{
		if (node->EmployeeData->Id == id)
		{
			node->Edit();
			return;
		}
		else
		{
			node = node->Next;
		}
	}

	std::cout << "\tThere is no employee data with that Id." << std::endl;
}

void Company::DisplayEmployees()
{
	if (_employeeList == nullptr)
	{
		std::cout << "\tThere is no employee data to display\n" << std::endl;
		return;
	}
	
	auto node = _employeeList;

	while (node != nullptr)
	{
		node->Display();
		node = node->Next;
	}
}

void Company::Save()
{
	FileWriter().Write(Name, _employeeList);	
}

