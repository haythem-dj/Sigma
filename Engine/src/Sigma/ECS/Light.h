#pragma once

#include <GLM/glm.hpp>

namespace Sigma
{
	struct DirectionalLight
	{
		glm::vec3 Direction;

		glm::vec3 Ambient;
		glm::vec3 Diffuse;
		glm::vec3 Specular;
	};

	struct PointLight
	{
		glm::vec3 Position;

		float a, b, c;
		glm::vec3 Ambient;
		glm::vec3 Diffuse;
		glm::vec3 Specular;
	};

	struct SpotLight
	{
		glm::vec3 Position;
		glm::vec3 Direction;

		float a, b, c;

		float CutOff, OuterCutOff;

		glm::vec3 Ambient;
		glm::vec3 Diffuse;
		glm::vec3 Specular;
    };
}
