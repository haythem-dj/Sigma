#pragma once

#include <vector>
#include <string>

#include "Window.h"
#include "Camera.h"

#include "../ECS/Scene.h"

#include "../Renderer/Renderer.h"
#include "../Renderer/ShaderProgram.h"

namespace Sigma
{
	class Application
	{
	public:
		Application();
		virtual ~Application();

		inline static Application& Get() { return *sInstance; }

		void Resize(unsigned int width, unsigned int height);
		void Render();

		void Run();

		void SetActiveScene(const Scene* scene) { mActiveScene = scene; };
		void SetShader(const ShaderProgram* shader) { mAppShader = shader; } ;
		void SetActiveCamera(const Camera* camera) { mActiveCamera = camera; }

		void SetBackgroundColor(const glm::vec3& color) { mBackgroundColor = color; }

		const Scene* GetActiveScene() const { return mActiveScene; }
		const ShaderProgram* GetShader() const { return mAppShader; }
		const Camera* GetActiveCamera() const { return mActiveCamera; }

		void SetWidth(unsigned int width) { mWidth = width; }
		void SetHeight(unsigned int height) { mHeight = height; }
		unsigned int GetWidth() const { return mWidth; }
		unsigned int GetHeight() const { return mHeight; }

		Window GetWindow() const { return mWindow; }
		
	private:
		bool mRunning = false;

		unsigned int mWidth = 0;
		unsigned int mHeight = 0;
		std::string mTitle = "Sigma Engine";

		glm::vec3 mBackgroundColor{0.0f};

		const Scene* mActiveScene = nullptr;
        const Camera* mActiveCamera = nullptr;

		Window mWindow;
		Renderer mRenderer;
		const ShaderProgram* mAppShader = nullptr;

	private:
		static Application* sInstance;

	};

	Application* CreateApplication();
}
