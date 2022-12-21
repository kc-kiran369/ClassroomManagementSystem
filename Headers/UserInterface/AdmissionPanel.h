#ifndef PANEL_ADMISSION_H
#define PANEL_ADMISSION_H

#include<iostream>
#include<imgui/imgui.h>

#include"Data/ClassRegistry.h"
#include"Data/StudentRegistry.h"
#include"Windows/MessageBox.h"

namespace cms
{
	class AdmissionPanel
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
		AdmissionPanel();
		~AdmissionPanel();
		void Draw(StudentRegistry* registry);
	};
}
#endif