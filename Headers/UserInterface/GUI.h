#ifndef GUI_LAYER_H
#define GUI_LAYER_H

#include<iostream>
#include<sstream>
#include"glfw/glfw3.h"

#include"imgui/imgui.h"
#include"ImGUI/imgui_impl_glfw.h"
#include"ImGUI/imgui_impl_opengl3.h"

#include"Core/Layer.h"
#include"Core/Window.h"
#include"Core/Serializer.h"
#include"Windows/MessageBox.h"
#include"Data/StudentRegistry.h"
#include "Database/SqlConnector.h"

#include"AdmissionPanel.h"
#include"DashboardPanel.h"
#include"StudentsPanel.h"
#include"NavigationPanel.h"
#include"AnnouncementPanel.h"
#include"SettingsPanel.h"

namespace cms::UI
{
	class GUI : public Core::Layer
	{
	private:
		//float m_UIScale = 1.0f;

		GLFWwindow* m_Window;

		ImGuiIO* io;
		ImGuiStyle* style;
		ImVec4* colors;

		Data::StudentRegistry* m_Registry;

		AdmissionPanel admissionPanel;
		DashboardPanel dashboardPanel;
		StudentsPanel studentsPanel;
		NavigationPanel navigationPanel;
		AnnouncementPanel announcementPanel;
		SettingsPanel settingsPanel;

		void MainMenuBar();
		void Style();
	public:
		GUI(GLFWwindow* window);
		~GUI();

		void Attach()override;
		void Attach(Data::StudentRegistry* registry);
		void Detach()override;
		void OnUpdate()override;
		void OnUpdateComplete()override;

		void RenderUIElements();

		void SetDarkTheme();
		void SetGreenTheme();
		void SetRedTheme();
	};
}

#endif