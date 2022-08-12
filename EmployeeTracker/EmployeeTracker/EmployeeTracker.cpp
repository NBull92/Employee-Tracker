#include <iostream>
#include "Company.h"
#include "EmployeeTracker.h"

int main()
{
    //  create a class that will look for a company file in %AppData%/EmployeeTracker
    //  It must look for the %AppData%/EmployeeTracker directory
    //  If this doesn't exist, then it should create it. And then create a new Compony object and return that. This must ask the user for a company name.
    //  If the directory exists and there is no file. then create a new Compony object and return that. This must ask the user for a company name.
    //  If there is a file, then read in the csv file and create a Company object based off of the files data and return that.
    

    // Creating automatic storage object
    Company company = Company("CompanyX");
        
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