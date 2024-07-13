#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <GLM/glm.hpp>

#include "../Renderer/ShaderProgram.h"

namespace Sigma
{
	class Camera
	{
	public:
		Camera();
		~Camera();

		void Init(unsigned int width, unsigned int height, float fov, float nClip, float fClip);
		void Resize(unsigned int width, unsigned int height);
		void Update();

		void SendUniforms(const ShaderProgram& shader) const;

		void SetPosition(glm::vec3 Position) { mPosition = Position; }
		void SetRotation(glm::vec3 Rotation) { mRotation = Rotation; }

		void SetForward(glm::vec3 Forward) { mForward = Forward; }
		void SetUp(glm::vec3 Up) { mUp = Up; }

		const glm::vec3& GetPosition() const { return mPosition; }
		const glm::vec3& GetRotation() const { return mRotation; }

		const glm::vec3& GetForward() const { return mForward; }
		const glm::vec3& GetUp() const { return mUp; }
		const glm::vec3& GetRight() const { return mRight; }

		const glm::mat4& GetView() const { return mView; }
		const glm::mat4& GetProj() const { return mProj; }

	private:
		unsigned int mWidth = 0;
		unsigned int mHeight = 0;

		float mFov = 0.0f;
		float mNClip = 0.0f;
		float mFClip = 0.0f;

		glm::vec3 mPosition = glm::vec3(0.0f);
		glm::vec3 mRotation = glm::vec3(1.0f);

		glm::vec3 mForward = glm::vec3(1.0f);
		glm::vec3 mUp = glm::vec3(1.0f);
		glm::vec3 mRight = glm::vec3(1.0f);

		glm::mat4 mView = glm::mat4(1.0f);
		glm::mat4 mProj = glm::mat4(1.0f);

	};
}
