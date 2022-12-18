#include<iostream>
#include<memory>
#include"Core/Application.h"

int main()
{
	std::unique_ptr<CW::Application> app = std::make_unique<CW::Application>("Classroom Manager", 1000, 600);
	app->Run();

	return EXIT_SUCCESS;
}