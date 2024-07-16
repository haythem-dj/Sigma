#pragma once

#include <string>

#include <glad/glad.h>

#include "../../Renderer/Texture.h"

namespace Sigma
{
	struct MaterialComponent
    {
        Texture Diffuse;
        Texture Specular;
        float Shininess = 32;

        MaterialComponent() = default;
        MaterialComponent(const MaterialComponent&) = default;
        MaterialComponent(const std::string& diffusePath = "", const std::string& specualrPath = "", float shininess = 32);

        void Bind() const;

        void Unbind() const;
    };
}