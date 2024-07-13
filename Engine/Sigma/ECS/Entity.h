#pragma once

#include <GLM/glm.hpp>

#include <algorithm>
#include <vector>

#include "Light.h"

#include "../Renderer/ShaderProgram.h"
#include "../Renderer/Texture.h"

namespace Sigma
{
	struct Vertex
	{
		glm::vec3 Position;
		glm::vec3 Normal;
		glm::vec2 TexCoords;
	};

	struct Material
	{
		Texture Diffuse;
		Texture Specular;
		float Shininess = 0.0f;
	};

	class Entity
	{
	public:
		Entity();
		~Entity();

		void Bind() const;
		void Unbind() const;

		bool LoadFromFile(const char* path);
		void Update();
		void Delete();

		void SendUniforms(const ShaderProgram& shader) const;

		void SetVertices(const std::vector<Vertex>& vertices);
		void SetIndices(const std::vector<unsigned int>& indices);
		void SetMaterial(const Material& material);

		void SetPosition(glm::vec3 Position);
		void SetRotation(glm::vec3 Rotation);
		void SetScale(glm::vec3 Scale);

		glm::vec3 GetPosition() const { return mPosition; }
		glm::vec3 GetRotation() const { return mRotation; }
		glm::vec3 GetScale() const { return mScale; }
		glm::mat4 GetModelMatrix() const { return mModelMatrix; }

		unsigned int GetIndicesCount() const { return mIndicesCount; }

	private:
        unsigned int vao, vbo, ebo;
		unsigned int mIndicesCount = 0;

        glm::vec3 mPosition = { 0.0f, 0.0f, 0.0f };
        glm::vec3 mRotation = { 0.0f, 0.0f, 0.0f };
        glm::vec3 mScale = { 1.0f, 1.0f, 1.0f };

		Material mMaterial;

		glm::mat4 mModelMatrix = glm::mat4(1.0f);
	};
}
