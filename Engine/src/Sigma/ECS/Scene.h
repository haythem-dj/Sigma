#pragma once

#include <vector>
#include <entt.hpp>

#include "../Renderer/ShaderProgram.h"

namespace Sigma
{
    class Entity;

	class Scene
	{
	public:
		Scene();
		~Scene();

		Entity CreateEntity(const std::string& name = "");
        void DestroyEntity(Entity entity);

        void Update(float dt);

        const Entity* GetCamera() const { return mActiveCamera; }
        void SetCamera(Entity* entity);
        
        const ShaderProgram* GetShader() const { return mActiveShader; }
        void SetShader(ShaderProgram* shader) { mActiveShader = shader; }

	private:
        entt::registry mRegistry;

        ShaderProgram* mActiveShader = nullptr;
        Entity* mActiveCamera = nullptr;

        friend class Entity;
	};
};
