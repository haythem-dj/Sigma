#pragma once

// #include "Application.h"
#include "Sigma/Core/Base.h"

extern Sigma::Application* Sigma::CreateApplication();

int main()
{
	Sigma::Log::Init();

	SG_CORE_INFO("app created");
	Sigma::Application* app = Sigma::CreateApplication();

	SG_CORE_INFO("app running");
	app->Run();

	SG_CORE_INFO("app deleted");
	delete app;
	return 0;
}