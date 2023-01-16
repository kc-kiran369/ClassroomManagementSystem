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
			Data::Student& student = registry.GetStudentAt(row);
			ImGui::TableNextRow();
			ImGui::TableNextColumn();
			ImGui::Text("%d", (row + 1));
			ImGui::TableNextColumn();
			ImGui::Text(student.GetName().c_str());
			ImGui::TableNextColumn();
			ImGui::Text("%d", registry.GetStudentAt(row).GetRoll());
			ImGui::TableNextColumn();
			ImGui::Text(student.GetAddress().c_str());
			ImGui::TableNextColumn();

			ImGui::PushID(row);
			if (ImGui::Button(":"))
			{
				ImGui::OpenPopup("ContextMenu");
			}
			if (ImGui::BeginPopupModal("ContextMenu", (bool*)0, ImGuiWindowFlags_AlwaysAutoResize))
			{
				if (ImGui::TreeNodeEx("Edit Details", ImGuiTreeNodeFlags_Framed))
				{
					ImGui::Text("New Name");
					ImGui::InputText("##NewName", m_TmpName, 25);
					ImGui::Text("New Address");
					ImGui::InputText("##NewAddress", m_TmpAddress, 25);
					if (ImGui::Button("Get Original Data"))
					{
						std::string& name = student.GetName();
						std::string& address = student.GetAddress();
						memcpy_s(m_TmpName, 25, name.c_str(), name.length());
						memcpy_s(m_TmpAddress, 25, address.c_str(), address.length());
					}
					ImGui::SameLine();
					if (ImGui::Button("Apply Edits"))
					{
						if (m_TmpName[0] == '\0' || m_TmpAddress[0] == '\0')
							cms::Windows::PromptBox::Open("Enter Valid Details!!", MB_OK | MB_ICONEXCLAMATION);
						else
						{
							registry.EditStudentByRoll(m_TmpName, m_TmpAddress, registry.GetStudentAt(row).GetRoll());
							cms::Windows::PromptBox::Open("Details Has Been Modified!!", MB_OK | MB_ICONINFORMATION);
							ImGui::CloseCurrentPopup();
						}
					}
					if (ImGui::IsKeyPressed(ImGuiKey_Escape, false))
					{
						ImGui::CloseCurrentPopup();
					}
					ImGui::TreePop();
				}
				ImGui::Separator();
				if (ImGui::TreeNodeEx("Remove Student", ImGuiTreeNodeFlags_Framed))
				{
					ImGui::Text("The Following Student Will Be Removed");
					ImGui::Text(registry.GetStudentAt(row).GetName().c_str());
					ImGui::Text("Roll No : %d", registry.GetStudentAt(row).GetRoll());
					ImGui::Text(registry.GetStudentAt(row).GetAddress().c_str());
					if (ImGui::Button("Delete"))
					{
						registry.RemoveStudent(row);
						cms::Windows::PromptBox::Open("Record cleared successfully!!", MB_OK | MB_ICONINFORMATION);
						ImGui::CloseCurrentPopup();
					}
					ImGui::TreePop();
				}
				ImGui::Separator();
				if (ImGui::IsKeyPressed(ImGuiKey_Escape, false))
				{
					ImGui::CloseCurrentPopup();
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
	ImGui::Begin("Students", (bool*)0);

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