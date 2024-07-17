#include "Game.h"

#include "CameraScript.h"
#include "PlayerScript.h"
#include "FlashLightScript.h"

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

    mShader.Init("res/shaders/default.vert", "res/shaders/default.frag");
    
    mPlayer = mScene.CreateEntity("player");
    mCamera = mScene.CreateEntity("camera");
    Sigma::Entity flashLight = mScene.CreateEntity("flash light");
    Sigma::Entity Light = mScene.CreateEntity();

    // auto& dLight = Light.AddComponent<Sigma::DirectionalLight>();
    // dLight.Direction = glm::vec3(0.0f, 0.0f, -1.0f);
    // dLight.Ambient = glm::vec3(0.2f, 0.2f, 0.2f);
    // dLight.Diffuse = glm::vec3(0.5f, 0.5f, 0.5f);
    // dLight.Specular = glm::vec3(0.5f, 0.5f, 0.5f);

    // // Light.AddComponent<Sigma::SpotLight>();
    // auto& light = Light.AddComponent<Sigma::PointLight>();
    // light.a = 0.032;
    // light.b = 0.09;

    // auto& transform = Light.AddComponent<Sigma::Transform>();
    // transform.Position = {0.5f, 0.5f, 1.5f};

    mCamera.AddComponent<Sigma::Camera>(mWidth, mHeight, 75.0f, 0.1f, 100.0f);
    mCamera.AddComponent<Sigma::NativeScript>().Bind<CameraScript>();

    mPlayer.AddComponent<Sigma::Transform>();

    mPlayer.AddComponent<Sigma::Mesh>(mQuadVertices, mQuadIndices);
    mPlayer.AddComponent<Sigma::Material>("res/textures/container_diffuse.png", "res/textures/container_specular.png");
    mPlayer.AddComponent<Sigma::NativeScript>().Bind<PlayerScript>();

    auto& light = flashLight.AddComponent<Sigma::SpotLight>();
    light.a = 0.032;
    light.b = 0.09;
    light.Ambient = glm::vec3(0.0f, 0.0f, 0.0f);
    light.Diffuse = glm::vec3(1.0f, 1.0f, 1.0f);
    light.Specular = glm::vec3(1.0f, 1.0f, 1.0f);
    light.CutOff = 12.5f;
    light.OuterCutOff = 17.5f;

    flashLight.AddComponent<Sigma::Transform>();
    flashLight.AddComponent<Sigma::NativeScript>().Bind<FlashLightScript>();

	mScene.SetShader(&mShader);
    mScene.SetCamera(&mCamera);
}
