#include"Core/Application.h"

using namespace cms;

cms::Application::Application(const char* ApplicationName, int width, int height)
{
	m_Window = new Window(ApplicationName, width, height);
	m_UserInterface = new GUI(m_Window->GetWindow());
	std::cout << "Application Init : \n";
	std::cout << "\tApp_Name : " << ApplicationName << "\n";
	std::cout << "\tApp_Window_Width : " << width << "\n";
	std::cout << "\tApp_Window_Height : " << height << "\n";
}

cms::Application::~Application()
{
	delete m_Window;
	delete m_UserInterface;
	std::cout << "Application Out Of Scope\n";
}

void cms::Application::Run()
{
	m_Window->Attach();
	std::unique_ptr<StudentRegistry> registry = std::make_unique<StudentRegistry>();
	m_UserInterface->Attach(registry.get());

	while (!glfwWindowShouldClose(m_Window->GetWindow()))
	{
		m_Window->OnUpdate();
		m_UserInterface->OnUpdate();

		m_UserInterface->OnUpdateComplete();
		m_Window->OnUpdateComplete();
	}
	m_UserInterface->Detach();
	m_Window->Detach();
}

void cms::Application::Attach() {}

void cms::Application::Detach() {}

void cms::Application::OnUpdate() {}

void cms::Application::OnUpdateComplete() {}