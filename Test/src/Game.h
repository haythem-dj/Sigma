#pragma once

#include <Sigma.h>

class Game
{
public:
	Game();
	~Game();

    void Init(unsigned int width, unsigned int height);

	const Sigma::Scene* GetScene() const { return &mScene; }

private:
    unsigned int mWidth = 0;
    unsigned int mHeight = 0;

	std::vector<Sigma::Vertex> mQuadVertices;
	std::vector<unsigned int> mQuadIndices;

	Sigma::Entity mPlayer, mCameraEntity;

	Sigma::Scene mScene;
    Sigma::ShaderProgram mShader;
};
