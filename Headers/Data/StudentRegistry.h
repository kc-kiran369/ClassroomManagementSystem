#ifndef STUDENT_REG_H
#define STUDENT_REG_H

#include<iostream>
#include<vector>
#include"ClassRegistry.h"

class StudentRegistry
{
public:
	StudentRegistry();
	~StudentRegistry();
	ClassRegistry Class09;
	ClassRegistry Class10;
	ClassRegistry Class11;
	ClassRegistry Class12;

	unsigned int GetTotalStudents();
};

#endif