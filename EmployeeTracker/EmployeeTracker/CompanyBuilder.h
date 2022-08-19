#pragma once
#include "Company.h"
class CompanyBuilder
{
private:
	std::string GetString(const std::string& prompt);
	bool IsPathExist(const std::string& s);
public:
	Company Create();
};

