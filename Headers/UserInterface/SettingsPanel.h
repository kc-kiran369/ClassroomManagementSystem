#ifndef SETTINGS_PANEL
#define SETTINGS_PANEL

#include"imgui/imgui.h"
#include"UserInterface/Panel.h"
#include"Database/SqlConnector.h"

namespace cms::UI
{
	class SettingsPanel : public  Panel
	{
	private:
	public:
		SettingsPanel();
		~SettingsPanel();

		void Draw() override;
		void SetRegistry(Data::StudentRegistry* Registry) override;
	};
}

#endif // !SETTINGS_PANEL
