#include "..\..\Headers\UserInterface\SettingsPanel.h"

void cms::UI::SettingsPanel::Draw()
{
	ImGui::Begin("Settings");

	if (ImGui::TreeNodeEx("Database"))
	{
		if (ImGui::InputText("Server", m_TmpServerName, 12)) {}
		if (ImGui::InputText("User", m_TmpUser, 12)) {}
		if (ImGui::InputText("Password", m_TmpPassword, 12)) {}
		if (ImGui::InputText("Database", m_TmpDatabase, 12)) {}
		if (ImGui::InputText("Table", m_TmpTable, 12)) {}
		if (ImGui::Button("Connect To database"))
		{
			cms::Database::SqlConnector::GetInstance().Connect();
		}
		ImGui::TreePop();
	}

	ImGui::End();
}

void cms::UI::SettingsPanel::SetRegistry(Data::StudentRegistry* Registry)
{
}
