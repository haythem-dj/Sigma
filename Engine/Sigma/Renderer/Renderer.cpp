#include "Renderer.h"

#include <glad/glad.h>

namespace Sigma
{
	void Renderer::Render(const Entity& entity, const ShaderProgram& shader, const  Camera& camera)
	{
		entity.Bind();

		entity.SendUniforms(shader);
		camera.SendUniforms(shader);

		shader.Activate();
		
		glDrawElements(GL_TRIANGLES, entity.GetIndicesCount(), GL_UNSIGNED_INT, 0);
		
		shader.Deactivate();

		entity.Unbind();
	}

	void Renderer::Render(const Scene& scene, const  ShaderProgram& shader, const  Camera& camera)
	{
		scene.SendUniforms(shader);
		
		for (const Entity& entity : scene.GetEntities())
			Render(entity, shader, camera);
	}
}
