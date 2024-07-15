#include "Game.h"

#include "CameraScript.h"
#include "PlayerScript.h"

Game::Game()
{}

Game::~Game()
{}

void Game::Init(unsigned int width, unsigned int height)
{
    mWidth = width;
    mHeight = height;

    mQuadVertices = {
        { {-0.5f, 0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}, {0.0f, 0.0f} },
        { { 0.5f, 0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}, {1.0f, 0.0f} },
        { { 0.5f,-0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}, {1.0f, 1.0f} },
        { {-0.5f,-0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}, {0.0f, 1.0f} }
    };

    mQuadIndices = {
        0, 1, 2, 0, 2, 3
    };

    mShader.Init("Resources/shaders/test.vert", "Resources/shaders/test.frag");
    
    mPlayer = mScene.CreateEntity();
    mCameraEntity = mScene.CreateEntity();

    mCameraEntity.AddComponent<Sigma::CameraComponent>(mWidth, mHeight, 75.0f, 0.1f, 100.0f);
    mCameraEntity.AddComponent<Sigma::NativeScriptComponent>().Bind<CameraScript>();

    mPlayer.AddComponent<Sigma::TransformComponent>(Sigma::TransformComponent(
        { 0.0f, 0.0f, 0.0f },
        { 0.0f, 0.0f, 45.0f },
        { 1.0f, 1.0f, 1.0f }
    ));

    mPlayer.AddComponent<Sigma::MeshComponent>(mQuadVertices, mQuadIndices);
    mPlayer.AddComponent<Sigma::MaterialComponent>("Resources/textures/brick.png");
    mPlayer.AddComponent<NativeScriptComponent>().Bind<PlayerScript>();

	mScene.SetShader(&mShader);
    mScene.SetCamera(&mCameraEntity);
}
