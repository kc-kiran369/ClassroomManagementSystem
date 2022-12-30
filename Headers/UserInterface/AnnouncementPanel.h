#ifndef PANEL_ANNOUNCEMENT_H
#define PANEL_ANNOUNCEMENT_H

#include<iostream>
#include<imgui/imgui.h>

#include"Panel.h"
#include"Windows/MessageBox.h"

namespace cms::UI
{
	struct Announcement
	{
	public:
		char Title[50];
		char Description[255];
	};

	class AnnouncementPanel : public Panel
	{
	private:
		std::vector<Announcement> m_Announcements;
		Announcement m_TmpAnnouncement;
		bool IsModalEnabled = false;
	public:
		void Draw() override;
		void SetRegistry(Data::StudentRegistry* Registry) override;
	};
}

#endif