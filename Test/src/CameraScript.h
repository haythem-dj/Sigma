#pragma once

#include <iostream>

using namespace Sigma;

class CameraScript : public Sigma::EntityScript
{
public:
	void OnInit() override
	{
		
	}

	void OnUpdate(float dt) override
	{
		auto& camera = GetComponent<CameraComponent>();

		glm::vec3 right = glm::normalize(glm::cross(camera.Forward, camera.Up));
		if (Input::IsKeyPressed(SIGMA_KEY_W))
			camera.Position += camera.Forward * mSpeed * dt;
		else if (Input::IsKeyPressed(SIGMA_KEY_S))
			camera.Position -= camera.Forward * mSpeed * dt;
	}

	void OnDestroy() override
	{}

private:
	float mSpeed = 5.0f;
	float mSensitivity = 5.0f;

};