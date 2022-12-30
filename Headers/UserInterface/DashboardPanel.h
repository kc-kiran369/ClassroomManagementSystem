#ifndef DAHSBOARD_PANEL
#define DAHSBOARD_PANEL

#include"imgui/imgui.h"
#include "Data/StudentRegistry.h"
#include"Panel.h"

namespace cms::UI
{
	class DashboardPanel : public Panel
	{
	private:
		bool m_PanelEnabled = true;
		bool m_HistogramView = true;
	public:
		DashboardPanel() = default;
		DashboardPanel(Data::StudentRegistry* registry);
		~DashboardPanel();

		void Draw() override;
		void SetRegistry(Data::StudentRegistry* Registry) override;
	};
}

#endif