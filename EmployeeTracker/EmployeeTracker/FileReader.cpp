#include <iostream>
#include <fstream>
#include <filesystem>
#include "FileReader.h"

void FileReader::Read(std::string filename, Company* company)
{
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
            company->AddEmployee(employee);
        }

        file.close();
    }
}
