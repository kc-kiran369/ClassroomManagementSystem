#include"Data/ClassRegistry.h"

int cms::Data::ClassRegistry::MaxStudents = 48;

cms::Data::ClassRegistry::ClassRegistry()
{
	m_Students.clear();
}

bool cms::Data::ClassRegistry::AddStudent(std::string name, int roll, std::string address)
{
	if (GetTotalStudents() > 48)
	{
		cms::Windows::MessageBox::Open("More than 48 students cannot be admitted", "Maximum students reached", MB_OK | MB_ICONWARNING);
	}
	else if (HasRollNo(roll))
	{
		std::string msg = "Student with Roll number " + std::to_string(roll) + " already exists";
		cms::Windows::MessageBox::Open(msg.c_str(), "Student Cannot be admitted!!", MB_OK | MB_ICONEXCLAMATION);
	}
	else
	{
		m_Students.emplace_back(name, roll, address);

		m_Changes = CHANGES::STUDENT_ADD;

		return true;
	}
	return false;
}

void cms::Data::ClassRegistry::RemoveStudent(int index)
{
	//m_Changes = m_Changes | CHANGES::STUDENT_REMOVE;
	m_Students.erase(m_Students.begin() + index);
}

cms::Data::Student cms::Data::ClassRegistry::GetStudentAt(int index)
{
	return m_Students.at(index);
}

unsigned int cms::Data::ClassRegistry::GetTotalStudents()
{
	std::vector<int>::size_type size = m_Students.size();
	return size;
}

void cms::Data::ClassRegistry::FillWithRandomStudents()
{
	FillRandom random;
	int _roll = 1;
	int _totalStudentsInThisClass = random.RandInt(35, MaxStudents);
	for (int i = 0; i < _totalStudentsInThisClass; i++)
	{
		//This loop is to assign roll number
		for (int j = _totalStudentsInThisClass; j >= 1; j--)
		{
			if (HasRollNo(j))
				continue;
			else
				_roll = j;
		}
		AddStudent(random.GetRandomText(random.RandInt(4, 7)), _roll, random.GetRandomText(random.RandInt(4, 12)));
	}
}

bool cms::Data::ClassRegistry::HasRollNo(int roll)
{
	for (Student& student : m_Students)
	{
		if (student.GetRoll() == roll)
			return true;
	}
	return false;
}