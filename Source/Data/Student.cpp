#include"Data/Student.h"

static int IdCount = 1;

cms::Data::Student::Student(std::string name, int roll, std::string address)
{
	m_ID = IdCount;
	IdCount++;
	m_Name = name;
	m_RollNo = roll;
	m_Address = address;
}

cms::Data::Student::~Student()
{

}

std::string& cms::Data::Student::GetName()
{
	return m_Name;
}

std::string& cms::Data::Student::GetAddress()
{
	return m_Address;
}

int cms::Data::Student::GetRoll()
{
	return m_RollNo;
}

int cms::Data::Student::GetID()
{
	return m_ID;
}

void cms::Data::Student::EditDetails(char new_name[], char new_address[])
{
	int n = 0;
	m_Name.clear();
	m_Address.clear();
	while (new_name[n] != '\0')
	{
		m_Name.push_back(new_name[n]);
		n++;
	}
	n = 0;
	while (new_address[n] != '\0')
	{
		m_Address.push_back(new_address[n]);
		n++;
	}
}