#pragma once

#include <iostream>

using namespace Sigma;

class PlayerScript : public Sigma::EntityScript
{
public:
	void OnInit() override
	{
		
	}

	void OnUpdate(float dt) override
	{
		auto& transform = GetComponent<TransformComponent>();
		glm::vec2 direction = {0.0f, 0.0f};

		if (Input::IsKeyPressed(SIGMA_KEY_UP))
			direction.y = 1.0f;
		else if (Input::IsKeyPressed(SIGMA_KEY_DOWN))
			direction.y = -1.0f;
		else
			direction.y = 0.0f;

		if (Input::IsKeyPressed(SIGMA_KEY_RIGHT))
			direction.x = 1.0f;
		else if (Input::IsKeyPressed(SIGMA_KEY_LEFT))
			direction.x = -1.0f;
		else
			direction.x = 0.0f;

		if (glm::length(direction) != 0) direction = glm::normalize(direction);

		transform.Position.x += direction.x * mSpeed * dt;
		transform.Position.y += direction.y * mSpeed * dt;
	}

	void OnDestroy() override
	{}

private:
	float mSpeed = 5.0f;

};