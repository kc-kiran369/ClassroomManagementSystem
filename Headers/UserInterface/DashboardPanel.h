#ifndef DAHSBOARD_PANEL
#define DAHSBOARD_PANEL

#include"imgui/imgui.h"

#include "Data/StudentRegistry.h"

namespace cms
{
	class DashboardPanel
	{
	private:
		bool m_PanelEnabled = true;
		bool m_HistogramView = true;
	public:
		void Draw(StudentRegistry* registry);
	};
}

#endif