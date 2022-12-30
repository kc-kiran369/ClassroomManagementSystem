#include "UserInterface/DashboardPanel.h"
#include <imgui/imgui_internal.h>

cms::UI::DashboardPanel::DashboardPanel(Data::StudentRegistry* registry)
{
	m_Registry = registry;
}

cms::UI::DashboardPanel::~DashboardPanel()
{

}

void cms::UI::DashboardPanel::SetRegistry(Data::StudentRegistry* Registry)
{
	m_Registry = Registry;
}

void cms::UI::DashboardPanel::Draw()
{
	ImGui::Begin("Dashboard", &m_PanelEnabled);

	float values[] = {
		m_Registry->Class09.GetTotalStudents(),
		m_Registry->Class10.GetTotalStudents(),
		m_Registry->Class11.GetTotalStudents(),
		m_Registry->Class12.GetTotalStudents()
	};

	ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2{ 0,0 });

	ImGui::BeginChildFrame(1, ImVec2{ ImGui::GetWindowWidth() / 2,250 }, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_MenuBar);

	if (m_Registry->GetTotalStudents() != 0)
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

	ImGui::Text("Total Students : %d", m_Registry->GetTotalStudents());
	ImGui::Text("Class 9 : %d", m_Registry->Class09.GetTotalStudents());
	ImGui::Text("Class 10 : %d", m_Registry->Class10.GetTotalStudents());
	ImGui::Text("Class 11 : %d", m_Registry->Class11.GetTotalStudents());
	ImGui::Text("Class 12 : %d", m_Registry->Class12.GetTotalStudents());
	ImGui::EndChildFrame();

	ImGui::PopStyleVar();
	ImGui::End();
}