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
	Game mGame;
};
