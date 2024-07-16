#pragma once

#include <glm/glm.hpp>

namespace Sigma
{
	struct TransformComponent
    {
        glm::vec3 Position = { 0.0f, 0.0f, 0.0f };
        glm::vec3 Rotation = { 0.0f, 0.0f, 0.0f };
        glm::vec3 Scale = { 1.0f, 1.0f, 1.0f };

        TransformComponent() = default;
        TransformComponent(const TransformComponent&) = default;
        TransformComponent(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale);

        glm::mat4 GetTransform() const;
    };
}