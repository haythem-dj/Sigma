#pragma once

class PlayerScript : public Sigma::EntityScript
{
public:
	PlayerScript() = default;

	void OnInit() override
	{
		auto& transform = GetComponent<Sigma::Transform>();
		transform.Position = {0.5f, 0.0f, 0.0f};
	}

	void OnUpdate(float dt) override
	{
		auto& transform = GetComponent<Sigma::Transform>();
		glm::vec2 direction = {0.0f, 0.0f};

		if (Sigma::Input::IsKeyPressed(SIGMA_KEY_UP))
			direction.y = 1.0f;
		else if (Sigma::Input::IsKeyPressed(SIGMA_KEY_DOWN))
			direction.y = -1.0f;
		else
			direction.y = 0.0f;

		if (Sigma::Input::IsKeyPressed(SIGMA_KEY_RIGHT))
			direction.x = 1.0f;
		else if (Sigma::Input::IsKeyPressed(SIGMA_KEY_LEFT))
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