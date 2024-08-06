#pragma once

#include <vector>
#include <string>

#include "Base.h"
#include "Window.h"

#include "../Event/ApplicationEvent.h"

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

		bool OnResize(WindowResizeEvent& e);

		void OnEvent(Event& event);

		void Run();

		void SetActiveScene(Scene& scene) { mActiveScene = (Scene*)&scene; };
		void SetBackgroundColor(const glm::vec3& color) { mBackgroundColor = color; }

		Scene* GetActiveScene() const { return mActiveScene; }

		Window* GetWindow() const { return mWindow; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);
		
	private:
		bool mRunning = false;

		glm::vec3 mBackgroundColor{0.0f};

		Scene* mActiveScene;

		Window* mWindow;
		Renderer mRenderer;

	private:
		static Application* sInstance;

	};

	Application* CreateApplication();
}
