#include <iostream>
#include <string>
#include "ConsoleUtils.h"

std::string ConsoleUtils::GetString(const std::string& prompt, bool ignorePrevious)
{
	std::cin.clear();
	if(ignorePrevious)
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::string result;
	while (true)
	{
		//	Ask user for a name
		std::cout << prompt;
		std::getline(std::cin, result);

		if (std::cin.fail() || result == "")
		{
			std::cout << "Enter a valid string!" << std::endl;
			std::cin.clear();
		}
		else
		{
			break;
		}
	}

	return result;
}


int ConsoleUtils::GetNumber(const std::string& prompt)
{
	int result = -1;
	while (true)
	{
		std::cout << prompt;
		std::cin >> result;

		if (std::cin.fail())
		{
			std::cout << "Enter a valid number!" << std::endl;
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