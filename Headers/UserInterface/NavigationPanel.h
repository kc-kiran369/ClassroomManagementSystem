#ifndef NAVIGATION_PANEL
#define NAVIGATION_PANEL

#include"Panel.h"
#include"imgui/imgui.h"

namespace cms::UI
{
	class NavigationPanel : public Panel
	{
	private:
	public:
		void Draw() override;
		void SetRegistry(Data::StudentRegistry* Registry) override;
	};
}

#endif // !NAVIGATION_PANEL
