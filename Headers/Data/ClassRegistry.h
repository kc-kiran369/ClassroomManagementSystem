#ifndef CLASS_REG_H
#define CLASS_REG_H

#include<iostream>
#include<vector>
#include"Student.h"
#include"Windows/MessageBox.h"

namespace cms
{
	class FillRandom
	{
	private:
		std::string m_TmpName;
	public:
		int RandInt(int low, int high)
		{
			return low + rand() % (high - low + 1);
		}
		std::string GetRandomText(int length)
		{
			m_TmpName.clear();
			for (int i = 0; i < length; i++)
			{
				m_TmpName.push_back(RandInt('a', 'z'));
			}
			return m_TmpName;
		}
	};

	class ClassRegistry
	{
	private:
		std::vector<Student> m_Students;
	public:
		static int MaxStudents;

		ClassRegistry();
		bool AddStudent(std::string name, int roll, std::string address);
		void RemoveStudent();

		Student GetStudentAt(int index);

		unsigned int GetTotalStudents();

		void FillWithRandomStudents();

		bool HasRollNo(int roll);
	};
}

#endif