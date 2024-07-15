#pragma once

#include "Application.h"

extern Sigma::Application* Sigma::CreateApplication();

int main()
{
	Sigma::Application* app = Sigma::CreateApplication();
	app->Run();
	delete app;
	return 0;
}
