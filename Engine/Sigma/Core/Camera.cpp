#include "Camera.h"

#include <GLM/gtc/matrix_transform.hpp>
#include <GLM/gtc/type_ptr.hpp>

#include <iostream>

namespace Sigma
{
	Camera::Camera()
	{}

	Camera::~Camera()
	{}

	void Camera::Init(unsigned int width, unsigned int height, float fov, float nClip, float fClip)
	{
		mWidth = width;
		mHeight = height;
		mFov = fov;
		mNClip = nClip;
		mFClip = fClip;

		mPosition = glm::vec3(0.0f, 0.0f, 1.0f);
		mRotation = glm::vec3(0.0f, 0.0f, -1.0f);

		mForward = glm::vec3(0.0f, 0.0f, -1.0f);
		mUp = glm::vec3(0.0f, 1.0f, 0.0f);
		mRight = glm::normalize(glm::cross(mForward, mUp));
	}

	void Camera::Resize(unsigned int width, unsigned int height)
	{
		mWidth = width;
		mHeight = height;
	}

	void Camera::Update()
	{
		mRight = glm::normalize(glm::cross(mForward, mUp));

		mView = glm::lookAt(mPosition, mPosition + mRotation, mUp);
		mProj = glm::perspective(glm::radians(mFov), (float)mWidth/mHeight, mNClip, mFClip);
	}

	void Camera::SendUniforms(const ShaderProgram& shader) const
	{
		shader.Activate();
		glUniform3f(glGetUniformLocation(shader.GetID(), "viewPos"), mPosition.x, mPosition.y, mPosition.z);
		glUniformMatrix4fv(glGetUniformLocation(shader.GetID(), "view"), 1, GL_FALSE, glm::value_ptr(mView));
		glUniformMatrix4fv(glGetUniformLocation(shader.GetID(), "proj"), 1, GL_FALSE, glm::value_ptr(mProj));
		shader.Deactivate();
	}
}
