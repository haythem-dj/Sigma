#include "sgpch.h"
#include "Entity.h"

namespace Sigma
{
    Entity::Entity(entt::entity entity_id, Scene* scene)
        :mEntityID(entity_id), mScene(scene)
    {
    }
}
