#include"Data/ClassRegistry.h"

int ClassRegistry::MaxStudents = 48;

ClassRegistry::ClassRegistry()
{
	m_Students.clear();
}

void ClassRegistry::AddStudent(std::string name, int roll, std::string address)
{
	if (GetTotalStudents() > 48)
	{

	}
	else
	{
		m_Students.emplace_back(name, roll, address);
	}
}

void ClassRegistry::RemoveStudent()
{

}

Student ClassRegistry::GetStudentAt(int index)
{
	return m_Students.at(index);
}

unsigned int ClassRegistry::GetTotalStudents()
{
	std::vector<int>::size_type size = m_Students.size();
	return size;
}