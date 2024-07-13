#pragma once

#include <vector>

#include <Sigma.h>

#include "Game.h"

class App : public Sigma::Application
{
public:
	App();
	~App();

private:
	unsigned int mWidth = 1080;
	unsigned int mHeight = 608;

	Sigma::ShaderProgram mShader;

	Game mGame;
};
