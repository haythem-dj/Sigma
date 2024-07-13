#include "Scene.h"

#include <iostream>
#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Sigma
{
	Scene::Scene()
	{}

	Scene::~Scene()
	{}

	void Scene::AddEntity(const Entity& entity)
	{
		mEntities.push_back(entity);
	}

	void Scene::AddDirectionalLight(const DirectionalLight& light)
	{
		mDirLights.push_back(light);
	}

	void Scene::AddPointLight(const PointLight& light)
	{
		mPointLights.push_back(light);
	}

	void Scene::AddSpotLight(const SpotLight& light)
	{
		mSpotLights.push_back(light);
	}

	void Scene::SendUniforms(const ShaderProgram& shader) const
	{
		shader.Activate();
		
		glUniform1i(glGetUniformLocation(shader.GetID(), "numDirLight"), mDirLights.size());
		glUniform1i(glGetUniformLocation(shader.GetID(), "numPointLight"), mPointLights.size());
		glUniform1i(glGetUniformLocation(shader.GetID(), "numSpotLight"), mSpotLights.size());

		for (int i = 0; i < mDirLights.size(); i++)
		{
			const DirectionalLight& light = mDirLights[i];
			std::string name = "dirLights[" + std::to_string(i) + "].";

			glUniform3f(glGetUniformLocation(shader.GetID(), (name + "direction").c_str()),
				light.Direction.x, light.Direction.y, light.Direction.z);

			glUniform3f(glGetUniformLocation(shader.GetID(), (name + "ambient").c_str()),
				light.Ambient.x, light.Ambient.y, light.Ambient.z);
			glUniform3f(glGetUniformLocation(shader.GetID(), (name + "diffuse").c_str()),
				light.Diffuse.x, light.Diffuse.y, light.Diffuse.z);
			glUniform3f(glGetUniformLocation(shader.GetID(), (name + "specular").c_str()),
				light.Specular.x, light.Specular.y, light.Specular.z);
		}

		for (int i = 0; i < mPointLights.size(); i++)
		{
			const PointLight& light = mPointLights[i];
			std::string name = "pointLights[" + std::to_string(i) + "].";

			glUniform3f(glGetUniformLocation(shader.GetID(), (name + "position").c_str()),
				light.Position.x, light.Position.y, light.Position.z);

			glUniform1f(glGetUniformLocation(shader.GetID(), (name + "a").c_str()), light.a);
			glUniform1f(glGetUniformLocation(shader.GetID(), (name + "b").c_str()), light.b);
			glUniform1f(glGetUniformLocation(shader.GetID(), (name + "c").c_str()), light.c);

			glUniform3f(glGetUniformLocation(shader.GetID(), (name + "ambient").c_str()),
				light.Ambient.x, light.Ambient.y, light.Ambient.z);
			glUniform3f(glGetUniformLocation(shader.GetID(), (name + "diffuse").c_str()),
				light.Diffuse.x, light.Diffuse.y, light.Diffuse.z);
			glUniform3f(glGetUniformLocation(shader.GetID(), (name + "specular").c_str()),
				light.Specular.x, light.Specular.y, light.Specular.z);
		}	

		for (int i = 0; i < mSpotLights.size(); i++)
		{
			const SpotLight& light = mSpotLights[i];
			std::string name = "spotLights[" + std::to_string(i) + "].";

			glUniform3f(glGetUniformLocation(shader.GetID(), (name + "position").c_str()),
				light.Position.x, light.Position.y, light.Position.z);
			glUniform3f(glGetUniformLocation(shader.GetID(), (name + "direction").c_str()),
				light.Direction.x, light.Direction.y, light.Direction.z);

			glUniform1f(glGetUniformLocation(shader.GetID(), (name + "cutOff").c_str()), light.CutOff);
			glUniform1f(glGetUniformLocation(shader.GetID(), (name + "outerCutOff").c_str()), light.OuterCutOff);

			glUniform1f(glGetUniformLocation(shader.GetID(), (name + "a").c_str()), light.a);
			glUniform1f(glGetUniformLocation(shader.GetID(), (name + "b").c_str()), light.b);
			glUniform1f(glGetUniformLocation(shader.GetID(), (name + "c").c_str()), light.c);

			glUniform3f(glGetUniformLocation(shader.GetID(), (name + "ambient").c_str()),
				light.Ambient.x, light.Ambient.y, light.Ambient.z);
			glUniform3f(glGetUniformLocation(shader.GetID(), (name + "diffuse").c_str()),
				light.Diffuse.x, light.Diffuse.y, light.Diffuse.z);
			glUniform3f(glGetUniformLocation(shader.GetID(), (name + "specular").c_str()),
				light.Specular.x, light.Specular.y, light.Specular.z);
		}

		shader.Deactivate();
	}

	void Scene::Clear()
	{
		for(Entity& entity : mEntities)
			entity.Delete();

		mEntities.clear();
		mDirLights.clear();
		mPointLights.clear();
		mSpotLights.clear();
	}
}
