#ifndef CLASS_REG_H
#define CLASS_REG_H

#include<iostream>
#include<vector>
#include<string>
#include"Student.h"
#include"Windows/MessageBox.h"

#include<fstream>
#include <chrono>
#include <random>

namespace cms::Data
{
	class FillRandom
	{
	private:
		std::string m_TmpName;
		std::vector<std::string> names;
		std::vector<std::string> surnames;
		std::vector<std::string> places;
	public:
		~FillRandom()
		{
			names.clear();
			surnames.clear();
			places.clear();
		}
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
		std::string GetRandomName()
		{
			std::ifstream in;
			in.open("Resources/Data/names.txt");

			if (in.fail())
			{
				return GetRandomText(5);
			}
			else
			{
				std::string line;
				while (std::getline(in, line))
				{
					if (line.size() != 0)
						names.push_back(line);
				}
				in.close();

				in.open("Resources/Data/surnames.txt");
				while (std::getline(in, line))
				{
					if (line.size() != 0)
						surnames.push_back(line);
				}
				in.close();
				return names[RandInt(0, (int)names.size())] + " " + surnames[RandInt(0, (int)surnames.size())];
			}
		}

		std::string GetRandomPlace()
		{
			std::ifstream in;
			in.open("Resources/Data/places.txt");
			std::string line;
			while (std::getline(in, line))
			{
				if (line.size() != 0)
					places.push_back(line);
			}
			in.close();
			if (places.size() == 0)
				return GetRandomText(9);
			else
				return places[RandInt(0, (int)places.size())];
		}
	};

	class ClassRegistry
	{
	private:
		std::vector<Student> m_Students;
		bool m_RandomlyFilled = false;
	public:
		ClassRegistry();

		static int MaxStudents;

		bool AddStudent(std::string name, int roll, std::string address);
		void RemoveStudent(int index);
		void RemoveStudentByRoll(int roll);
		unsigned int GetTotalStudents();
		Student& GetStudentAt(int index);

		void FillWithRandomStudents();
		bool HasRollNo(int roll);
	};
}
#endif