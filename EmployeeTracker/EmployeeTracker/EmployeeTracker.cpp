#include <iostream>
#include "Company.h"

int main()
{
    // Creating automatic storage object
    Company company = Company("CompanyX");

    //  Get user input a number between 0 and X. X being the amount of options. For extensibility, let 0 be quit.
    
    int option = 100;
    while (option != 0)
    {
        std::cout << company.Name << "Employee Tracker!\n";
        std::cout << "\n\n*************************************";
        std::cout << "\n\t1.Add Employee.";
        std::cout << "\n\t2.Display Employee.";
        std::cout << "\n\t3.Search By id.";
        std::cout << "\n\t4.Delete by Id.";
        std::cout << "\n\t5.Edit Employee data.";
        std::cout << "\n\t6.Display All Employees.";
        std::cout << "\n\t0.Exit";
        std::cout << "\n*************************************\n\n";
        std::cout << "\n\tEnter the choice: ";
        std::cin >> option;

        switch (option)
        {
        case 1:
            company.AddEmployee();
            break;
        /*case 2:
            company.DisplayEmployee();
            break;
        case 3:
            company.SearchEmployeeById();
            break;
        case 4:
            company.DeleteEmployeeById();
            break;
        case 5:
            company.EditEmployeeById();
            break;
        case 6:
            company.DisplayAllEmployees();
            break;*/
        default:
            std::cout << "Invalid input.";
            break;
        }
    }
}

//  A class for the company. This will be instantiated in the main. But if the app was real, it could be generic company employee tracker
//  Create a linked list of employees. 
//  - Try to show case linked list knowledge to traverse, delete a node within the list, search the list, reverse the list (if you want to see employees in desc name order etc.


// A class for employee
//  - Name
//  - Age
//  - Salary
//  - Bonus
