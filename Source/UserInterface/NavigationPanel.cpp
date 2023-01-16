#include"UserInterface/NavigationPanel.h"

void cms::UI::NavigationPanel::Draw()
{
	if (ImGui::Begin("Inspector", (bool*)0))
	{
		if (ImGui::Button("Dashboard", ImVec2{ ImGui::GetColumnWidth(),40.0f }))
		{
			ImGui::SetWindowFocus("Dashboard");
		}
		if (ImGui::Button("Students", ImVec2{ ImGui::GetColumnWidth(),40.0f }))
		{
			ImGui::SetWindowFocus("Students");
		}
		if (ImGui::Button("Admission", ImVec2{ ImGui::GetColumnWidth(),40.0f }))
		{
			ImGui::SetWindowFocus("Admission");
		}
		if (ImGui::Button("Announcement", ImVec2{ ImGui::GetColumnWidth(),40.0f }))
		{
			ImGui::SetWindowFocus("Announcement");
		}
		if (ImGui::Button("Settings", ImVec2{ ImGui::GetColumnWidth(),40.0f }))
		{
			ImGui::SetWindowFocus("Settings");
		}
		ImGui::End();
	}
}

void cms::UI::NavigationPanel::SetRegistry(Data::StudentRegistry* Registry)
{

}