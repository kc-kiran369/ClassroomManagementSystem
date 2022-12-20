#include"UserInterface/GUI.h"

CW::GUI::GUI(GLFWwindow* window)
	:m_Window(window)
{

}

CW::GUI::~GUI()
{
}

void CW::GUI::Attach()
{
}

void CW::GUI::Attach(StudentRegistry* registry)
{
	m_Registry = registry;
	ImGui::CreateContext();
	ImGui_ImplGlfw_InitForOpenGL(m_Window, true);
	ImGui_ImplOpenGL3_Init("#version 330");

	io = &ImGui::GetIO();
	style = &ImGui::GetStyle();
	colors = style->Colors;

	SetDarkThemeColors();

	io->ConfigFlags |= ImGuiConfigFlags_DockingEnable;
	io->IniFilename = "config.ini";
}

void CW::GUI::Detach()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}

void CW::GUI::OnUpdate()
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();

	ImGui::DockSpaceOverViewport();

	RenderUIElements();
}

void CW::GUI::OnUpdateComplete()
{
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void CW::GUI::RenderUIElements()
{
	MainMenuBar();
	Inspector();
	DashboardPanel();
	AttPanel();
	StudentsPanel();
	//AdmissionPanel();
	admissionPanel.Draw(m_Registry);
	SettingsPanel();
}

void CW::GUI::SetDarkThemeColors()
{
	colors[ImGuiCol_Text] = ImVec4(1.000f, 1.000f, 1.000f, 1.000f);
	colors[ImGuiCol_TextDisabled] = ImVec4(0.500f, 0.500f, 0.500f, 1.000f);
	colors[ImGuiCol_WindowBg] = ImVec4(0.180f, 0.180f, 0.180f, 1.000f);
	colors[ImGuiCol_ChildBg] = ImVec4(0.280f, 0.280f, 0.280f, 0.000f);
	colors[ImGuiCol_PopupBg] = ImVec4(0.313f, 0.313f, 0.313f, 1.000f);
	colors[ImGuiCol_Border] = ImVec4(0.266f, 0.266f, 0.266f, 1.000f);
	colors[ImGuiCol_BorderShadow] = ImVec4(0.000f, 0.000f, 0.000f, 0.000f);
	colors[ImGuiCol_FrameBg] = ImVec4(0.160f, 0.160f, 0.160f, 1.000f);
	colors[ImGuiCol_FrameBgHovered] = ImVec4(0.200f, 0.200f, 0.200f, 1.000f);
	colors[ImGuiCol_FrameBgActive] = ImVec4(0.280f, 0.280f, 0.280f, 1.000f);
	colors[ImGuiCol_TitleBg] = ImVec4(0.148f, 0.148f, 0.148f, 1.000f);
	colors[ImGuiCol_TitleBgActive] = ImVec4(0.148f, 0.148f, 0.148f, 1.000f);
	colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.148f, 0.148f, 0.148f, 1.000f);
	colors[ImGuiCol_MenuBarBg] = ImVec4(0.195f, 0.195f, 0.195f, 1.000f);
	colors[ImGuiCol_ScrollbarBg] = ImVec4(0.160f, 0.160f, 0.160f, 1.000f);
	colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.277f, 0.277f, 0.277f, 1.000f);
	colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.300f, 0.300f, 0.300f, 1.000f);
	colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(1.000f, 0.391f, 0.000f, 1.000f);
	colors[ImGuiCol_CheckMark] = ImVec4(1.000f, 1.000f, 1.000f, 1.000f);
	colors[ImGuiCol_SliderGrab] = ImVec4(0.391f, 0.391f, 0.391f, 1.000f);
	colors[ImGuiCol_SliderGrabActive] = ImVec4(1.000f, 0.391f, 0.000f, 1.000f);
	colors[ImGuiCol_Button] = ImVec4(1.000f, 1.000f, 1.000f, 0.000f);
	colors[ImGuiCol_ButtonHovered] = ImVec4(1.000f, 1.000f, 1.000f, 0.156f);
	colors[ImGuiCol_ButtonActive] = ImVec4(1.000f, 1.000f, 1.000f, 0.391f);
	colors[ImGuiCol_Header] = ImVec4(0.313f, 0.313f, 0.313f, 1.000f);
	colors[ImGuiCol_HeaderHovered] = ImVec4(0.469f, 0.469f, 0.469f, 1.000f);
	colors[ImGuiCol_HeaderActive] = ImVec4(0.469f, 0.469f, 0.469f, 1.000f);
	colors[ImGuiCol_Separator] = colors[ImGuiCol_Border];
	colors[ImGuiCol_SeparatorHovered] = ImVec4(0.391f, 0.391f, 0.391f, 1.000f);
	colors[ImGuiCol_SeparatorActive] = ImVec4(1.000f, 0.391f, 0.000f, 1.000f);
	colors[ImGuiCol_ResizeGrip] = ImVec4(1.000f, 1.000f, 1.000f, 0.250f);
	colors[ImGuiCol_ResizeGripHovered] = ImVec4(1.000f, 1.000f, 1.000f, 0.670f);
	colors[ImGuiCol_ResizeGripActive] = ImVec4(1.000f, 0.391f, 0.000f, 1.000f);
	colors[ImGuiCol_Tab] = ImVec4(0.098f, 0.098f, 0.098f, 1.000f);
	colors[ImGuiCol_TabHovered] = ImVec4(0.352f, 0.352f, 0.352f, 1.000f);
	colors[ImGuiCol_TabActive] = ImVec4(0.195f, 0.195f, 0.195f, 1.000f);
	colors[ImGuiCol_TabUnfocused] = ImVec4(0.098f, 0.098f, 0.098f, 1.000f);
	colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.195f, 0.195f, 0.195f, 1.000f);
	colors[ImGuiCol_DockingPreview] = ImVec4(1.000f, 0.391f, 0.000f, 0.781f);
	colors[ImGuiCol_DockingEmptyBg] = ImVec4(0.180f, 0.180f, 0.180f, 1.000f);
	colors[ImGuiCol_PlotLines] = ImVec4(0.469f, 0.469f, 0.469f, 1.000f);
	colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.000f, 0.391f, 0.000f, 1.000f);
	colors[ImGuiCol_PlotHistogram] = ImVec4(0.586f, 0.586f, 0.586f, 1.000f);
	colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.000f, 0.391f, 0.000f, 1.000f);
	colors[ImGuiCol_TextSelectedBg] = ImVec4(1.000f, 1.000f, 1.000f, 0.156f);
	colors[ImGuiCol_DragDropTarget] = ImVec4(1.000f, 0.391f, 0.000f, 1.000f);
	colors[ImGuiCol_NavHighlight] = ImVec4(1.000f, 0.391f, 0.000f, 1.000f);
	colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.000f, 0.391f, 0.000f, 1.000f);
	colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.000f, 0.000f, 0.000f, 0.586f);
	colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.000f, 0.000f, 0.000f, 0.586f);

	style->ChildRounding = 4.0f;
	style->FrameBorderSize = 1.0f;
	style->FrameRounding = 2.0f;
	style->GrabMinSize = 7.0f;
	style->PopupRounding = 2.0f;
	style->ScrollbarRounding = 12.0f;
	style->ScrollbarSize = 13.0f;
	style->TabBorderSize = 1.0f;
	style->TabRounding = 0.0f;
	style->WindowRounding = 0.0f;
	style->WindowMenuButtonPosition = ImGuiDir_None;
}

