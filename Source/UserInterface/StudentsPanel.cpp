#include"UserInterface/StudentsPanel.h"

void StudentsPanel::DrawTable()
{

}

void StudentsPanel::Render(StudentRegistry* registry)
{
	if (ImGui::Begin("Students"))
	{
		if (ImGui::BeginTabBar("Tab", ImGuiTabBarFlags_None))
		{
			if (ImGui::BeginTabItem("Class 9"))
			{
				if (ImGui::BeginTable("Table", 4))
				{
					ImGui::TableNextRow();
					ImGui::TableNextColumn();
					ImGui::Text("SN");
					ImGui::TableNextColumn();
					ImGui::Text("Name");
					ImGui::TableNextColumn();
					ImGui::Text("Roll");
					ImGui::TableNextColumn();
					ImGui::Text("Address");
					for (int row = 0; row < registry->Class12.GetTotalStudents(); row++)
					{
						ImGui::TableNextRow();
						ImGui::TableNextColumn();
						ImGui::Text("%d", (row + 1));
						ImGui::TableNextColumn();
						ImGui::Text("%s", registry->Class12.GetStudentAt(row).GetName());
						ImGui::TableNextColumn();
						ImGui::Text("%d", registry->Class12.GetStudentAt(row).GetRoll());
						ImGui::TableNextColumn();
						ImGui::Text("%s", registry->Class12.GetStudentAt(row).GetAddress());
					}
					ImGui::EndTable();
				}
				ImGui::EndTabItem();
			}
			if (ImGui::BeginTabItem("Class 10"))
			{
				ImGui::EndTabItem();
			}
			if (ImGui::BeginTabItem("Class 11"))
			{
				ImGui::EndTabItem();
			}
			if (ImGui::BeginTabItem("Class 12"))
			{
				ImGui::EndTabItem();
			}
			ImGui::EndTabBar();
		}
		ImGui::End();
	}
}
