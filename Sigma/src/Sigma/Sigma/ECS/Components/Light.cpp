#include "sgpch.h"
#include "Light.h"

namespace Sigma
{
	DirectionalLight::DirectionalLight(glm::vec3 direction, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular)
		:Direction(direction), Ambient(ambient), Diffuse(diffuse), Specular(specular)
	{}

	PointLight::PointLight(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular)
		:Ambient(ambient), Diffuse(diffuse), Specular(specular)
	{}

	SpotLight::SpotLight(glm::vec3 direction, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular)
		:Direction(direction), Ambient(ambient), Diffuse(diffuse), Specular(specular)
	{}
}