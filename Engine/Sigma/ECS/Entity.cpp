#include "Entity.h"

#include <glad/glad.h>
#include <GLM/gtc/matrix_transform.hpp>
#include <GLM/gtc/type_ptr.hpp>

#include <iostream>
#include <sstream>
#include <fstream>

namespace Sigma
{
	Entity::Entity()
	{
		glGenVertexArrays(1, &vao);
		glGenBuffers(1, &vbo);
		glGenBuffers(1, &ebo);
	}

	Entity::~Entity()
	{}

	void Entity::Bind() const
	{
		mMaterial.Diffuse.Bind();
		mMaterial.Specular.Bind();

		glBindVertexArray(vao);
		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);
		glEnableVertexAttribArray(2);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	}

	void Entity::Unbind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
		glDisableVertexAttribArray(2);
		glBindVertexArray(0);

		mMaterial.Specular.Unbind();
		mMaterial.Diffuse.Unbind();
	}

	bool Entity::LoadFromFile(const char* path)
	{
		std::ifstream file(path);
		std::string line;

		if (!file.is_open())
			return false;

		std::vector<Vertex> verts = {};
		std::vector<unsigned int> indes = {};

		std::vector<glm::vec3> positions = {};
		std::vector<glm::vec3> normals = {};
		std::vector<glm::vec2> textures = {};

		unsigned int index = 0;
		while (getline(file, line))
		{
			std::stringstream s;
			char junk;

			s << line;

			if (line.rfind("v ", 0) == 0)
			{
				glm::vec3 position;
				s >> junk >> position.x >> position.y >> position.z;
				positions.push_back(position);
			}
			else if (line.rfind("vt", 0) == 0)
			{
				glm::vec2 texture;
				s >> junk >> junk >> texture.x >> texture.y;
				textures.push_back(texture);
			}
			else if (line.rfind("vn", 0) == 0)
			{
				glm::vec3 normal;
				s >> junk >> junk >> normal.x >> normal.y >> normal.z;
				normals.push_back(normal);
			}
			else if (line.rfind("f", 0) == 0)
			{
				s >> junk;
				for (int i = 0; i < 3; i++)
				{
					Vertex vert;
					unsigned int v = 0, t = 0, n = 0;
					s >> v >> junk >> t >> junk >> n;
					if (positions.size() > 0)
						vert.Position = positions[v - 1];
					if (textures.size() > 0)
						vert.TexCoords = textures[t - 1];
					if (normals.size() > 0)
						vert.Normal = normals[n - 1];

					verts.push_back(vert);
					indes.push_back(index);

					index++;
				}
			}
		}

		file.close();

		SetVertices(verts);
		SetIndices(indes);

		return true;
	}

	void Entity::Update()
	{
		mModelMatrix = glm::translate(mModelMatrix, mPosition);
		mModelMatrix = glm::rotate(mModelMatrix, glm::radians(mRotation.x), glm::vec3{1.0f, 0.0f, 0.0f});
		mModelMatrix = glm::rotate(mModelMatrix, glm::radians(mRotation.y), glm::vec3{0.0f, 1.0f, 0.0f});
		mModelMatrix = glm::rotate(mModelMatrix, glm::radians(mRotation.z), glm::vec3{0.0f, 0.0f, 1.0f});
		mModelMatrix = glm::scale(mModelMatrix, mScale);
	}

	void Entity::Delete()
	{
		glDeleteVertexArrays(1, &vao);
		glDeleteBuffers(1, &vbo);
		glDeleteBuffers(1, &ebo);

		mMaterial.Diffuse.Delete();
		mMaterial.Specular.Delete();
	}

	void Entity::SendUniforms(const ShaderProgram& shader) const
	{
		shader.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shader.GetID(), "model"), 1, GL_FALSE, glm::value_ptr(mModelMatrix));

		glUniform1i(glGetUniformLocation(shader.GetID(), "material.diffuse"), 0);
		glUniform1i(glGetUniformLocation(shader.GetID(), "material.specular"), 1);
		glUniform1f(glGetUniformLocation(shader.GetID(), "material.shininess"), mMaterial.Shininess);
		shader.Deactivate();
	}

	void Entity::SetVertices(const std::vector<Vertex>& vertices)
	{
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		glBindVertexArray(vao);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_TRUE, sizeof(Vertex), 0);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_TRUE, sizeof(Vertex), (void*)(3*sizeof(float)));
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_TRUE, sizeof(Vertex), (void*)(6*sizeof(float)));
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}

	void Entity::SetIndices(const std::vector<unsigned int>& indices)
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);
		mIndicesCount = (unsigned int)indices.size();
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);		
	}

	void Entity::SetMaterial(const Material& material)
	{
		mMaterial = material;
	}

	void Entity::SetPosition(glm::vec3 Position)
	{
		mPosition = Position;
		mModelMatrix = glm::mat4(1.0f);
		Update();
	}

	void Entity::SetRotation(glm::vec3 Rotation)
	{
		mRotation = Rotation;
		mModelMatrix = glm::mat4(1.0f);
		Update();
	}

	void Entity::SetScale(glm::vec3 Scale)
	{
		mScale = Scale;
		mModelMatrix = glm::mat4(1.0f);
		Update();
	}
}
