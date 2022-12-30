#ifndef STUDENT_H
#define STUDENT_H

#include<iostream>

namespace cms::Data
{
	class Student
	{
	private:
		std::string m_Name, m_Address;
		int m_RollNo;
	public:
		Student(std::string name, int roll, std::string address);
		~Student();

		std::string GetName();
		std::string GetAddress();
		int GetRoll();
	};
}

#endif