void CW::GUI::MainMenuBar()
{
	if (ImGui::BeginMainMenuBar())
	{
		if (ImGui::BeginMenu("File"))
		{
			if (ImGui::MenuItem("Exit"))
			{
				if (CW::MessageBox::Open("Any unsaved progress will be lost!!", "Do you want to exit", MB_OKCANCEL | MB_ICONQUESTION) == 1)
				{
					glfwSetWindowShouldClose(m_Window, 1);
				}
			}
			ImGui::EndMenu();
		}
		if (ImGui::BeginMenu("Theme"))
		{
			if (ImGui::MenuItem("Light"))
			{
				ImGui::StyleColorsLight();
			}
			if (ImGui::MenuItem("Dark 1"))
			{
				ImGui::StyleColorsDark();
			}
			if (ImGui::MenuItem("Dark 2"))
			{
				SetDarkThemeColors();
			}
			if (ImGui::MenuItem("Classic"))
			{
				ImGui::StyleColorsClassic();
			}
			
			ImGui::EndMenu();
		}
		if (ImGui::BeginMenu("View"))
		{

		}
		if (ImGui::BeginMenu("Tools"))
		{
			if (ImGui::MenuItem("Fill Random Data"))
			{
				m_Registry->Class09.FillWithRandomStudents();
				m_Registry->Class10.FillWithRandomStudents();
				m_Registry->Class11.FillWithRandomStudents();
				m_Registry->Class12.FillWithRandomStudents();
			}
			ImGui::EndMenu();
		}
		ImGui::EndMainMenuBar();
	}
}

