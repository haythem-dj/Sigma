#pragma once

#include <glm/glm.hpp>

namespace Sigma
{
	struct Vertex
    {
        glm::vec3 Position;
        glm::vec3 Normal;
        glm::vec2 TexCoords;
    };
    
	struct MeshComponent
    {
        unsigned int VAO, VBO, EBO;
        unsigned int IndicesCount = 0;

        MeshComponent() = default;
        MeshComponent(const MeshComponent&) = default;
        MeshComponent(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices);
        
        void Bind() const;
        void Unbind() const;
    };
}