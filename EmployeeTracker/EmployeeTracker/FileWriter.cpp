#include <iostream>
#include <fstream>
#include "FileWriter.h"

void FileWriter::Write(std::string companyName, EmployeeNode* employeeList)
{
	char* appdata;
	size_t len;
	errno_t err = _dupenv_s(&appdata, &len, "APPDATA");

	std::string path = std::string(appdata) + "\\EmployeeTracker\\";
	std::string filename = path + companyName + ".csv";

	std::ofstream file;
	file.open(filename);

	if (file.is_open())
	{
		file << "id,name,age,salary,bonus\n";	//	We could use 'endl' here. But the buffer is flushed everytime the endl is called. 
												//	Where as if we only use \n here. The buffer is only flushed, once everything is written to the stream. 
												//	This is because the string here isn't written to the file straight away. It's stored in memory until this is completed. Then it's sent to the file stream..
		auto node = employeeList;

		while (node != nullptr)
		{
			file << node->Print() << "\n";
			node = node->Next;
		}
		file.close();
	}
	if (file.fail())
	{
		std::cout << "Save unsuccessful!" << std::endl;
	}
	else
	{
		std::cout << "Saved Successfully!" << std::endl;
	}
}