void CW::GUI::Inspector()
{
	if (ImGui::Begin("Inspector"))
	{
		if (ImGui::Button("Dashboard", ImVec2{ ImGui::GetColumnWidth(),40.0f }))
		{
		}
		if (ImGui::Button("Attendance", ImVec2{ ImGui::GetColumnWidth(),40.0f })) {}
		if (ImGui::Button("Students", ImVec2{ ImGui::GetColumnWidth(),40.0f })) {}
		if (ImGui::Button("Admission", ImVec2{ ImGui::GetColumnWidth(),40.0f })) {}
		if (ImGui::Button("Settings", ImVec2{ ImGui::GetColumnWidth(),40.0f })) {}
		ImGui::End();
	}
}

void CW::GUI::DashboardPanel()
{
	if (ImGui::Begin("Dashboard"))
	{
		float values[] = {
			m_Registry->Class09.GetTotalStudents(),
			m_Registry->Class10.GetTotalStudents(),
			m_Registry->Class11.GetTotalStudents(),
			m_Registry->Class12.GetTotalStudents()
		};
		ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2{ 0,0 });
		if (ImGui::BeginChildFrame(1, ImVec2{ ImGui::GetWindowWidth() / 2,250 }, ImGuiWindowFlags_NoScrollbar))
		{
			ImGui::PlotHistogram("Stds", values, 4, 0, "Total Students", 0, 50.0f, ImVec2{ ImGui::GetWindowWidth(),ImGui::GetWindowHeight() }, 4);
			ImGui::EndChildFrame();
		}
		ImGui::SameLine();
		if (ImGui::BeginChildFrame(3, ImVec2{ 300,250 }, ImGuiWindowFlags_NoScrollbar))
		{
			ImGui::Text("Total Students : %d", m_Registry->GetTotalStudents());
			ImGui::Text("Class 9 : %d", m_Registry->Class09.GetTotalStudents());
			ImGui::Text("Class 10 : %d", m_Registry->Class10.GetTotalStudents());
			ImGui::Text("Class 11 : %d", m_Registry->Class11.GetTotalStudents());
			ImGui::Text("Class 12 : %d", m_Registry->Class12.GetTotalStudents());
			ImGui::EndChildFrame();
		}
		ImGui::PopStyleVar();
		ImGui::End();
	}
}

void CW::GUI::AttPanel()
{
	if (ImGui::Begin("Attendance"))
	{

		ImGui::End();
	}
}

