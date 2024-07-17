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
        for (auto [entity, tag] : mRegistry.view<Tag>().each())
        {
            if (tag.Name == name)
            {
                SG_CORE_WARN("The name '{0}' is already taken by entity {1}", name, (size_t)entity);
                return Entity();
            }
        }
        Entity entity(mRegistry.create(), this);
        entity.AddComponent<Tag>(name);
        return entity;
    }

    void Scene::DestroyEntity(Entity entity)
    {
        mRegistry.destroy(entity.GetID());
    }

    Entity Scene::GetEntity(const std::string& name)
    {
        for (auto [entity, tag] : mRegistry.view<Tag>().each())
        {
            if (tag.Name == name) return Entity(entity, this);
        }
        return Entity();
    }

    void Scene::SetCamera(Entity* entity)
    {
        auto view = mRegistry.view<Camera>();
        for (auto e : view)
        {
            if (entity->GetID() == e) continue;
            entity->RemoveComponent<Camera>();
        }
        mActiveCamera = entity;
    }

    void Scene::Update(float dt)
    {
        for (auto [entity, script] : mRegistry.view<NativeScript>().each())
        {
            if (!script.instance)
            {
                script.instance = script.InstantiateScript();
                script.instance->mEntity = Entity(entity, this);
                script.instance->OnInit();
            }

            script.instance->OnUpdate(dt);
        }

        {
            mActiveShader->Activate();

            int dir = 0;
            for (auto [entity, light] : mRegistry.view<DirectionalLight>().each())
            {
                std::string name = "dir_lights[" + std::to_string(dir) + "].";
                glUniform3f(glGetUniformLocation(mActiveShader->GetID(), (name + "direction").c_str()),
                    light.Direction.x, light.Direction.y, light.Direction.z);

                glUniform3f(glGetUniformLocation(mActiveShader->GetID(), (name + "ambient").c_str()),
                    light.Ambient.x, light.Ambient.y, light.Ambient.z);
                glUniform3f(glGetUniformLocation(mActiveShader->GetID(), (name + "diffuse").c_str()),
                    light.Diffuse.x, light.Diffuse.y, light.Diffuse.z);
                glUniform3f(glGetUniformLocation(mActiveShader->GetID(), (name + "specular").c_str()),
                    light.Specular.x, light.Specular.y, light.Specular.z);

                dir++;
            }

            int point = 0;
            for (auto [entity, light, transform] : mRegistry.view<PointLight, Transform>().each())
            {
                std::string name = "point_lights[" + std::to_string(point) + "].";

                glUniform3f(glGetUniformLocation(mActiveShader->GetID(), (name + "position").c_str()),
                    transform.Position.x, transform.Position.y, transform.Position.z);

                glUniform1f(glGetUniformLocation(mActiveShader->GetID(), (name + "a").c_str()), light.a);
                glUniform1f(glGetUniformLocation(mActiveShader->GetID(), (name + "b").c_str()), light.b);
                glUniform1f(glGetUniformLocation(mActiveShader->GetID(), (name + "c").c_str()), light.c);

                glUniform3f(glGetUniformLocation(mActiveShader->GetID(), (name + "ambient").c_str()),
                    light.Ambient.x, light.Ambient.y, light.Ambient.z);
                glUniform3f(glGetUniformLocation(mActiveShader->GetID(), (name + "diffuse").c_str()),
                    light.Diffuse.x, light.Diffuse.y, light.Diffuse.z);
                glUniform3f(glGetUniformLocation(mActiveShader->GetID(), (name + "specular").c_str()),
                    light.Specular.x, light.Specular.y, light.Specular.z);

                point++;
            }

            int spot = 0;
            for (auto [entity, light, transform] : mRegistry.view<SpotLight, Transform>().each())
            {
                std::string name = "spot_lights[" + std::to_string(spot) + "].";

                glUniform3f(glGetUniformLocation(mActiveShader->GetID(), (name + "position").c_str()),
                    transform.Position.x, transform.Position.y, transform.Position.z);
                glUniform3f(glGetUniformLocation(mActiveShader->GetID(), (name + "direction").c_str()),
                    light.Direction.x, light.Direction.y, light.Direction.z);

                glUniform1f(glGetUniformLocation(mActiveShader->GetID(), (name + "cutOff").c_str()), light.CutOff);
                glUniform1f(glGetUniformLocation(mActiveShader->GetID(), (name + "outerCutOff").c_str()), light.OuterCutOff);

                glUniform1f(glGetUniformLocation(mActiveShader->GetID(), (name + "a").c_str()), light.a);
                glUniform1f(glGetUniformLocation(mActiveShader->GetID(), (name + "b").c_str()), light.b);
                glUniform1f(glGetUniformLocation(mActiveShader->GetID(), (name + "c").c_str()), light.c);

                glUniform3f(glGetUniformLocation(mActiveShader->GetID(), (name + "ambient").c_str()),
                    light.Ambient.x, light.Ambient.y, light.Ambient.z);
                glUniform3f(glGetUniformLocation(mActiveShader->GetID(), (name + "diffuse").c_str()),
                    light.Diffuse.x, light.Diffuse.y, light.Diffuse.z);
                glUniform3f(glGetUniformLocation(mActiveShader->GetID(), (name + "specular").c_str()),
                    light.Specular.x, light.Specular.y, light.Specular.z);

                spot++;
            }

            glUniform1i(glGetUniformLocation(mActiveShader->GetID(), "num_dir_light"), dir);
            glUniform1i(glGetUniformLocation(mActiveShader->GetID(), "num_point_light"), point);
            glUniform1i(glGetUniformLocation(mActiveShader->GetID(), "num_spot_light"), spot);


            mActiveShader->Deactivate();
        }

        if (mActiveCamera && mActiveCamera->HasComponent<Camera>() && mActiveShader)
        {
            mActiveCamera->GetComponent<Camera>();
            auto view = mRegistry.view<Transform, Mesh, Material>();
            for (auto [entity, transform, mesh, material] : view.each())
            {
                Renderer::Render(mesh, transform, material, mActiveCamera->GetComponent<Camera>(), *mActiveShader);
            };
        }
    }
}
