#ifndef WINDOW_CW_H
#define WINDOW_CW_H

#include<iostream>
#include<Windows.h>
#include"Layer.h"
#include<glfw/glfw3.h>

namespace cms::Core
{
	class Window : public cms::Core::Layer
	{
	private:
		GLFWwindow* m_Window;
		int m_Width, m_Height;
		std::string m_Name;
	public:
		Window(const char* AppName, int width, int height);
		~Window();
		void Attach();
		void Detach();
		void OnUpdate();
		void OnUpdateComplete();
		static void ToggleSystemConsole();
		static void SetSystemConsoleVisible(bool Visible);
		GLFWwindow* GetWindow();
	};
}

#endif