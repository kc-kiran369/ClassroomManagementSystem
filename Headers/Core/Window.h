#include<iostream>
#include"Layer.h"
#include<glfw/glfw3.h>

namespace CW
{
	class Window : public Layer
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
		GLFWwindow* GetWindow();
	};
}
