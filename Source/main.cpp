#include "Core/Core.h"

//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
int main()
{
	std::unique_ptr<cms::Core::Application> app = std::make_unique<cms::Core::Application>(
		cms::Core::Serializer::Instance().GetString("app_name").c_str(),
		cms::Core::Serializer::Instance().GetInt("width"),
		cms::Core::Serializer::Instance().GetInt("height"));
	app->Run();
	return EXIT_SUCCESS;
}