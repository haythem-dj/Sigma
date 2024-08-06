#pragma once

#include "../../Core/Base.h"

#include <glm/glm.hpp>

namespace Sigma
{
	struct SIGMA_API DirectionalLight
	{
		glm::vec3 Direction{ 0.0f, -1.0f, 0.0f };

		glm::vec3 Ambient{0.1f, 0.1f, 0.1f};
		glm::vec3 Diffuse{1.0f, 1.0f, 1.0f};
		glm::vec3 Specular{1.0f, 1.0f, 1.0f};

		DirectionalLight() = default;
		DirectionalLight(DirectionalLight&) = default;
		DirectionalLight(glm::vec3 direction, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular);
	};

	struct SIGMA_API PointLight
	{
		float a = 0.2f;
		float b = 0.22f;
		float c = 1.0;

		glm::vec3 Ambient{0.1f, 0.1f, 0.1f};
		glm::vec3 Diffuse{1.0f, 1.0f, 1.0f};
		glm::vec3 Specular{1.0f, 1.0f, 1.0f};

		PointLight() = default;
		PointLight(PointLight&) = default;
		PointLight(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular);
	};

	struct SIGMA_API SpotLight
	{
		glm::vec3 Direction{0.0f, 0.0f, -1.0f};

		float a = 0.2f;
		float b = 0.22f;
		float c = 1.0;

		float CutOff = 25.0f;
		float OuterCutOff = 35.0f;

		glm::vec3 Ambient{0.1f, 0.1f, 0.1f};
		glm::vec3 Diffuse{1.0f, 1.0f, 1.0f};
		glm::vec3 Specular{1.0f, 1.0f, 1.0f};

		SpotLight() = default;
		SpotLight(SpotLight&) = default;
		SpotLight(glm::vec3 direction, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular);
    };
}
