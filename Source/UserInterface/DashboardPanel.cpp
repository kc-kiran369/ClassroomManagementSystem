#include "UserInterface/DashboardPanel.h"
#include <imgui/imgui_internal.h>

namespace cms
{
	void DashboardPanel::Draw(StudentRegistry* registry)
	{
		ImGui::Begin("Dashboard", &m_PanelEnabled);

		float values[] = {
			registry->Class09.GetTotalStudents(),
			registry->Class10.GetTotalStudents(),
			registry->Class11.GetTotalStudents(),
			registry->Class12.GetTotalStudents()
		};

		ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2{ 0,0 });

		ImGui::BeginChildFrame(1, ImVec2{ ImGui::GetWindowWidth() / 2,250 }, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_MenuBar);

		if (registry->GetTotalStudents() != 0)
		{
			if (ImGui::BeginMenuBar())
			{
				if (ImGui::BeginMenu("View"))
				{
					if (ImGui::MenuItem("Bar Graph"))
					{
						m_HistogramView = true;
					}
					if (ImGui::MenuItem("Lines"))
					{
						m_HistogramView = false;
					}
					ImGui::EndMenu();
				}
				ImGui::EndMenuBar();
			}
		}

		if (m_HistogramView)
			ImGui::PlotHistogram("Stds", values, 4, 0, (const char*)(0), 0, 50.0f, ImVec2{ ImGui::GetWindowWidth(),ImGui::GetWindowHeight() }, 4);
		else
			ImGui::PlotLines("Stds", values, 4, 0, (const char*)0, 0, 50.0f, ImVec2{ ImGui::GetWindowWidth(),ImGui::GetWindowHeight() }, 4);
		ImGui::EndChildFrame();

		ImGui::PopStyleVar();
		ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2{ 10,10 });
		ImGui::SameLine();

		ImGui::BeginChildFrame(3, ImVec2{ 300,250 }, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_AlwaysUseWindowPadding);

		ImGui::Text("Total Students : %d", registry->GetTotalStudents());
		ImGui::Text("Class 9 : %d", registry->Class09.GetTotalStudents());
		ImGui::Text("Class 10 : %d", registry->Class10.GetTotalStudents());
		ImGui::Text("Class 11 : %d", registry->Class11.GetTotalStudents());
		ImGui::Text("Class 12 : %d", registry->Class12.GetTotalStudents());
		ImGui::EndChildFrame();

		ImGui::PopStyleVar();
		ImGui::End();
	}
}