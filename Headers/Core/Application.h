#ifndef APP_H
#define APP_H

#include<iostream>
#include<memory>
#include"Window.h"
#include"UserInterface/GUI.h"
#include"Data/StudentRegistry.h"

namespace cms::Core
{
	class Application
	{
	private:
		Window* m_Window;
		UI::GUI* m_UserInterface;
	public:
		Application();
		~Application();
		void Run();
	};
}

#endif