#include"Data/StudentRegistry.h"

cms::Data::StudentRegistry::StudentRegistry()
{

}

cms::Data::StudentRegistry::~StudentRegistry()
{

}

unsigned int cms::Data::StudentRegistry::GetTotalStudents()
{
	return (unsigned int)Class09.GetTotalStudents() +
		Class10.GetTotalStudents() +
		Class11.GetTotalStudents() +
		Class12.GetTotalStudents();
}