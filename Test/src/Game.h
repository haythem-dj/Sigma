#pragma once

#include <Sigma.h>

class Game
{
public:
	Game();
	~Game();

    void Init();

	const Sigma::Scene* GetScene() const { return &mScene; }

private:
	void DrawTexture(Sigma::Texture texture, glm::vec4 src, glm::vec4 dst);

private:
    unsigned int mWidth = 0;
    unsigned int mHeight = 0;

	Sigma::Entity mCamera;

	Sigma::Scene mScene;
    Sigma::ShaderProgram mShader;

    unsigned int mTextureCount = 0;
};
