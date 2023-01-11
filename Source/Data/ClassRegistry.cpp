#include"Data/ClassRegistry.h"
#include"Database/SqlConnector.h"

int cms::Data::ClassRegistry::MaxStudents = 30;

cms::Data::ClassRegistry::ClassRegistry(int _class)
{
	m_Class = _class;
}

void cms::Data::ClassRegistry::EditStudentByRoll(char new_name[], char new_address[], UINT roll)
{
	GetStudentByRoll(roll).EditDetails(new_name, new_address);
	m_Updated.push_back(roll);
}

std::vector<UINT>& cms::Data::ClassRegistry::GetAddedList()
{
	return m_NewAdded;
}

std::vector<UINT>& cms::Data::ClassRegistry::GetDeletedList()
{
	return m_Deleted;
}

std::vector<UINT>& cms::Data::ClassRegistry::GetUpdatedList()
{
	return m_Updated;
}

void cms::Data::ClassRegistry::UploadAddedDataToDatabase()
{
	for (int i = 0; i < m_NewAdded.size(); i++)
	{
		Student& student = m_Students[i];
		cms::Database::SqlConnector::GetInstance().Insert(student.GetID(), student.GetName(), student.GetAddress(), student.GetRoll(), m_Class);
	}
	m_NewAdded.clear();
}

void cms::Data::ClassRegistry::SyncDeletedDataWithDatabase()
{
}

void cms::Data::ClassRegistry::UpdateDataWithDatabase()
{
}

bool cms::Data::ClassRegistry::AddStudent(std::string name, int roll, std::string address, int _class, StudentAdditionType type)
{
	if (GetTotalStudents() > MaxStudents)
	{
		cms::Windows::PromptBox::Open("More than 30 students cannot be admitted", "Maximum students reached", MB_OK | MB_ICONWARNING);
	}
	else if (HasRollNo(roll))
	{
		std::string msg = "Student with Roll number " + std::to_string(roll) + " already exists";
	}
	else if (roll > MaxStudents)
	{
		std::string msg = "Roll number " + std::to_string(roll) + " isn't acceptable.";
		cms::Windows::PromptBox::Open(msg.c_str(), MB_OK | MB_ICONEXCLAMATION);
	}
	else
	{
		m_Students.emplace_back(name, roll, address);
		if (type != StudentAdditionType::DATABASE)
			m_NewAdded.push_back(roll);
		return true;
	}
	return false;
}

void cms::Data::ClassRegistry::RemoveStudent(int index)
{
	auto student = (m_Students.begin() + index);
	m_Students.erase(student);
	m_Deleted.push_back(student->GetRoll());
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

cms::Data::Student& cms::Data::ClassRegistry::GetStudentByRoll(int roll)
{
	for (Student& student : m_Students)
	{
		if (student.GetRoll() == roll)
			return student;
	}
}

UINT cms::Data::ClassRegistry::GetTotalStudents()
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
	int _totalStudentsInThisClass = random.RandInt(20, MaxStudents);
	for (int i = 0; i < _totalStudentsInThisClass; i++)
	{
		//This loop assigns roll number in ascending order
		for (int j = _totalStudentsInThisClass; j >= 1; j--)
		{
			if (!HasRollNo(j))
			{
				_roll = j;
				break;
			}
		}
		AddStudent(random.GetRandomName(), _roll, random.GetRandomPlace(), this->GetClass(),StudentAdditionType::RANDOMLY);
	}
	m_RandomlyFilled = true;
}

UINT cms::Data::ClassRegistry::GetClass()
{
	return m_Class;
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