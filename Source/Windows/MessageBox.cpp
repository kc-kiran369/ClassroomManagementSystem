#include"Windows/MessageBox.h"

int cms::Windows::PromptBox::Open(const char* description, const char* title, unsigned int type)
{
	int result = MessageBoxA(GetActiveWindow(), description, title, type);
	return result;
}

int cms::Windows::PromptBox::Open(const char* description, unsigned int type)
{
	int result = MessageBoxA(GetActiveWindow(), description, cms::Core::Serializer::Instance().GetString("app_name").c_str(), type);
	return result;
}