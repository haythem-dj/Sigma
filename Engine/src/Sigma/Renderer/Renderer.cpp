#include "sgpch.h"
#include "Renderer.h"

#include <glm/gtc/type_ptr.hpp>
#include <glad/glad.h>

namespace Sigma
{
    void Renderer::Render(const MeshComponent& mesh, const TransformComponent& transform, const CameraComponent& camera, const ShaderProgram& shader)
    {
        mesh.Bind();
        shader.Activate();

        glUniformMatrix4fv(glGetUniformLocation(shader.GetID(), "transform"), 1, GL_FALSE, glm::value_ptr(transform.GetTransform()));
        
        glUniform3f(glGetUniformLocation(shader.GetID(), "view_pos"), camera.Position.x, camera.Position.y, camera.Position.z);
        glUniformMatrix4fv(glGetUniformLocation(shader.GetID(), "proj_view"), 1, GL_FALSE, glm::value_ptr(camera.GetProjViewMatrix()));

        glDrawElements(GL_TRIANGLES, mesh.IndicesCount, GL_UNSIGNED_INT, 0);
        
        shader.Deactivate();
        mesh.Unbind();
    }

    void Renderer::Render(const MeshComponent& mesh, const TransformComponent& transform, const MaterialComponent& material, const CameraComponent& camera, const ShaderProgram& shader)
    {
        mesh.Bind();
        material.Bind();
        shader.Activate();

        glUniformMatrix4fv(glGetUniformLocation(shader.GetID(), "transform"), 1, GL_FALSE, glm::value_ptr(transform.GetTransform()));

        glUniform3f(glGetUniformLocation(shader.GetID(), "view_pos"), camera.Position.x, camera.Position.y, camera.Position.z);
        glUniformMatrix4fv(glGetUniformLocation(shader.GetID(), "proj_view"), 1, GL_FALSE, glm::value_ptr(camera.GetProjViewMatrix()));

        glUniform1i(glGetUniformLocation(shader.GetID(), "material.diffuse"), 0);
        glUniform1i(glGetUniformLocation(shader.GetID(), "material.specular"), 1);
        glUniform1f(glGetUniformLocation(shader.GetID(), "material.shininess"), material.Shininess);
        
        glDrawElements(GL_TRIANGLES, mesh.IndicesCount, GL_UNSIGNED_INT, 0);
        
        shader.Deactivate();
        material.Unbind();
        mesh.Unbind();
    }
}
