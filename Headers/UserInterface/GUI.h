#ifndef GUI_LAYER_H
#define GUI_LAYER_H

#include<iostream>
#include"glfw/glfw3.h"

#include"imgui/imgui.h"
#include"ImGUI/imgui_impl_glfw.h"
#include"ImGUI/imgui_impl_opengl3.h"

#include"Core/Layer.h"
#include"Data/StudentRegistry.h"
#include"AdmissionPanel.h"
#include"Windows/MessageBox.h"
#include"Core/Window.h"

namespace cms
{
	class GUI : public Layer
	{
	private:
		GLFWwindow* m_Window;

		ImGuiIO* io;
		ImGuiStyle* style;
		ImVec4* colors;

		StudentRegistry* m_Registry;
		AdmissionPanel admissionPanel;

		void MainMenuBar();
		void Inspector();
		void DashboardPanel();
		void AttPanel();
		void StudentsPanel();
		//void AdmissionPanel();
		void SettingsPanel();
		void Style();

		void DrawTable(int _class);
	public:
		GUI(GLFWwindow* window);
		~GUI();

		void Attach();
		void Attach(StudentRegistry* registry);
		void Detach();
		void OnUpdate();
		void OnUpdateComplete();

		void RenderUIElements();

		void SetDarkTheme();
		void SetGreenTheme();
		void SetRedTheme();
	};
}

#endif