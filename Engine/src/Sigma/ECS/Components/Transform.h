#pragma once

#include <glm/glm.hpp>

namespace Sigma
{
	struct Transform
    {
        glm::vec3 Position = { 0.0f, 0.0f, 0.0f };
        glm::vec3 Rotation = { 0.0f, 0.0f, 0.0f };
        glm::vec3 Scale = { 1.0f, 1.0f, 1.0f };

        Transform() = default;
        Transform(const Transform&) = default;
        Transform(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale);

        glm::mat4 GetTransform() const;
    };
}