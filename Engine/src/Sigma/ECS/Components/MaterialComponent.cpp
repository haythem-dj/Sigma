#include "MaterialComponent.h"

namespace Sigma
{
    MaterialComponent::MaterialComponent(const std::string& diffusePath, const std::string& specualrPath, float shininess)
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

    void MaterialComponent::Bind() const
    {
        Diffuse.Bind();
        Specular.Bind();
    }

    void MaterialComponent::Unbind() const
    {
        Diffuse.Unbind();
        Specular.Unbind();
    }
}