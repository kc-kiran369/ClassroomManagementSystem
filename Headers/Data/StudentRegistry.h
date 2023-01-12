#ifndef STUDENT_REG_H
#define STUDENT_REG_H

#include<iostream>
#include<vector>
#include"ClassRegistry.h"

namespace cms::Data
{
	enum class CLASS { NINE = 9, TEN, ELEVEN, TWELVE };

	class StudentRegistry
	{
	public:
		StudentRegistry();
		~StudentRegistry();

		ClassRegistry Class09 = ClassRegistry((int)CLASS::NINE);
		ClassRegistry Class10 = ClassRegistry((int)CLASS::TEN);
		ClassRegistry Class11 = ClassRegistry((int)CLASS::ELEVEN);
		ClassRegistry Class12 = ClassRegistry((int)CLASS::TWELVE);

		void FillWithRandomData();
		UINT GetTotalStudents();
	};
}

#endif