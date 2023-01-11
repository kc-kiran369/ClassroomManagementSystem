#include "Core/Core.h"

int main()
{
	std::unique_ptr<cms::Core::Application> app = std::make_unique<cms::Core::Application>();
	app->Run();
	return EXIT_SUCCESS;
}