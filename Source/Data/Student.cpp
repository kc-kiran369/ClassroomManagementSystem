#include"Data/Student.h"

Student::Student(std::string name, int roll, std::string address)
{
	m_Name = name;
	m_RollNo = roll;
	m_Address = address;
}

Student::~Student()
{

}

std::string Student::GetName()
{
	return m_Name;
}

std::string Student::GetAddress()
{
	return m_Address;
}

int Student::GetRoll()
{
	return m_RollNo;
}
