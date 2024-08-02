#include "sgpch.h"
#include "Material.h"

namespace Sigma
{
    Material::Material(const std::string& diffusePath, const std::string& specualrPath, float shininess)
    {
        Shininess = shininess;
        if (diffusePath != "")
        {
            Diffuse.Load(diffusePath.c_str(), GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA);
            if (specualrPath != "")
            {
                Specular.Load(specualrPath.c_str(), GL_TEXTURE_2D, GL_TEXTURE1, GL_RGBA);
            }
            else
            {
                Specular = Diffuse;
            }
        }
    }

    Material::Material(Texture diffuse, float shininess)
    {
        Diffuse = diffuse;
        Specular = diffuse;
        Shininess = shininess;
    }

    Material::Material(Texture diffuse, Texture specular, float shininess)
    {
        Diffuse = diffuse;
        Specular = specular;
        Shininess = shininess;
    }

    void Material::Bind() const
    {
        Diffuse.Bind();
        Specular.Bind();
    }

    void Material::Unbind() const
    {
        Diffuse.Unbind();
        Specular.Unbind();
    }
}