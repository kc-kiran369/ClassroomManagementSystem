#include"Data/StudentRegistry.h"

using namespace cms;

StudentRegistry::StudentRegistry()
{
	
}

StudentRegistry::~StudentRegistry()
{
	
}

unsigned int StudentRegistry::GetTotalStudents()
{
	return (unsigned int)Class09.GetTotalStudents() +
		Class10.GetTotalStudents() +
		Class11.GetTotalStudents() +
		Class12.GetTotalStudents();
}