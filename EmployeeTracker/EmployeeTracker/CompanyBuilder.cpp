#include <iostream>
#include <fstream>
#include <filesystem>
#include <sys/stat.h>
#include "CompanyBuilder.h"

namespace fs = std::filesystem;

std::string CompanyBuilder::GetString(const std::string& prompt)
{
    std::string result;
        while (true)
        {
            //	Ask user for a name
            std::cout << prompt;
            std::cin >> result;	// this doesn't allow for spaces	// TODO: validate this	
            //std::getline(std::cin, employeeName); // this jumps straight to asking for age.	// TODO: validate this
            //std::cin.ignore(numeric_limits<streamsize>::max, '\n');
    
            if (std::cin.fail())
            {
                std::cout << "Enter a valid string!" << std::endl;
                std::cin.clear();
                std::cin.ignore(1000, '\n');
            }
            else
            {
                break;
            }
        }
    
        return result;
}

bool CompanyBuilder::IsPathExist(const std::string& s)
{
    struct stat buffer;
    return (stat(s.c_str(), &buffer) == 0);
}

Company CompanyBuilder::Create()
{
    char* appdata;
    size_t len;
    errno_t err = _dupenv_s(&appdata, &len, "APPDATA");

    std::string path = std::string(appdata) + "\\EmployeeTracker\\";
    
    std::string companyName;
    if (IsPathExist(path))
    {
        std::string ext(".csv");
        for (auto& p : fs::recursive_directory_iterator(path))
        {
            if (p.path().extension() == ext)
                companyName += p.path().stem().string();
        }

        if (companyName == "")
        {
            companyName = GetString("\tPlease provide the company's name: ");
            return Company(companyName);
        }
        else
        {
            // Creating automatic storage object
            Company company = Company(companyName);
            std::string filename = path + companyName + ext;

            std::ifstream file;
            file.open(filename);
            if (file.is_open())
            {
                std::string str;
                std::getline(file, str);
                while (!file.eof())
                {
                    std::getline(file, str, ',');

                    if (str.empty())
                        continue;

                    int id = stoi(str);

                    std::getline(file, str, ',');
                    std::string name = str;

                    std::getline(file, str, ',');
                    int age = stoi(str);

                    std::getline(file, str, ',');
                    int salary = stoi(str);

                    std::getline(file, str);
                    int bonus = stoi(str);

                    Employee* employee = new Employee(id, name, age, salary, bonus);
                    company.AddEmployee(employee);
                }

                file.close();
            }

            return company;
        }
    }
    else
    {
        companyName = GetString("\tPlease provide the company's name: ");
        return Company(companyName);
    }
}
