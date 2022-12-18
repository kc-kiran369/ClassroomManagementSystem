#ifndef CLASS_REG_H
#define CLASS_REG_H

#include<iostream>
#include<vector>
#include"Student.h"

class ClassRegistry
{
private:
	std::vector<Student> m_Students;
public:
	static int MaxStudents;

	ClassRegistry();
	void AddStudent(std::string name, int roll, std::string address);
	void RemoveStudent();

	Student GetStudentAt(int index);

	unsigned int GetTotalStudents();
};

#endif