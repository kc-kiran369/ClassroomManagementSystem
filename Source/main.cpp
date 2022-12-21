#include"Core/Application.h"

int main()
{
	std::unique_ptr<cms::Application> app = std::make_unique<cms::Application>("Classroom Management (64-bit, windows)", 1000, 600);
	app->Run();
	return EXIT_SUCCESS;
}