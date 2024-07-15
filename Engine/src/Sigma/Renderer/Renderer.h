#pragma once

#include "../ECS/Components.h"

#include "ShaderProgram.h"

namespace Sigma
{
	class Renderer
	{
	public:
		static void Render(const MeshComponent& mesh, const TransformComponent& transform, const CameraComponent& camera, const ShaderProgram& shader);
        static void Render(const MeshComponent& mesh, const TransformComponent& transform, const MaterialComponent& material, const CameraComponent& camera, const ShaderProgram& shader);	
    };
}
