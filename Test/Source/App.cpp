#include "App.h"

#include <iostream>

App::App()
    :mGame(mWidth, mHeight)
{
	SetWidth(mWidth);
	SetHeight(mHeight);	

	mShader.Init("Resources/shaders/default.vert", "Resources/shaders/default.frag");

	SetActiveCamera(mGame.GetCamera());
	SetShader(&mShader);
	SetBackgroundColor({0.2f, 0.1f, 0.7f});

	SetActiveScene(mGame.GetScene());
}

App::~App()
{}
