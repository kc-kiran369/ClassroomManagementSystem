#include "UserInterface\SettingsPanel.h"

static ImVec4 Red(1.0f, 0.0f, 0.0f, 1.0f);
static ImVec4 Green(0.0f, 1.0f, 0.0f, 1.0f);
static ImVec4 Blue(0.0f, 0.0f, 1.0f, 1.0f);

cms::UI::SettingsPanel::SettingsPanel()
{

}

cms::UI::SettingsPanel::~SettingsPanel()
{

}

void cms::UI::SettingsPanel::Draw()
{
	const bool& status = Database::SqlConnector::GetInstance().GetConnectionStatus();
	ImGui::Begin("Settings", &m_PanelEnabled, ImGuiWindowFlags_NoCollapse);

	if (ImGui::TreeNodeEx("Database", ImGuiTreeNodeFlags_Framed))
	{
		ImGui::Text("Database Status : ");
		ImGui::SameLine();
		ImGui::TextColored((status ? Green : Red), (status ? "Connected" : "Not Connected"));

		if (ImGui::TreeNodeEx("Database Info", ImGuiTreeNodeFlags_Framed))
		{
			ImGuiInputTextFlags flag = (status ? ImGuiInputTextFlags_ReadOnly : ImGuiInputTextFlags_None);

			if (ImGui::InputText("Server", Database::SqlConnector::GetInstance().GetDatabaseInfo().server, 15, flag))
			{

			}
			if (ImGui::InputText("User", Database::SqlConnector::GetInstance().GetDatabaseInfo().username, 15, flag))
			{

			}
			if (ImGui::InputText("Password", Database::SqlConnector::GetInstance().GetDatabaseInfo().password, 15, flag))
			{

			}
			if (ImGui::InputText("Database", Database::SqlConnector::GetInstance().GetDatabaseInfo().database, 15, flag))
			{

			}
			if (ImGui::InputText("Table", Database::SqlConnector::GetInstance().GetDatabaseInfo().table, 15, flag))
			{

			}
			if (!status)
			{
				if (ImGui::Button("Connect To database"))
				{
					if (cms::Database::SqlConnector::GetInstance().GetConnectionStatus())
						cms::Windows::PromptBox::Open("Connection with Database already established", MB_OK | MB_ICONEXCLAMATION);
					else
					{
						cms::Database::SqlConnector::GetInstance().Connect();
					}
				}
			}
			ImGui::TreePop();
		}

		if (ImGui::TreeNodeEx("Updates", ImGuiTreeNodeFlags_Framed))
		{
			if (ImGui::TreeNodeEx("Added", ImGuiTreeNodeFlags_Framed))
			{
				ImGui::Text("%d new added students in class 9", m_Registry->Class09.GetAddedList().size());
				ImGui::Text("%d new added students in class 10", m_Registry->Class10.GetAddedList().size());
				ImGui::Text("%d new added students in class 11", m_Registry->Class11.GetAddedList().size());
				ImGui::Text("%d new added students in class 12", m_Registry->Class12.GetAddedList().size());
				if (ImGui::Button("Upload New Data to database"))
				{
					if (status)
					{
						m_Registry->Class09.UploadAddedDataToDatabase();
						m_Registry->Class10.UploadAddedDataToDatabase();
						m_Registry->Class11.UploadAddedDataToDatabase();
						m_Registry->Class12.UploadAddedDataToDatabase();
					}
				}
				ImGui::TreePop();
			}

			if (ImGui::TreeNodeEx("Deleted", ImGuiTreeNodeFlags_Framed))
			{
				ImGui::Text("%d students were deleted in class 9", m_Registry->Class09.GetDeletedList().size());
				ImGui::Text("%d students were deleted in class 10", m_Registry->Class10.GetDeletedList().size());
				ImGui::Text("%d students were deleted in class 11", m_Registry->Class11.GetDeletedList().size());
				ImGui::Text("%d students were deleted in class 12", m_Registry->Class12.GetDeletedList().size());
				if (ImGui::Button("Sync database with deleted students"))
				{
					if (status)
					{
						m_Registry->Class09.SyncDeletedDataWithDatabase();
						m_Registry->Class10.SyncDeletedDataWithDatabase();
						m_Registry->Class11.SyncDeletedDataWithDatabase();
						m_Registry->Class12.SyncDeletedDataWithDatabase();
					}
				}
				ImGui::TreePop();
			}

			if (ImGui::TreeNodeEx("Updated", ImGuiTreeNodeFlags_Framed))
			{
				ImGui::Text("%d students were updated in class 9", m_Registry->Class09.GetUpdatedList().size());
				ImGui::Text("%d students were updated in class 10", m_Registry->Class10.GetUpdatedList().size());
				ImGui::Text("%d students were updated in class 11", m_Registry->Class11.GetUpdatedList().size());
				ImGui::Text("%d students were updated in class 12", m_Registry->Class12.GetUpdatedList().size());
				if (ImGui::Button("Update database with new information"))
				{
					if (status)
					{
						m_Registry->Class09.UpdateDataWithDatabase();
						m_Registry->Class10.UpdateDataWithDatabase();
						m_Registry->Class11.UpdateDataWithDatabase();
						m_Registry->Class12.UpdateDataWithDatabase();
					}
				}
				ImGui::TreePop();
			}

			ImGui::TreePop();
		}

		if (ImGui::Button("Get Data From Database"))
		{
			Database::SqlConnector::GetInstance().Retrieve(m_Registry);
		}

		ImGui::TreePop();
	}
	ImGui::End();
}

void cms::UI::SettingsPanel::SetRegistry(Data::StudentRegistry* Registry)
{
	m_Registry = Registry;
}