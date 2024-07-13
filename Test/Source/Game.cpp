#include "Game.h"

Game::Game(unsigned int width, unsigned int height)
    :mWidth(width), mHeight(height)
{
	mScene = Sigma::Scene();

    mCamera.Init(mWidth, mHeight, 75.0f, 0.1f, 100.0f);
	mCamera.SetPosition({0.0f, 0.0f, 5.0f});
	mCamera.SetRotation({0.0f, 0.0f, -1.0f});

	mQuadVertices = {
		{ {-0.5f, 0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}, {0.0f, 0.0f} },
		{ { 0.5f, 0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}, {1.0f, 0.0f} },
		{ { 0.5f,-0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}, {1.0f, 1.0f} },
		{ {-0.5f,-0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}, {0.0f, 1.0f} }
	};

	mQuadIndices = {
		0, 1, 2, 0, 2, 3
	};

	mPlayer.SetVertices(mQuadVertices);
	mPlayer.SetIndices(mQuadIndices);
    mPlayer.SetRotation({0.0f, 0.0f, 45.0f});
	mPlayerTexture.Load("Resources/textures/plank.jpg", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA);
	mPlayerMaterial = {mPlayerTexture, mPlayerTexture, 32};
	mPlayer.SetMaterial(mPlayerMaterial);

	Sigma::DirectionalLight light = {
		{0.0f, -1.0f, 0.0f},
		{1.0f, 1.0f, 1.0f},
		{1.0f, 1.0f, 1.0f},
		{1.0f, 1.0f, 1.0f}
	};

	mScene.AddDirectionalLight(light);
	mScene.AddEntity(mPlayer);
}

Game::~Game()
{
    mScene.Clear();
}
