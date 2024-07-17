#pragma once

#include "../ECS/Components.h"

#include "ShaderProgram.h"

namespace Sigma
{
	class Renderer
	{
	public:
		static void Render(const Mesh& mesh, const Transform& transform, const Camera& camera, const ShaderProgram& shader);
        static void Render(const Mesh& mesh, const Transform& transform, const Material& material, const Camera& camera, const ShaderProgram& shader);	
    };
}
