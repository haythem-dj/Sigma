#pragma once

#include <Sigma.h>

class Game
{
public:
	Game(unsigned int width, unsigned int height);
	~Game();

	const Sigma::Scene* GetScene() const { return &mScene; }
    const Sigma::Camera* GetCamera() const { return &mCamera; }

private:
    unsigned int mWidth = 0;
    unsigned int mHeight = 0;

	std::vector<Sigma::Vertex> mQuadVertices;
	std::vector<unsigned int> mQuadIndices;

	Sigma::Entity mPlayer;
	Sigma::Texture mPlayerTexture;
	Sigma::Material mPlayerMaterial;

	Sigma::Scene mScene;
	Sigma::Camera mCamera;
};
