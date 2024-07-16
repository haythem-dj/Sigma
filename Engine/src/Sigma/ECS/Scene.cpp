#include "sgpch.h"
#include "Scene.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Entity.h"

#include "../Renderer/Renderer.h"

namespace Sigma
{
	Scene::Scene()
	{}

	Scene::~Scene()
	{}

    Entity Scene::CreateEntity(const std::string& name)
    {
        Entity entity(mRegistry.create(), this);
        entity.AddComponent<TagComponent>();
        return entity;
    }

    void Scene::DestroyEntity(Entity entity)
    {
        mRegistry.destroy(entity.GetID());
    }

    void Scene::SetCamera(Entity* entity)
    {
        auto view = mRegistry.view<CameraComponent>();
        for (auto e : view)
        {
            if (entity->GetID() == e) continue;
            entity->RemoveComponent<CameraComponent>();
        }
        mActiveCamera = entity;
    }

    void Scene::Update(float dt)
    {
        for (auto [entity, script] : mRegistry.view<NativeScriptComponent>().each())
        {
            if (!script.instance)
            {
                script.instance = script.InstantiateScript();
                script.instance->mEntity = Entity(entity, this);
                script.instance->OnInit();
            }

            script.instance->OnUpdate(dt);
        }

        if (mActiveCamera && mActiveCamera->HasComponent<CameraComponent>() && mActiveShader)
        {
            mActiveCamera->GetComponent<CameraComponent>();
            auto view = mRegistry.view<TransformComponent, MeshComponent, MaterialComponent>();
            for (auto [entity, transform, mesh, material] : view.each())
            {
                Renderer::Render(mesh, transform, material, mActiveCamera->GetComponent<CameraComponent>(), *mActiveShader);
            };
        }
    }
}
