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
        SG_CORE_INFO("diffuse: {0}, specular: {1}", Diffuse.GetID(), Specular.GetID());
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