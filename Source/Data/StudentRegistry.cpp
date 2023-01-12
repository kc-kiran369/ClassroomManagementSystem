#include"Data/StudentRegistry.h"

cms::Data::StudentRegistry::StudentRegistry()
{

}

cms::Data::StudentRegistry::~StudentRegistry()
{

}

void cms::Data::StudentRegistry::FillWithRandomData()
{
	Class09.FillWithRandomStudents();
	Class10.FillWithRandomStudents();
	Class11.FillWithRandomStudents();
	Class12.FillWithRandomStudents();
}

UINT cms::Data::StudentRegistry::GetTotalStudents()
{
	return (UINT)Class09.GetTotalStudents() + Class10.GetTotalStudents() + Class11.GetTotalStudents() + Class12.GetTotalStudents();
}