#include <iostream>
#include "Company.h"
#include "Employee.h"

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

Company::Company(std::string name) : Name(name), _employeeList(nullptr) { }

void Company::AddEmployee()
{
	//	Ask user for a name
	std::cout << "\tPlease provide the employee's name: ";
	std::string employeeName;
	std::cin >> employeeName;	// this doesn't allow for spaces	// TODO: validate this	
	//std::getline(std::cin, employeeName); // this jumps straight to asking for age.	// TODO: validate this
	
	//	Ask for age
	std::cout << "\tPlease provide the employee's age: ";
	int employeeAge;
	std::cin >> employeeAge;	// TODO: validate this
	
	//	Ask for salary
	std::cout << "\tPlease provide the employee's salary: ";
	int employeeSalary;
	std::cin >> employeeSalary;	// TODO: validate this

	//	Ask for bonus percentage
	std::cout << "\tPlease provide the employee's bonus percentage: ";
	int employeeBonus;
	std::cin >> employeeBonus;	// TODO: validate this

	//	get last employee id.
	Employee* newEmp = nullptr;
	if (_employeeList != nullptr)
	{
		auto lastEmployee = ReverseList();
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

	//	Print out employee "(Id) Name has been added".
	std::cout << "\tEmployee: " << " (" << newEmp->Id << ") " << newEmp->Name << " added successfully." << std::endl;
}

void Company::DisplayEmployee()
{
	if (_employeeList == nullptr)
	{
		std::cout << "\tThere is no employee data to display." << std::endl;
		return;
	}

	std::cout << "\tPlease provide the Id of the employee you wish to display: ";
	int id;
	std::cin >> id;	// TODO: validate this

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

	std::cout << "\tPlease provide the Id of the employee you wish to display: ";
	int id;
	std::cin >> id;	// TODO: validate this

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

	std::cout << "\tPlease provide the Id of the employee you wish to edit: ";
	int id;
	std::cin >> id;	// TODO: validate this

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


