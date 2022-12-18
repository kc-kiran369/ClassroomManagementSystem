#include"UserInterface/AdmissionPanel.h"

void AdmissionPanel::ClearTempValues()
{
	std::fill(std::begin(m_TmpName), std::end(m_TmpName), '\0');
	std::fill(std::begin(m_TmpAddress), std::end(m_TmpAddress), '\0');
	m_TmpRoll = 0;
	m_TmpClass = 9;
}

AdmissionPanel::AdmissionPanel()
{

}

AdmissionPanel::~AdmissionPanel()
{

}

void AdmissionPanel::Draw(StudentRegistry* registry)
{
	ImGui::Begin("Admission");
	ImGui::Text("Name : ");
	ImGui::InputText("Name", m_TmpName, 25);
	ImGui::Text("Address : ");
	ImGui::InputText("Address", m_TmpAddress, 25);
	ImGui::Text("Roll : ");
	ImGui::SliderInt("Roll", &m_TmpRoll, 1, ClassRegistry::MaxStudents, "%d");
	ImGui::Text("Class : ");
	ImGui::SliderInt("Class", &m_TmpClass, 9, 12, "%d");
	if (ImGui::Button("Submit"))
	{
		switch (m_TmpClass)
		{
		case 9:
			registry->Class09.AddStudent(m_TmpName, m_TmpRoll, m_TmpAddress);
			ClearTempValues();
			break;
		case 10:
			registry->Class10.AddStudent(m_TmpName, m_TmpRoll, m_TmpAddress);
			ClearTempValues();
			break;
		case 11:
			registry->Class11.AddStudent(m_TmpName, m_TmpRoll, m_TmpAddress);
			ClearTempValues();
			break;
		case 12:
			registry->Class12.AddStudent(m_TmpName, m_TmpRoll, m_TmpAddress);
			ClearTempValues();
			break;
		}
	}
	ImGui::End();
}