#include"Data/Student.h"

cms::Data::Student::Student(std::string name, int roll, std::string address)
{
	m_Name = name;
	m_RollNo = roll;
	m_Address = address;
}

cms::Data::Student::~Student()
{

}

std::string cms::Data::Student::GetName()
{
	return m_Name;
}

std::string cms::Data::Student::GetAddress()
{
	return m_Address;
}

int cms::Data::Student::GetRoll()
{
	return m_RollNo;
}
