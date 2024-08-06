#include "App.h"

App::App()
{
	mGame.Init();

	SetBackgroundColor({0.2f, 0.1f, 0.7f});

	SetActiveScene(*(Sigma::Scene*)(mGame.GetScene()));

    SG_INFO("Hello, World!");
}

App::~App()
{}
