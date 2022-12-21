#include"Core/Window.h"

cms::Window::Window(const char* AppName, int width, int height)
{
	glfwInit();
	m_Window = glfwCreateWindow(width, height, AppName, nullptr, nullptr);
	m_Width = width;
	m_Height = height;
}

cms::Window::~Window()
{
}

void cms::Window::Attach()
{
	glfwMakeContextCurrent(m_Window);
	glfwSwapInterval(1);

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

}

void cms::Window::Detach()
{
	glfwTerminate();
}

void cms::Window::OnUpdate()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
}

void cms::Window::OnUpdateComplete()
{
	glfwPollEvents();
	glfwSwapBuffers(m_Window);
}

GLFWwindow* cms::Window::GetWindow()
{
	return m_Window;
}

void cms::Window::ToggleSystemConsole()
{
	ShowWindow(GetConsoleWindow(), (IsWindowVisible(GetConsoleWindow()) ? SW_HIDE : SW_SHOW));
}
