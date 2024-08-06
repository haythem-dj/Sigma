#pragma once

#include "../../Core/Base.h"

#include "../EntityScript.h"

namespace Sigma
{
	struct SIGMA_API NativeScript
    {
        EntityScript* instance = nullptr;

        EntityScript*(*InstantiateScript)();
        void (*DestroyScript)(NativeScript*);

        template<typename T>
        void Bind()
        {
            InstantiateScript = []() { return static_cast<EntityScript*>(new T()); };
            DestroyScript = [](NativeScript* script) { delete script->instance; script->instance = nullptr; };
        }
    };
}