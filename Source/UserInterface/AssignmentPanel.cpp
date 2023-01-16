#include"UserInterface/AssignmentPanel.h"

void cms::UI::AssignmentPanel::Draw()
{
	ImGui::Begin("Assignment", (bool*)0, ImGuiWindowFlags_MenuBar);

	if (ImGui::BeginMenuBar())
	{
		if (ImGui::MenuItem("Add Assignment"))
		{
			IsPopupEnable = true;
		}
		ImGui::EndMenuBar();
	}
	if (IsPopupEnable)
		ImGui::OpenPopup("Addmenu");
	if (ImGui::BeginPopupModal("Addmenu"))
	{
		ImGui::Text("Title : ");
		ImGui::InputText("##Title", m_Title, 25);
		for (std::string& path : m_Imagespath)
			ImGui::Text(path.c_str());
		if (ImGui::Button("Attach a Photo"))
		{
			std::string path = FileDialog::OpenFile(".png;.jpg", m_Window);
			if (path.size() != 0)
				m_Imagespath.push_back(path);
		}
		ImGui::SameLine();
		if (ImGui::Button("Publish"))
		{
			if (m_Title[0] == '\0')
			{
				cms::Windows::PromptBox::Open("Title cannot be empty", MB_OK | MB_ICONEXCLAMATION);
			}
			else
			{
				Assignment& ass = m_Assignments.emplace_back(m_Title);
				for (std::string& path : m_Imagespath)
					ass.Images.emplace_back(path.c_str());
				m_Imagespath.clear();
				IsPopupEnable = false;
				ImGui::CloseCurrentPopup();
			}
		}
		if (ImGui::IsKeyPressed(ImGuiKey_Escape, false))
		{
			IsPopupEnable = false;
			ImGui::CloseCurrentPopup();
		}
		ImGui::EndPopup();
	}

	for (Assignment& assignment : m_Assignments)
	{
		if (ImGui::TreeNodeEx(assignment.Title, ImGuiTreeNodeFlags_Framed))
		{
			for (Data::Image& image : assignment.Images)
			{
				ImGui::Image((void*)image.GetID(), ImVec2{
					(float)image.GetWidth() * m_ImageScale,
					(float)image.GetHeight() * m_ImageScale });
			}
			ImGui::SliderFloat("##ImageScale", &m_ImageScale, 0.2f, 1.0f, "##scale", ImGuiSliderFlags_NoRoundToFormat);
			ImGui::Separator();
			ImGui::TreePop();
		}
	}

	ImGui::End();
}

void cms::UI::AssignmentPanel::SetRegistry(Data::StudentRegistry* Registry) { m_Registry = Registry; }

void cms::UI::AssignmentPanel::SetWindow(GLFWwindow* window)
{
	m_Window = window;
}
