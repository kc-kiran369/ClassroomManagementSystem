#include "UserInterface/StudentsPanel.h"

void cms::UI::StudentsPanel::DrawTable(int _class)
{
	cms::Data::ClassRegistry& registry = (_class == 9 ? m_Registry->Class09 : (_class == 10 ? m_Registry->Class10 : (_class == 11 ? m_Registry->Class11 : m_Registry->Class12)));
	
	if (ImGui::BeginTable("Class", 5))
	{
		ImGui::TableNextRow();
		ImGui::TableNextColumn();
		ImGui::TableHeader("SN");
		ImGui::TableNextColumn();
		ImGui::TableHeader("Name");
		ImGui::TableNextColumn();
		ImGui::TableHeader("Roll");
		ImGui::TableNextColumn();
		ImGui::TableHeader("Address");

		for (int row = 0; row < registry.GetTotalStudents(); row++)
		{
			ImGui::TableNextRow();
			ImGui::TableNextColumn();
			ImGui::Text("%d", (row + 1));
			ImGui::TableNextColumn();
			ImGui::Text("%s", registry.GetStudentAt(row).GetName());
			ImGui::TableNextColumn();
			ImGui::Text("%d", registry.GetStudentAt(row).GetRoll());
			ImGui::TableNextColumn();
			ImGui::Text("%s", registry.GetStudentAt(row).GetAddress());
			ImGui::TableNextColumn();

			ImGui::PushID(row);
			if (ImGui::Button(":"))
			{
				ImGui::OpenPopup("ContextMenu");
			}
			if (ImGui::BeginPopupModal("ContextMenu", (bool*)0, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_AlwaysAutoResize))
			{
				if (ImGui::TreeNodeEx("Edit Details"))
				{

					ImGui::TreePop();
				}
				ImGui::Separator();
				if (ImGui::TreeNodeEx("Remove Student"))
				{
					ImGui::Text("The Following Student Will Be Removed");
					ImGui::Text("Name : %s", registry.GetStudentAt(row).GetName());
					ImGui::Text("Roll No : %d", registry.GetStudentAt(row).GetRoll());
					ImGui::Text("Address : %s", registry.GetStudentAt(row).GetAddress());
					if (ImGui::Button("Delete"))
					{
						registry.RemoveStudent(row);
						cms::Windows::MessageBox::Open("Record cleared successfully!!", "Classroom Management", MB_OK | MB_ICONINFORMATION);
						ImGui::CloseCurrentPopup();
					}
					ImGui::TreePop();
				}
				ImGui::EndPopup();
			}
			ImGui::PopID();
		}
		ImGui::EndTable();
	}
}

cms::UI::StudentsPanel::StudentsPanel(cms::Data::StudentRegistry* registry)
{
	m_Registry = registry;
}

cms::UI::StudentsPanel::~StudentsPanel()
{
}

void cms::UI::StudentsPanel::SetRegistry(cms::Data::StudentRegistry* Registry)
{
	m_Registry = Registry;
}

void cms::UI::StudentsPanel::Draw()
{
	ImGui::Begin("Students", &m_PanelEnabled);

	if (ImGui::BeginTabBar("Tab", ImGuiTabBarFlags_None))
	{
		if (ImGui::BeginTabItem("Class 9"))
		{
			DrawTable(9);
			ImGui::EndTabItem();
		}
		if (ImGui::BeginTabItem("Class 10"))
		{
			DrawTable(10);
			ImGui::EndTabItem();
		}
		if (ImGui::BeginTabItem("Class 11"))
		{
			DrawTable(11);
			ImGui::EndTabItem();
		}
		if (ImGui::BeginTabItem("Class 12"))
		{
			DrawTable(12);
			ImGui::EndTabItem();
		}
		ImGui::EndTabBar();
	}
	ImGui::End();
}