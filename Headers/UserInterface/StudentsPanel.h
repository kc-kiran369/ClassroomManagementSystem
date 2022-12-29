#ifndef STUDENTS_PANEL
#define STUDENTS_PANEL

#include"imgui/imgui.h"

#include "Data/StudentRegistry.h"

namespace cms
{
	class StudentsPanel
	{
	private:
		bool m_PanelEnabled = true;
	public:
		void Draw(StudentRegistry* registry);
	};
}

#endif