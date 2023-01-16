#ifndef ASSIGNMENT_PANEL
#define ASSIGNMENT_PANEL

#include<string>
#include<vector>
#include<fstream>
#include<iostream>

#include<glfw/glfw3.h>
#include"imgui/imgui.h"

#include"Windows/FileDialog.h"

#include"Panel.h"
#include"Data/Image.h"

namespace cms::UI
{
	struct Assignment
	{
		char Title[25];
		std::vector<Data::Image> Images;

		Assignment(char* title)
		{
			memcpy_s(Title, 25, title, 25);
		}
	};

	class AssignmentPanel : public Panel
	{
	private:
		char m_Title[25];
		std::vector<std::string> m_Imagespath;

		std::vector<Assignment> m_Assignments;

		GLFWwindow* m_Window;

		bool IsPopupEnable = false;

		float m_ImageScale = 1.0f;
	public:
		void Draw() override;
		void SetRegistry(Data::StudentRegistry* Registry) override;
		void SetWindow(GLFWwindow* window);
	};
}

#endif