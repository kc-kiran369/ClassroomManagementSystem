#include"UserInterface/AnnouncementPanel.h"

void cms::UI::AnnouncementPanel::Draw()
{
	ImGui::Begin("Announcement", &m_PanelEnabled, ImGuiWindowFlags_MenuBar);

	if (ImGui::BeginMenuBar())
	{
		if (ImGui::BeginMenu("Options"))
		{
			if (ImGui::MenuItem("New Announcement"))
				IsModalEnabled = true;
			if (ImGui::MenuItem("Clear All Announcements"))
				m_Announcements.clear();
			ImGui::EndMenu();
		}
		ImGui::EndMenuBar();
	}
	if (IsModalEnabled)
		ImGui::OpenPopup("Add Announcement", ImGuiPopupFlags_AnyPopupLevel);

	if (ImGui::BeginPopupModal("Add Announcement"))
	{
		ImGui::InputText("Title", m_TmpAnnouncement.Title, 50, ImGuiInputTextFlags_NoHorizontalScroll);
		ImGui::InputTextMultiline("Description", m_TmpAnnouncement.Description, 255);
		if (ImGui::Button("Add", ImVec2(100, 40)))
		{
			if (m_TmpAnnouncement.Title[0] == '\0' || m_TmpAnnouncement.Description[0] == '\0')
			{
				cms::Windows::PromptBox::Open("Fill Title and Description to make an announcement!!", MB_OK | MB_ICONEXCLAMATION);
			}
			else
			{
				m_Announcements.push_back(m_TmpAnnouncement);
				std::fill(std::begin(m_TmpAnnouncement.Title), std::end(m_TmpAnnouncement.Title), '\0');
				std::fill(std::begin(m_TmpAnnouncement.Description), std::end(m_TmpAnnouncement.Description), '\0');
				IsModalEnabled = false;
				ImGui::CloseCurrentPopup();
			}
		}
		ImGui::SameLine();
		if (ImGui::Button("Close", ImVec2(100, 40)))
		{
			IsModalEnabled = false;
			ImGui::CloseCurrentPopup();
		}
		ImGui::EndPopup();
	}

	for (const auto& announcement : m_Announcements)
	{
		if (ImGui::TreeNodeEx(announcement.Title, ImGuiTreeNodeFlags_DefaultOpen | ImGuiTreeNodeFlags_Framed | ImGuiTreeNodeFlags_Bullet))
		{
			ImGui::TextWrapped(announcement.Description);
			ImGui::TreePop();
		}
		ImGui::Separator();
	}
	ImGui::End();
}

void cms::UI::AnnouncementPanel::SetRegistry(Data::StudentRegistry* Registry)
{
}