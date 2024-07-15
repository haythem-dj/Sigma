#include "App.h"

#include <iostream>

App::App()
{
	SetWidth(mWidth);
	SetHeight(mHeight);	

    mGame.Init(mWidth, mHeight);

	SetBackgroundColor({0.2f, 0.1f, 0.7f});

	SetActiveScene(*(Sigma::Scene*)(mGame.GetScene()));
}

App::~App()
{}