void CW::GUI::StudentsPanel()
{
	if (ImGui::Begin("Students"))
	{
		if (ImGui::BeginTabBar("Tab", ImGuiTabBarFlags_None))
		{
			if (ImGui::BeginTabItem("Class 9"))
			{
				DrawTable(9);
				ImGui::EndTabItem();
			}
			if (ImGui::BeginTabItem("Class 10"))
			{
				DrawTable(10);
				ImGui::EndTabItem();
			}
			if (ImGui::BeginTabItem("Class 11"))
			{
				DrawTable(11);
				ImGui::EndTabItem();
			}
			if (ImGui::BeginTabItem("Class 12"))
			{
				DrawTable(12);
				ImGui::EndTabItem();
			}
			ImGui::EndTabBar();
		}
		ImGui::End();
	}
}

void CW::GUI::SettingsPanel()
{
	if (ImGui::Begin("Settings"))
	{

		ImGui::End();
	}
}

void CW::GUI::DrawTable(int _class)
{
	if (ImGui::BeginTable("Class", 4))
	{
		ImGui::TableNextRow();
		ImGui::TableNextColumn();
		ImGui::Text("SN");
		ImGui::TableNextColumn();
		ImGui::Text("Name");
		ImGui::TableNextColumn();
		ImGui::Text("Roll");
		ImGui::TableNextColumn();
		ImGui::Text("Address");
		switch (_class)
		{
		case 9:
			for (int row = 0; row < m_Registry->Class09.GetTotalStudents(); row++)
			{
				ImGui::TableNextRow();
				ImGui::TableNextColumn();
				ImGui::Text("%d", (row + 1));
				ImGui::TableNextColumn();
				ImGui::Text("%s", m_Registry->Class09.GetStudentAt(row).GetName());
				ImGui::TableNextColumn();
				ImGui::Text("%d", m_Registry->Class09.GetStudentAt(row).GetRoll());
				ImGui::TableNextColumn();
				ImGui::Text("%s", m_Registry->Class09.GetStudentAt(row).GetAddress());
			}
			ImGui::EndTable();
			break;

		case 10:
			for (int row = 0; row < m_Registry->Class10.GetTotalStudents(); row++)
			{
				ImGui::TableNextRow();
				ImGui::TableNextColumn();
				ImGui::Text("%d", (row + 1));
				ImGui::TableNextColumn();
				ImGui::Text("%s", m_Registry->Class10.GetStudentAt(row).GetName());
				ImGui::TableNextColumn();
				ImGui::Text("%d", m_Registry->Class10.GetStudentAt(row).GetRoll());
				ImGui::TableNextColumn();
				ImGui::Text("%s", m_Registry->Class10.GetStudentAt(row).GetAddress());
			}
			ImGui::EndTable();
			break;

		case 11:
			for (int row = 0; row < m_Registry->Class11.GetTotalStudents(); row++)
			{
				ImGui::TableNextRow();
				ImGui::TableNextColumn();
				ImGui::Text("%d", (row + 1));
				ImGui::TableNextColumn();
				ImGui::Text("%s", m_Registry->Class11.GetStudentAt(row).GetName());
				ImGui::TableNextColumn();
				ImGui::Text("%d", m_Registry->Class11.GetStudentAt(row).GetRoll());
				ImGui::TableNextColumn();
				ImGui::Text("%s", m_Registry->Class11.GetStudentAt(row).GetAddress());
			}
			ImGui::EndTable();
			break;

		case 12:
			for (int row = 0; row < m_Registry->Class12.GetTotalStudents(); row++)
			{
				ImGui::TableNextRow();
				ImGui::TableNextColumn();
				ImGui::Text("%d", (row + 1));
				ImGui::TableNextColumn();
				ImGui::Text("%s", m_Registry->Class12.GetStudentAt(row).GetName());
				ImGui::TableNextColumn();
				ImGui::Text("%d", m_Registry->Class12.GetStudentAt(row).GetRoll());
				ImGui::TableNextColumn();
				ImGui::Text("%s", m_Registry->Class12.GetStudentAt(row).GetAddress());
			}
			ImGui::EndTable();
			break;
		}
	}
	if (ImGui::Button("Upload To Cloud"))
	{
		CW::MessageBox::Open("All the data will be uploaded to local database.", "Do you want to upload to database ?", MB_YESNO);
	}
}
