#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

namespace cms::Data
{
	class Student
	{
	private:
		std::string m_Name, m_Address;
		int m_RollNo, m_ID;
	public:
		Student(std::string name, int roll, std::string address);
		Student(unsigned int id, std::string name, int roll, std::string address);
		~Student();

		std::string& GetName();
		std::string& GetAddress();
		int GetRoll();
		int GetID();

		void EditDetails(char new_name[], char new_address[]);
	};
}

#endif