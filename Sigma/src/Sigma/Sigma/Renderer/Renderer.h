#pragma once

#include "../Core/Base.h"

#include "../ECS/Components.h"

#include "ShaderProgram.h"

namespace Sigma
{
	class SIGMA_API Renderer
	{
	public:
		static void Render(const Mesh& mesh, const Transform& transform, const Camera& camera, const ShaderProgram& shader);
        static void Render(const Mesh& mesh, const Transform& transform, const Material& material, const Camera& camera, const ShaderProgram& shader);	
    };
}
