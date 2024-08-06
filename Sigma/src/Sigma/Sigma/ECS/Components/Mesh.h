#pragma once

#include "../../Core/Base.h"

#include <glm/glm.hpp>

namespace Sigma
{
	struct SIGMA_API Vertex
    {
        glm::vec3 Position;
        glm::vec3 Normal;
        glm::vec2 TexCoords;
    };
    
	struct SIGMA_API Mesh
    {
        unsigned int VAO, VBO, EBO;
        unsigned int IndicesCount = 0;

        Mesh() = default;
        Mesh(const Mesh&) = default;
        Mesh(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices);
        
        void Bind() const;
        void Unbind() const;
    };
}