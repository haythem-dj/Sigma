#pragma once

#include <entt.hpp>
#include <glm/glm.hpp>

#include <utility>

#include "Scene.h"

namespace Sigma
{
    class Entity
    {
    public:
        Entity() = default;
        Entity(entt::entity id, Scene* scene);
        Entity(const Entity&) = default;

        template<typename T, typename... Args>
        T& AddComponent(Args&&... args)
        {
            SG_CORE_ASSERT(!HasComponent<T>(), "This component is already in this entity");
            T& component = mScene->mRegistry.emplace<T>(mEntityID, std::forward<Args>(args)...);
            return component;
        }

        template<typename T>
        T& GetComponent()
        {
            SG_CORE_ASSERT(HasComponent<T>(), "This Entity does not have this component");
            return mScene->mRegistry.get<T>(mEntityID);
        }

        template<typename T>
        bool HasComponent()
        {
            return mScene->mRegistry.all_of<T>(mEntityID);
        }

        template<typename T>
        void RemoveComponent()
        {
            mScene->mRegistry.remove<T>(mEntityID);
        }

        entt::entity GetID() const { return mEntityID; }
    
    private:
        entt::entity mEntityID = entt::null;
        Scene* mScene = nullptr;
        friend class EntityScript;

    };
}
