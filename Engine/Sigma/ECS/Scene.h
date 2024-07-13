#pragma once

#include <vector>

#include "Entity.h"

#include "../Renderer/ShaderProgram.h"

namespace Sigma
{
	class Scene
	{
	friend class Application;
	public:
		Scene();
		~Scene();

		void AddEntity(const Entity& entity);

		void AddDirectionalLight(const DirectionalLight& light);
		void AddPointLight(const PointLight& light);
		void AddSpotLight(const SpotLight& light);

		void SendUniforms(const ShaderProgram& shader) const;

		void Clear();

		const std::vector<Entity>& GetEntities() const { return mEntities; }

		const std::vector<DirectionalLight>& GetDirLights() const { return mDirLights; }
		const std::vector<PointLight>& GetPointLights() const { return mPointLights; }
		const std::vector<SpotLight>& GetSpotLights() const { return mSpotLights; }

	private:
		std::vector<Entity> mEntities;

		std::vector<DirectionalLight> mDirLights;
		std::vector<PointLight> mPointLights;
		std::vector<SpotLight> mSpotLights;

	};
};
