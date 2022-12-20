#pragma once

#include<iostream>
#include<imgui/imgui.h>
#include"Data/ClassRegistry.h"
#include"Data/StudentRegistry.h"
#include"Windows/MessageBox.h"

class AdmissionPanel
{
private:
	char m_TmpName[25];
	char m_TmpAddress[25];
	int m_TmpRoll = 1;
	int m_TmpClass = 9;

	void ClearTempValues();
public:
	AdmissionPanel();
	~AdmissionPanel();
	void Draw(StudentRegistry* registry);
};