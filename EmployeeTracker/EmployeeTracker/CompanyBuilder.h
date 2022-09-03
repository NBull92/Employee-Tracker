#pragma once
#include "Company.h"
class CompanyBuilder
{
private:
	bool IsPathExist(const std::string& s);
public:
	Company* Create();
};

