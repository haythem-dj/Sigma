#pragma once

#include <string>

#include "Entity.h"

#include "../Core/Base.h"

namespace Sigma
{
    class SIGMA_API EntityScript
    {
    public:
        virtual ~EntityScript() = default;

        template<typename T>
        T& GetComponent()
        {
            return mEntity.GetComponent<T>();
        }

        Entity GetEntity(const std::string& name)
        {
            return mEntity.mScene->GetEntity(name);
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