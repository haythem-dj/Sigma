#pragma once

#include <GLM/glm.hpp>

#include "../Core/Camera.h"

#include "../ECS/Scene.h"
#include "../ECS/Entity.h"

#include "ShaderProgram.h"
#include "Texture.h"

namespace Sigma
{
	class Renderer
	{
	public:
		void Render(const Entity& entity, const ShaderProgram& shader, const Camera& camera);
		void Render(const Scene& scene, const ShaderProgram& shader, const Camera& camera);
	};
}
