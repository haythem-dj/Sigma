#include "Game.h"

#include "Scripts/CameraScript.h"

Game::Game()
{}

Game::~Game()
{}

void Game::Init(unsigned int width, unsigned int height)
{
    mWidth = width;
    mHeight = height;

    mShader.Init("res/shaders/default.vert", "res/shaders/default.frag");
    
    mCamera = mScene.CreateEntity("camera");
    Sigma::Entity Light = mScene.CreateEntity("light");

    auto& dLight = Light.AddComponent<Sigma::DirectionalLight>();
    dLight.Direction = glm::vec3(0.0f, 0.0f, -1.0f);
    dLight.Ambient = glm::vec3(1.0f, 1.0f, 1.0f);
    dLight.Diffuse = glm::vec3(1.0f, 1.0f, 1.0f);
    dLight.Specular = glm::vec3(1.0f, 1.0f, 1.0f);

    mCamera.AddComponent<Sigma::Camera>(mWidth, mHeight, 75.0f, 0.1f, 100.0f);
    mCamera.AddComponent<Sigma::NativeScript>().Bind<CameraScript>();

    Sigma::Texture test("res/Test/Characters/basic_character_spritesheet.png");
    DrawTexture(test, {0.0f, 0.0f, 0.25f, 0.25f}, {-0.5f, -0.5f, 0.0f, 0.0f});

	mScene.SetShader(&mShader);
    mScene.SetCamera(&mCamera);
}

void Game::DrawTexture(Sigma::Texture texture, glm::vec4 src, glm::vec4 dst)
{
    std::vector<Sigma::Vertex> quadVertices  = {
        { {-0.5f, 0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}, {src.x, src.y} },
        { { 0.5f, 0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}, {src.z, src.y} },
        { { 0.5f,-0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}, {src.z, src.w} },
        { {-0.5f,-0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}, {src.x, src.w} }
    };

    std::vector<unsigned int> quadIndices = {
        0, 1, 2, 0, 2, 3
    };

    float scaleX = (dst.z - dst.x) / (src.z - src.x);
    float scaleY = (dst.w - dst.y) / (src.w - src.y);

    Sigma::Entity entity = mScene.CreateEntity("texture" + std::to_string(mTextureCount));

    entity.AddComponent<Transform>(glm::vec3(dst.x, dst.y, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(scaleX, scaleY, 1.0f));
    entity.AddComponent<Mesh>(quadVertices, quadIndices);
    entity.AddComponent<Material>(texture);
}
