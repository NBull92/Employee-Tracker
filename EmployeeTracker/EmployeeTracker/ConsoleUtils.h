#pragma once
#include <iostream>
#include <string.h>

class ConsoleUtils
{
public:
	static std::string GetString(const std::string& prompt, bool ignorePrevious);
	static int GetNumber(const std::string& prompt);
};

