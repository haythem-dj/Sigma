#pragma once

#include "../../Core/Base.h"

#include <string>

#include <glad/glad.h>

#include "../../Renderer/Texture.h"

namespace Sigma
{
	struct SIGMA_API Material
    {
        Texture Diffuse;
        Texture Specular;
        float Shininess = 32;

        Material() = default;
        Material(const Material&) = default;
        Material(const std::string& diffusePath = "", const std::string& specualrPath = "", float shininess = 32);
        Material(Texture diffuse, float shininess = 32);
        Material(Texture diffuse, Texture specular, float shininess = 32);

        void Bind() const;

        void Unbind() const;
    };
}