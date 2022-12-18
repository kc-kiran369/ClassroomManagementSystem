#include"Data/StudentRegistry.h"

StudentRegistry::StudentRegistry()
{
	std::cout << "Studnt reg start" << std::endl;
}

StudentRegistry::~StudentRegistry()
{
	std::cout << "Studnt reg end" << std::endl;
}

unsigned int StudentRegistry::GetTotalStudents()
{
	return (unsigned int)Class09.GetTotalStudents() + 
		   Class10.GetTotalStudents() + 
		   Class11.GetTotalStudents() + 
		   Class12.GetTotalStudents();
}