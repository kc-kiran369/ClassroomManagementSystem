#include"UserInterface/AdmissionPanel.h"

void AdmissionPanel::ClearTempValues()
{
	std::fill(std::begin(m_TmpName), std::end(m_TmpName), '\0');
	std::fill(std::begin(m_TmpAddress), std::end(m_TmpAddress), '\0');
	m_TmpRoll = 1;
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
		if (m_TmpName[0] == '\0')
		{
			CW::MessageBox::Open("You must enter valid name of the student", "Enter valid name!!!", MB_OK | MB_ICONWARNING);
			return;
		}
		if (m_TmpAddress[0] == '\0')
		{
			CW::MessageBox::Open("You must enter valid address of the student", "Enter valid address!!!", MB_OK | MB_ICONWARNING);
			return;
		}
		switch (m_TmpClass)
		{
		case 9:
			if (registry->Class09.AddStudent(m_TmpName, m_TmpRoll, m_TmpAddress))
			{
				CW::MessageBox::Open("You can now upload current data to database", "Student Admitted Successfully!!", MB_OKCANCEL | MB_ICONINFORMATION);
			}
			ClearTempValues();
			break;
		case 10:
			if (registry->Class10.AddStudent(m_TmpName, m_TmpRoll, m_TmpAddress))
			{
				CW::MessageBox::Open("You can now upload current data to database", "Student Admitted Successfully!!", MB_OKCANCEL | MB_ICONINFORMATION);
			}
			ClearTempValues();
			break;
		case 11:
			if (registry->Class11.AddStudent(m_TmpName, m_TmpRoll, m_TmpAddress))
			{
				CW::MessageBox::Open("You can now upload current data to database", "Student Admitted Successfully!!", MB_OKCANCEL | MB_ICONINFORMATION);
			}
			ClearTempValues();
			break;
		case 12:
			if (registry->Class12.AddStudent(m_TmpName, m_TmpRoll, m_TmpAddress))
			{
				CW::MessageBox::Open("You can now upload current data to database", "Student Admitted Successfully!!", MB_OKCANCEL | MB_ICONINFORMATION);
			}
			ClearTempValues();
			break;
		}
	}
	ImGui::End();
}