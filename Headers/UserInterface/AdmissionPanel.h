#pragma once

#include<iostream>
#include<imgui/imgui.h>
#include"Data/ClassRegistry.h"
#include"Data/StudentRegistry.h"

class AdmissionPanel
{
private:
	char m_TmpName[25];
	char m_TmpAddress[25];
	int m_TmpRoll = 0;
	int m_TmpClass = 9;

	void ClearTempValues();
public:
	AdmissionPanel();
	~AdmissionPanel();
	void Draw(StudentRegistry* registry);
};