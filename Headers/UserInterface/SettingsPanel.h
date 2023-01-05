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
		char m_TmpServerName[12] = "127.0.0.1";
		char m_TmpUser[12] = "root";
		char m_TmpPassword[12] = "";
		char m_TmpDatabase[12] = "mydatabase";
		char m_TmpTable[12] = "student";
	public:
		void Draw() override;
		void SetRegistry(Data::StudentRegistry* Registry) override;
	};
}

#endif // !SETTINGS_PANEL
