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
#include<string_view>

namespace cms::Data
{
	enum StudentAdditionType
	{
		RANDOMLY,
		ADMISSION,
		DATABASE
	};

	class FillRandom
	{
	private:
		std::string m_TmpName;
		std::vector<std::string> names;
		std::vector<std::string> surnames;
		std::vector<std::string> places;
		bool m_DataImported = false;

		void ImportData()
		{
			if (m_DataImported)
				return;

			std::ifstream in;
			std::string line;

			in.open("Resources/Data/names.txt");
			if (!in.fail())
			{
				while (std::getline(in, line))
				{
					if (line.size() != 0)
						names.push_back(line);
				}
				in.close();
			}

			in.open("Resources/Data/surnames.txt");
			if (!in.fail())
			{
				while (std::getline(in, line))
				{
					if (line.size() != 0)
						surnames.push_back(line);
				}
				in.close();
			}

			in.open("Resources/Data/places.txt");
			if (!in.fail())
			{
				while (std::getline(in, line))
				{
					if (line.size() != 0)
						places.push_back(line);
				}
				in.close();
			}

			m_DataImported = true;
		}

	public:
		FillRandom()
		{
			ImportData();
		}
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
			if (names.size() == 0)
				return GetRandomText(6);
			else
				return names[RandInt(0, (int)names.size() - 1)] + " " + surnames[RandInt(0, (int)surnames.size() - 1)];
		}

		std::string GetRandomPlace()
		{
			if (places.size() == 0)
				return GetRandomText(9);
			else
				return places[RandInt(0, (int)places.size() - 1)];
		}
	};

	class ClassRegistry
	{
	private:
		std::vector<Student> m_Students;
		bool m_RandomlyFilled = false;
		int m_Class;

		std::vector<UINT> m_NewAdded;
		std::vector<UINT> m_Updated;
		std::vector<UINT> m_Deleted;
	public:
		ClassRegistry(int _class);

		static int MaxStudents;

		UINT GetClass();
		void RemoveStudent(int index);
		void RemoveStudentByRoll(int roll);
		UINT GetTotalStudents();
		Student& GetStudentAt(int index);
		Student& GetStudentByRoll(int roll);
		void EditStudentByRoll(char new_name[], char new_address[], UINT roll);

		/// <summary>
		/// Adds the student in the registry
		/// </summary>
		/// <param name="name">Name of the student.</param>
		/// <param name="roll">Roll number of the student.</param>
		/// <param name="address">Address of the student.</param>
		/// <param name="_class">Class of the student.</param>
		/// <param name="type">How the student is added. i,e. Admission/Randomly Filled/Retrived From Database</param>
		/// <returns>Return true if student is added to registry.</returns>
		bool AddStudent(std::string name, int roll, std::string address, int _class,StudentAdditionType type);

		/// <summary>
		/// Returns the reference to vector which contains all the roll number of the student who were newly added
		/// </summary>
		/// <returns>A Reference to vector of int</returns>
		std::vector<unsigned int>& GetAddedList();
		/// <summary>
		/// Returns the reference to vector which contains all the roll number of the student who were deleted from registry
		/// </summary>
		/// <returns>A Reference to vector of int</returns>
		std::vector<unsigned int>& GetDeletedList();
		/// <summary>
		/// Returns the reference to vector which contains all the roll number of the student whose data were updated
		/// </summary>
		/// <returns>A Reference to vector of int</returns>
		std::vector<unsigned int>& GetUpdatedList();

		void FillWithRandomStudents();
		bool HasRollNo(int roll);

		void UploadAddedDataToDatabase();
		void SyncDeletedDataWithDatabase();
		void UpdateDataWithDatabase();
	};
}
#endif