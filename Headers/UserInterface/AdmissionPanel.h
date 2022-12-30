#ifndef PANEL_ADMISSION_H
#define PANEL_ADMISSION_H

#include<iostream>
#include<imgui/imgui.h>

#include"Data/ClassRegistry.h"
#include"Data/StudentRegistry.h"
#include"Panel.h"
#include"Windows/MessageBox.h"

namespace cms::UI
{
	class AdmissionPanel : public Panel
	{
	private:
		char m_TmpName[25];
		char m_TmpAddress[25];
		int m_TmpRoll = 1;
		int m_TmpClass = 9;
		int m_ClassIndex = 0;

		const char* const m_Classes[4] = { "Nine","Ten","Eleven","Twelve" };

		void ClearTempValues();
	public:
		AdmissionPanel() = default;
		AdmissionPanel(Data::StudentRegistry* registry);
		~AdmissionPanel();

		void Draw() override;
		void SetRegistry(Data::StudentRegistry* Registry) override;
	};
}
#endif