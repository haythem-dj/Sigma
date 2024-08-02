#pragma once

#include <vector>
#include <entt/entt.hpp>

#include "../Core/Base.h"

#include "../Renderer/ShaderProgram.h"

namespace Sigma
{
    class Entity;

	class SIGMA_API Scene
	{
	public:
		Scene();
		~Scene();

		Entity CreateEntity(const std::string& name = "");
        void DestroyEntity(Entity entity);
        Entity GetEntity(const std::string& name);

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
