#pragma once

class CameraScript : public Sigma::EntityScript
{
public:
	void OnInit() override
	{
		auto& camera = GetComponent<Sigma::Camera>();
		camera.Position = { 0.0f, 0.0f, 1.0f };
	}

	void OnUpdate(float dt) override
	{
		auto& camera = GetComponent<Sigma::Camera>();

		glm::vec3 right = glm::normalize(glm::cross(camera.Forward, camera.Up));
		if (Sigma::Input::IsKeyPressed(SIGMA_KEY_W))
			camera.Position += camera.Up * mSpeed * dt;
		else if (Sigma::Input::IsKeyPressed(SIGMA_KEY_S))
			camera.Position -= camera.Up * mSpeed * dt;

		if (Sigma::Input::IsKeyPressed(SIGMA_KEY_D))
			camera.Position += right * mSpeed * dt;
		else if (Sigma::Input::IsKeyPressed(SIGMA_KEY_A))
			camera.Position -= right * mSpeed * dt;

		if (Sigma::Input::IsKeyPressed(SIGMA_KEY_E))
			camera.Position += camera.Forward * mSpeed * dt;
		else if (Sigma::Input::IsKeyPressed(SIGMA_KEY_Q))
			camera.Position -= camera.Forward * mSpeed * dt;
	}

	void OnDestroy() override
	{}

private:
	float mSpeed = 5.0f;
	float mSensitivity = 5.0f;

};