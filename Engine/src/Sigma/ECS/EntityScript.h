#pragma once

#include "Entity.h"

namespace Sigma
{
    class EntityScript
    {
    public:
        virtual ~EntityScript() = default;

        template<typename T>
        T& GetComponent()
        {
            return mEntity.GetComponent<T>();
        }

    protected:
        virtual void OnInit() {}
        virtual void OnUpdate(float dt) {}
        virtual void OnDestroy() {}

    private:
        Entity mEntity;
        friend class Scene;

    };
}
