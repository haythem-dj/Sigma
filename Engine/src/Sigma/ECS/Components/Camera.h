#pragma once

#include <glm/glm.hpp>

namespace Sigma
{
	struct Camera
    {
    	unsigned int Width = 0;
    	unsigned int Height = 0;

    	float Fov = 0.0f;
		float NClip = 0.0f;
		float FClip = 0.0f;

        glm::vec3 Position{ 0.0f, 0.0f, 1.0f };
        glm::vec3 Rotation{ 0.0f, 0.0f, -1.0f };
        glm::vec3 Forward{ 0.0f, 0.0f, -1.0f };
        glm::vec3 Up{ 0.0f, 1.0f, 0.0f };

        Camera() = default;
        Camera(Camera&) = default;
        Camera(unsigned int width, unsigned int height, float fov, float nClip, float fClip);

        glm::mat4 GetProjViewMatrix() const;
    };
}