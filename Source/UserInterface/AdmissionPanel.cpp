#include "UserInterface/AdmissionPanel.h"

cms::UI::AdmissionPanel::AdmissionPanel(Data::StudentRegistry* registry)
{
	m_Registry = registry;
}

cms::UI::AdmissionPanel::~AdmissionPanel()
{

}

void cms::UI::AdmissionPanel::SetRegistry(Data::StudentRegistry* Registry)
{
	m_Registry = Registry;
}

void cms::UI::AdmissionPanel::ClearTempValues()
{
	std::fill(std::begin(m_TmpName), std::end(m_TmpName), '\0');
	std::fill(std::begin(m_TmpAddress), std::end(m_TmpAddress), '\0');
	m_TmpRoll = 1;
	m_TmpClass = 9;
	m_ClassIndex = 0;
}

void cms::UI::AdmissionPanel::Draw()
{
	ImGui::Begin("Admission", &m_PanelEnabled);

	ImGui::Text("Name : ");
	ImGui::InputText("Name", m_TmpName, 25);
	ImGui::Text("Address : ");
	ImGui::InputText("Address", m_TmpAddress, 25);
	ImGui::Text("Roll : ");
	ImGui::SliderInt("Roll", &m_TmpRoll, 1, Data::ClassRegistry::MaxStudents, "%d");
	ImGui::Text("Class : ");
	if (ImGui::Combo("Class", &m_ClassIndex, m_Classes, 4))
	{
		m_TmpClass = (m_ClassIndex + 9);
	}
	if (ImGui::Button("Submit"))
	{
		if (m_TmpName[0] == '\0')
		{
			cms::Windows::PromptBox::Open("You must enter valid name of the student", MB_OK | MB_ICONWARNING);
			return;
		}
		if (m_TmpAddress[0] == '\0')
		{
			cms::Windows::PromptBox::Open("You must enter valid address of the student", MB_OK | MB_ICONWARNING);
			return;
		}
		switch (m_TmpClass)
		{
		case 9:
			if (m_Registry->Class09.AddStudent(m_TmpName, m_TmpRoll, m_TmpAddress))
			{
				cms::Windows::PromptBox::Open("Student Admitted Successfully!!", MB_OKCANCEL | MB_ICONINFORMATION);
			}
			ClearTempValues();
			break;
		case 10:
			if (m_Registry->Class10.AddStudent(m_TmpName, m_TmpRoll, m_TmpAddress))
			{
				cms::Windows::PromptBox::Open("Student Admitted Successfully!!", MB_OKCANCEL | MB_ICONINFORMATION);
			}
			ClearTempValues();
			break;
		case 11:
			if (m_Registry->Class11.AddStudent(m_TmpName, m_TmpRoll, m_TmpAddress))
			{
				cms::Windows::PromptBox::Open("Student Admitted Successfully!!", MB_OKCANCEL | MB_ICONINFORMATION);
			}
			ClearTempValues();
			break;
		case 12:
			if (m_Registry->Class12.AddStudent(m_TmpName, m_TmpRoll, m_TmpAddress))
			{
				cms::Windows::PromptBox::Open("Student Admitted Successfully!!", MB_OKCANCEL | MB_ICONINFORMATION);
			}
			ClearTempValues();
			break;
		}
	}
	ImGui::End();
}