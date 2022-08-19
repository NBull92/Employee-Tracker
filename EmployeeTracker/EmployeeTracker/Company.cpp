#include <iostream>
#include <fstream>
#include "Company.h"
#include "Employee.h"

using namespace std;

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

string Company::GetString(const string& prompt)
{
	string result;
	while (true)
	{
		//	Ask user for a name
		cout << prompt;
		cin >> result;	// this doesn't allow for spaces	// TODO: validate this	
		//std::getline(std::cin, employeeName); // this jumps straight to asking for age.	// TODO: validate this
		//std::cin.ignore(numeric_limits<streamsize>::max, '\n');

		if (cin.fail())
		{
			cout << "Enter a valid string!" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}
		else
		{
			break;
		}
	}

	return result;
}

int Company::GetNumber(const std::string& prompt)
{
	int result;
	while (true)
	{
		cout << prompt;
		cin >> result;	// this doesn't allow for spaces	// TODO: validate this	
		//std::getline(std::cin, employeeName); // this jumps straight to asking for age.	// TODO: validate this
		//std::cin.ignore(numeric_limits<streamsize>::max, '\n');

		if (cin.fail())
		{
			cout << "Enter a valid number!" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}
		else
		{
			break;
		}
	}

	return result;
}

Company::Company(std::string name) : Name(name), _employeeList(nullptr) { }

void Company::AddEmployee()
{
	auto employeeName = GetString("\tPlease provide the employee's name: ");
	auto employeeAge = GetNumber("\tPlease provide the employee's age: ");
	auto employeeSalary = GetNumber("\tPlease provide the employee's salary: ");
	auto employeeBonus = GetNumber("\tPlease provide the employee's bonus percentage: ");

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

void Company::Save()
{
	//	maybe encapsulate this in another class that handles file saving. 
	//	pass in this company as a parameter.member

	char* appdata;
	size_t len;
	errno_t err = _dupenv_s(&appdata, &len, "APPDATA");

	std::cout << appdata << std::endl;

	std::string path = std::string(appdata) + "\\EmployeeTracker\\";
	std::string filename = path + Name + ".csv";
	
	std::cout << filename << std::endl;

	ofstream file;
	file.open(filename);

	if (file.is_open())
	{
		file << "id,name,age,salary,bonus\n";	//	We could use 'endl' here. But the buffer is flushed everytime the endl is called. 
												//	Where as if we only use \n here. The buffer is only flushed, once everything is written to the stream. 
												//	This is because the string here isn't written to the file straight away. It's stored in memory until this is completed. Then it's sent to the file stream..
		auto node = _employeeList;

		while (node != nullptr)
		{
			file << node->Print() << "\n";
			node = node->Next;
		}
		file.close();
	}
	if (file.fail())
	{
		std::cout << "Save unsuccessful!" << endl;
	}
	else
	{
		std::cout << "Saved Successfully!" << endl;
	}
}

