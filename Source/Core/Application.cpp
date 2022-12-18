#include"Core/Application.h"

CW::Application::Application(const char* ApplicationName, int width, int height)
{
	m_Window = new Window("Classroom Management (64-bit, windows)", width, height);
	m_UserInterface = new GUI(m_Window->GetWindow());
}

CW::Application::~Application()
{
	delete m_Window;
	delete m_UserInterface;
}

void CW::Application::Run()
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

void CW::Application::Attach()
{

}

void CW::Application::Detach()
{
}

void CW::Application::OnUpdate()
{

}

void CW::Application::OnUpdateComplete()
{

}
