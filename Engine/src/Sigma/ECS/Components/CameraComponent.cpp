#include "sgpch.h"
#include "CameraComponent.h"

#include <glm/gtc/matrix_transform.hpp>

namespace Sigma
{
	CameraComponent::CameraComponent(unsigned int width, unsigned int height, float fov, float nClip, float fClip)
	{
		Width = width;
		Height = height;
		Fov = fov;
		NClip = nClip;
		FClip = fClip;

		Position = glm::vec3(0.0f, 0.0f, 1.0f);
		Rotation = glm::vec3(0.0f, 0.0f, -1.0f);

		Forward = glm::vec3(0.0f, 0.0f, -1.0f);
		Up = glm::vec3(0.0f, 1.0f, 0.0f);
	}

	glm::mat4 CameraComponent::GetProjViewMatrix() const
	{
		glm::mat4 View(1.0f);
		glm::mat4 Proj(1.0f);

		View = glm::lookAt(Position, Position + Rotation, Up);
		Proj = glm::perspective(glm::radians(Fov), (float)Width/Height, NClip, FClip);

		return Proj * View;
	}
}