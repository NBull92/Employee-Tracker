#include <iostream>
#include <fstream>
#include <filesystem>
#include <sys/stat.h>
#include "CompanyBuilder.h"
#include "FileReader.h"
#include "ConsoleUtils.h"

namespace fs = std::filesystem;

bool CompanyBuilder::IsPathExist(const std::string& s)
{
    struct stat buffer;
    return (stat(s.c_str(), &buffer) == 0);
}

Company* CompanyBuilder::Create()
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
            companyName = ConsoleUtils::GetString("\tPlease provide the company's name: ", false);
            return new Company(companyName);
        }
        else
        {
            Company* company = new Company(companyName);
            std::string filename = path + companyName + ext;

            FileReader().Read(filename, company);

            return company;
        }
    }
    else
    {
        companyName = ConsoleUtils::GetString("\tPlease provide the company's name: ", false);
        return new Company(companyName);
    }
}
