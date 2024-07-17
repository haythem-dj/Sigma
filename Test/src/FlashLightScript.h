#pragma once

using namespace Sigma;

class FlashLightScript : public Sigma::EntityScript
{
public:
	void OnInit() override
	{
		
	}

	void OnUpdate(float dt) override
	{
		auto camera = GetEntity("camera").GetComponent<Camera>();
		auto& camera_position = camera.Position;
		auto& camera_rotation = camera.Rotation;

		auto& transform = GetComponent<Transform>();
		auto& light = GetComponent<SpotLight>();

		transform.Position = camera_position;
		light.Direction = camera_rotation;
	}

	void OnDestroy() override
	{}

private:


};