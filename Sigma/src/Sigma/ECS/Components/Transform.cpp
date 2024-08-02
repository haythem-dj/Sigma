#include "sgpch.h"
#include "Transform.h"

#include <glm/gtc/matrix_transform.hpp>

namespace Sigma
{
	Transform::Transform(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale)
        :Position(position), Rotation(rotation), Scale(scale)
    {}

    glm::mat4 Transform::GetTransform() const
    {
        glm::mat4 transform(1.0f);
        transform = glm::translate(transform, Position);
        transform = glm::rotate(transform, glm::radians(Rotation.x), {1.0f, 0.0f, 0.0f});
        transform = glm::rotate(transform, glm::radians(Rotation.y), {0.0f, 1.0f, 0.0f});
        transform = glm::rotate(transform, glm::radians(Rotation.z), {0.0f, 0.0f, 1.0f});
        transform = glm::scale(transform, Scale);
        return transform;
    }
}