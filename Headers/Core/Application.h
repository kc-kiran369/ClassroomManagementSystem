#ifndef APP_H
#define APP_H

#include<iostream>
#include<memory>
#include"Window.h"
#include"UserInterface/GUI.h"
#include"Data/StudentRegistry.h"

namespace CW
{
	class Application : public Layer
	{
	private:
		Window* m_Window;
		GUI* m_UserInterface;
	public:
		Application(const char* ApplicationName, int width, int height);
		~Application();
		void Run();
		void Attach();
		void Detach();
		void OnUpdate();
		void OnUpdateComplete();
	};
}
#endif // !APP_H