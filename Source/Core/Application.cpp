#include"Core/Application.h"

cms::Core::Application::Application(const char* ApplicationName, int width, int height)
{
	m_Window = new Window(ApplicationName, width, height);
	m_UserInterface = new UI::GUI(m_Window->GetWindow());
}

cms::Core::Application::~Application()
{
	delete m_Window;
	delete m_UserInterface;
}

void cms::Core::Application::Run()
{
	m_Window->Attach();
	std::unique_ptr<Data::StudentRegistry> registry = std::make_unique<Data::StudentRegistry>();
	m_UserInterface->Attach(registry.get());

	cms::Database::SqlConnector::GetInstance().Connect();

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