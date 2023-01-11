#include "UserInterface\SettingsPanel.h"

cms::UI::SettingsPanel::SettingsPanel()
{

}

cms::UI::SettingsPanel::~SettingsPanel()
{

}

void cms::UI::SettingsPanel::Draw()
{
	ImGui::Begin("Settings");

	if (ImGui::TreeNodeEx("Database", ImGuiTreeNodeFlags_Framed))
	{
		ImGui::Text("Database Status : ");
		ImGui::SameLine();
		bool status = Database::SqlConnector::GetInstance().GetConnectionStatus();
		ImGui::TextColored((status ? ImVec4(0.0f, 1.0f, 0.0f, 1.0f) : ImVec4(1.0f, 0.0f, 0.0f, 1.0f)), (status ? "Connected" : "Not Connected"));
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
			ImGui::Text("Updates");

			if (ImGui::TreeNodeEx("New Added", ImGuiTreeNodeFlags_Framed))
			{
				if (ImGui::TreeNodeEx("Class 9", ImGuiTreeNodeFlags_Framed))
				{
					for (unsigned int roll : m_Registry->Class09.GetAddedList())
					{
						ImGui::Text(m_Registry->Class09.GetStudentByRoll(roll).GetName().c_str());
					}
					ImGui::TreePop();
				}
				if (ImGui::TreeNodeEx("Class 10", ImGuiTreeNodeFlags_Framed))
				{
					for (unsigned int roll : m_Registry->Class10.GetAddedList())
					{
						ImGui::Text(m_Registry->Class10.GetStudentByRoll(roll).GetName().c_str());
					}
					ImGui::TreePop();
				}
				if (ImGui::TreeNodeEx("Class 11", ImGuiTreeNodeFlags_Framed))
				{
					for (unsigned int roll : m_Registry->Class11.GetAddedList())
					{
						ImGui::Text(m_Registry->Class11.GetStudentByRoll(roll).GetName().c_str());
					}
					ImGui::TreePop();
				}
				if (ImGui::TreeNodeEx("Class 12", ImGuiTreeNodeFlags_Framed))
				{
					for (unsigned int roll : m_Registry->Class12.GetAddedList())
					{
						ImGui::Text(m_Registry->Class12.GetStudentByRoll(roll).GetName().c_str());
					}
					ImGui::TreePop();
				}
				if (ImGui::Button("Upload New Data to database"))
				{
					m_Registry->Class09.UploadAddedDataToDatabase();
					m_Registry->Class10.UploadAddedDataToDatabase();
					m_Registry->Class11.UploadAddedDataToDatabase();
					m_Registry->Class12.UploadAddedDataToDatabase();
				}
				ImGui::TreePop();
			}

			if (ImGui::TreeNodeEx("Deleted", ImGuiTreeNodeFlags_Framed))
			{
				for (unsigned int roll : m_Registry->Class09.GetDeletedList())
				{
					ImGui::Text("Roll : %d", roll);
				}
				ImGui::TreePop();
			}

			ImGui::TreePop();
		}

		ImGui::TreePop();
	}
	ImGui::End();
}

void cms::UI::SettingsPanel::SetRegistry(Data::StudentRegistry* Registry)
{
	m_Registry = Registry;
}