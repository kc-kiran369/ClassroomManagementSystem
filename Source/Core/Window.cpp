#include"Core/Window.h"

cms::Core::Window::Window(const char* AppName, int width, int height)
{
	glfwInit();
	m_Window = glfwCreateWindow(width, height, AppName, nullptr, nullptr);
	m_Width = width;
	m_Height = height;
}

cms::Core::Window::~Window()
{

}

void cms::Core::Window::Attach()
{
	glfwMakeContextCurrent(m_Window);
	glfwSwapInterval(1);

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	SetSystemConsoleVisible(false);
}

void cms::Core::Window::Detach()
{
	glfwTerminate();
}

void cms::Core::Window::OnUpdate()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
}

void cms::Core::Window::OnUpdateComplete()
{
	glfwPollEvents();
	glfwSwapBuffers(m_Window);
}

GLFWwindow* cms::Core::Window::GetWindow()
{
	return m_Window;
}

void cms::Core::Window::ToggleSystemConsole()
{
	ShowWindow(GetConsoleWindow(), (IsWindowVisible(GetConsoleWindow()) ? SW_HIDE : SW_SHOW));
}

void cms::Core::Window::SetSystemConsoleVisible(bool Visible)
{
	if (Visible)
		ShowWindow(GetConsoleWindow(), SW_HIDE);
	else
		ShowWindow(GetConsoleWindow(), SW_HIDE);
}
