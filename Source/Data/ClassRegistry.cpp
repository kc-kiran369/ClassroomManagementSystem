#include"Data/ClassRegistry.h"
#include"Database/SqlConnector.h"

int cms::Data::ClassRegistry::MaxStudents = 48;

cms::Data::ClassRegistry::ClassRegistry()
{

}

bool cms::Data::ClassRegistry::AddStudent(std::string name, int roll, std::string address)
{
	if (GetTotalStudents() > 48)
	{
		cms::Windows::PromptBox::Open("More than 48 students cannot be admitted", "Maximum students reached", MB_OK | MB_ICONWARNING);
	}
	else if (HasRollNo(roll))
	{
		std::string msg = "Student with Roll number " + std::to_string(roll) + " already exists";
	}
	else if (roll > 48)
	{
		std::string msg = "Roll number " + std::to_string(roll) + " isn't acceptable.";
		cms::Windows::PromptBox::Open(msg.c_str(), MB_OK | MB_ICONEXCLAMATION);
	}
	else
	{
		m_Students.emplace_back(name, roll, address);
		//cms::Database::SqlConnector::GetInstance().Insert(name, address, roll);
		return true;
	}
	return false;
}

void cms::Data::ClassRegistry::RemoveStudent(int index)
{
	m_Students.erase(m_Students.begin() + index);
}

void cms::Data::ClassRegistry::RemoveStudentByRoll(int roll)
{
	for (int i = 0; i < m_Students.size(); i++)
	{
		if (m_Students[i].GetRoll() == roll)
		{
			RemoveStudent(i);
			break;
		}
	}
}

cms::Data::Student& cms::Data::ClassRegistry::GetStudentAt(int index)
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
	if (m_RandomlyFilled)
		return;

	FillRandom random;
	int _roll = 1;
	int _totalStudentsInThisClass = random.RandInt(30, MaxStudents);
	for (int i = 0; i < _totalStudentsInThisClass; i++)
	{
		//This loop is to assign roll number
		//Assign in ascending order
		for (int j = _totalStudentsInThisClass; j >= 1; j--)
		{
			if (HasRollNo(j))
				continue;
			else
			{
				_roll = j;
				break;
			}
		}
		AddStudent(random.GetRandomName(), _roll, random.GetRandomPlace());
	}

	m_RandomlyFilled = true;
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