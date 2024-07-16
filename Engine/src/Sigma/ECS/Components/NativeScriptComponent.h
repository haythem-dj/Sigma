#pragma once

#include "../EntityScript.h"

namespace Sigma
{
	struct NativeScriptComponent
    {
        EntityScript* instance = nullptr;

        EntityScript*(*InstantiateScript)();
        void (*DestroyScript)(NativeScriptComponent*);

        template<typename T>
        void Bind()
        {
            InstantiateScript = []() { return static_cast<EntityScript*>(new T()); };
            DestroyScript = [](NativeScriptComponent* script) { delete script->instance; script->instance = nullptr; };
        }
    };
}