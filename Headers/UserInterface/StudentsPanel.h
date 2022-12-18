#pragma once

#include<imgui/imgui.h>
#include"Data/StudentRegistry.h"

class StudentsPanel
{
private:
	void DrawTable();
public:
	void Render(StudentRegistry* registry);
};