#ifndef WINDOW_CW_H
#define WINDOW_CW_H

#include<iostream>
#include<Windows.h>
#include"Layer.h"
#include<glfw/glfw3.h>

namespace cms
{
	class Window : public cms::Layer
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
		GLFWwindow* GetWindow();
	};
}

#endif