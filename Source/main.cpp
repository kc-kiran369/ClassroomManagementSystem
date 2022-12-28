#include"Core/Application.h"
#include"Core/Serializer.h"

int main()
{
	std::unique_ptr<cms::Application> app = std::make_unique<cms::Application>(
		"Classroom Management (64-bit, windows)", 
		Serializer::Instance().GetInt("width"), 
		Serializer::Instance().GetInt("height"));
	app->Run();
	return EXIT_SUCCESS;
}