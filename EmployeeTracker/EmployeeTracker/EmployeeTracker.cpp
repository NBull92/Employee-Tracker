#include <iostream>

#include "Company.h"
#include "CompanyBuilder.h"
#include "EmployeeTracker.h"


int main()
{
    Company company = CompanyBuilder().Create();
            
    int option = 100;
    while (option != 0)
    {
        std::cout << "\n" << company.Name << " Employee Tracker!\n";
        std::cout << "\n\n*************************************";
        std::cout << "\n\t1.Add Employee.";
        std::cout << "\n\t2.Display Employee.";        
        std::cout << "\n\t3.Delete Employee by Id.";
        std::cout << "\n\t4.Edit Employee data.";
        std::cout << "\n\t5.Display All Employees.";
        std::cout << "\n\t6.Save.";
        std::cout << "\n\t0.Exit";
        std::cout << "\n*************************************\n\n";
        std::cout << "\n\tEnter the choice: ";
        std::cin >> option;

        switch (option)
        {
        case 0:
            break;
        case 1:
            company.AddEmployee();
            break;
        case 2:
            company.DisplayEmployee();
            break;
        case 3:
            company.DeleteEmployee();
            break;
        case 4:
            company.EditEmployee();
            break;
        case 5:
            company.DisplayEmployees();
            break;
        case 6:
            company.Save();
            break;
        default:
            std::cout << "Invalid input." << std::endl;
            break;
        }
    }
}