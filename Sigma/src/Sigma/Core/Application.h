#pragma once

#include <vector>
#include <string>

#include "Base.h"
#include "Window.h"

#include "../ECS/Scene.h"

#include "../Renderer/Renderer.h"

namespace Sigma
{
	class SIGMA_API Application
	{
	public:
		Application();
		virtual ~Application();

		inline static Application& Get() { return *sInstance; }

		void Resize(unsigned int width, unsigned int height);

		void Run();

		void SetActiveScene(Scene& scene) { mActiveScene = (Scene*)&scene; };
		void SetBackgroundColor(const glm::vec3& color) { mBackgroundColor = color; }

		Scene* GetActiveScene() const { return mActiveScene; }
		
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

		Scene* mActiveScene;

		Window mWindow;
		Renderer mRenderer;

	private:
		static Application* sInstance;

	};

	Application* CreateApplication();
}
