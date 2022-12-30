#ifndef STUDENTS_PANEL
#define STUDENTS_PANEL

#include"imgui/imgui.h"
#include "Data/StudentRegistry.h"
#include"Panel.h"

namespace cms::UI
{
	class StudentsPanel : public Panel
	{
	private:
		void DrawTable(int _class);
	public:
		StudentsPanel() = default;
		StudentsPanel(Data::StudentRegistry* registry);
		~StudentsPanel();

		void Draw() override;
		void SetRegistry(Data::StudentRegistry* Registry) override;
	};
}
#endif